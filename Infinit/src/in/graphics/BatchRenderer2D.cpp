#include "BatchRenderer2D.h"

#include "Color.h"
#include <GL\glew.h>

#include "buffers\buffer.h"
#include "buffers\vertexarray.h"
#include "buffers\indexbuffer.h"

#include "Font.h"
#include <ext\freetype-gl\freetype-gl.h>

namespace in { namespace graphics {

	BatchRenderer2D::BatchRenderer2D()
		: m_IndexCount(0)
	{
		Init();
	}

	BatchRenderer2D::~BatchRenderer2D()
	{

	}

	void BatchRenderer2D::Init()
	{
		m_VAO = new buffers::VertexArray();
		m_VAO->Bind();

		m_VBO = new buffers::Buffer(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
		m_VBO->Bind();

		m_VBO->Resize(RENDERER_BUFFER_SIZE);

		m_VBO->layout.Push<maths::vec3>("POSITION");
		m_VBO->layout.Push<maths::vec2>("TEXCOORDS");
		m_VBO->layout.Push<float>("TEXTUREID");
		m_VBO->layout.Push<INByte>("COLOR", 4, true);

		m_VAO->PushBuffer(m_VBO);

		m_VBO->Unbind();

		INUint* indices = new INUint[RENDERER_INDICES_SIZE];

		INUint offset = 0;
		for (INUint i = 0; i < RENDERER_INDICES_SIZE; i += 6)
		{
			indices[  i  ] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;

			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		m_IBO = new buffers::IndexBuffer(indices, RENDERER_INDICES_SIZE);

		m_VAO->Unbind();
	}

	void BatchRenderer2D::Begin()
	{
		m_VBO->Bind();
		m_Buffer = m_VBO->GetPointer<Vertex>(GL_WRITE_ONLY);
	}

	void BatchRenderer2D::End()
	{
		m_VBO->ReleasePointer();
		m_VBO->Unbind();
	}

	void BatchRenderer2D::DrawLine(float x0, float y0, float x1, float y1, INUint color, float thickness)
	{
		maths::vec2 normal = maths::vec2(y1 - y0, -(x1 - x0)).Normalize() * thickness;

		m_Buffer->position = maths::vec3(x1 + normal.x, y1 + normal.y, 0.0f);
		m_Buffer->uv = maths::vec2();
		m_Buffer->tid = 0.0f;
		m_Buffer->color = color;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x0 + normal.x, y0 + normal.y, 0.0f);
		m_Buffer->uv = maths::vec2();
		m_Buffer->tid = 0.0f;
		m_Buffer->color = color;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x0 - normal.x, y0 - normal.y, 0.0f);
		m_Buffer->uv = maths::vec2();
		m_Buffer->tid = 0.0f;
		m_Buffer->color = color;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x1 - normal.x, y1 - normal.y, 0.0f);
		m_Buffer->uv = maths::vec2();
		m_Buffer->tid = 0.0f;
		m_Buffer->color = color;
		m_Buffer++;

		m_IndexCount += 6;
	}

	void BatchRenderer2D::DrawLine(float x0, float y0, float x1, float y1, const Color& color, float thickness)
	{
		DrawLine(x0, y0, x1, y1, color.GetColor<INUint>(), thickness);
	}

	void BatchRenderer2D::DrawRect(float x, float y, float width, float height, INUint color, float thickness)
	{
		DrawLine(x, y, x + width, y, color, thickness);
		DrawLine(x + width, y, x + width, y + height, color, thickness);
		DrawLine(x + width, y + height, x, y + height, color, thickness);
		DrawLine(x, y + height, x, y, color, thickness);
	}

	void BatchRenderer2D::DrawRect(float x, float y, float width, float height, const Color& color, float thickness)
	{
		DrawRect(x, y, width, height, color.GetColor<INUint>(), thickness);
	}

	void BatchRenderer2D::DrawString(const INString& text, float x, float y, Font* font, INUint color)
	{
		using namespace ftgl;

		float ts = SubmitTexture(font->GetID());
		const maths::vec2& scale = font->GetScale();

		texture_font_t* ftFont = font->GetFont();

		float posX = x;
		float posY = y;

		for (INUint i = 0; i < text.length(); i++)
		{
			char c = text[i];
			if (c == '\n')
			{
				posX = x;
				posY = posY - font->GetSize() / scale.y;
				continue;
			}
			texture_glyph_t* glyph = texture_font_get_glyph(ftFont, c);
			if (glyph != NULL)
			{
				if (i > 0)
				{
					float kerning = texture_glyph_get_kerning(glyph, text[i - 1]);
					posX += kerning / scale.x;
				}

				float x0 = posX + glyph->offset_x / scale.x;
				float y0 = posY - glyph->offset_y / scale.y;
				float x1 = x0 + glyph->width / scale.x;
				float y1 = y0 + glyph->height / scale.y;

				float u0 = glyph->s0;
				float v0 = glyph->t0;
				float u1 = glyph->s1;
				float v1 = glyph->t1;

				m_Buffer->position = maths::vec3(x0, y1, 0.0f);
				m_Buffer->uv = maths::vec2(u0, v1);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_Buffer->position = maths::vec3(x0, y0, 0.0f);
				m_Buffer->uv = maths::vec2(u0, v0);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_Buffer->position = maths::vec3(x1, y0, 0.0f);
				m_Buffer->uv = maths::vec2(u1, v0);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_Buffer->position = maths::vec3(x1, y1, 0.0f);
				m_Buffer->uv = maths::vec2(u1, v1);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_IndexCount += 6;

				posX += glyph->advance_x / scale.x;
			}
		}
	}

	void BatchRenderer2D::DrawString(const INString& text, float x, float y, Font* font, const Color& color)
	{
		DrawString(text, x, y, font, color.GetColor<INUint>());
	}

	void BatchRenderer2D::DrawString(const INString& text, float x, float y, float width, float height, Font* font, INUint color, HORIZONTAL_TEXT_ALIGNMENT horizontalTextAlignment, VERTICAL_TEXT_ALIGNMENT verticalTextAlignment)
	{
		using namespace ftgl;

		float ts = SubmitTexture(font->GetID());
		const maths::vec2& scale = font->GetScale();

		texture_font_t* ftFont = font->GetFont();

		float textWidth = font->GetWidth(text);
		float textHeight = font->GetHeight(text);

		float startX = 0;
		switch (horizontalTextAlignment)
		{
			case LEFT:
				startX = x;
				break;
			case CENTER:
				startX = x + ((width - textWidth) / 2);
				break;
			case RIGHT:
				startX = x + (width * textWidth);
				break;
		}
		float startY = 0;
		switch (verticalTextAlignment)
		{
		case TOP:
			startY = y + textHeight;
			break;
		case MIDDLE:
			startY = y + height / 2 + textHeight / 2;
			break;
		case BOTTOM:
			startY = y + height;
			break;
		}
		float posX = startX;
		float posY = startY;

		for (INUint i = 0; i < text.length(); i++)
		{
			char c = text[i];
			if (c == '\n')
			{
				posX = startX;
				posY = posY - font->GetSize() / scale.y;
				continue;
			}
			texture_glyph_t* glyph = texture_font_get_glyph(ftFont, c);
			if (glyph != NULL)
			{
				if (i > 0)
				{
					float kerning = texture_glyph_get_kerning(glyph, text[i - 1]);
					posX += kerning / scale.x;
				}

				float x0 = posX + glyph->offset_x / scale.x;
				float y0 = posY - glyph->offset_y / scale.y;
				float x1 = x0 + glyph->width / scale.x;
				float y1 = y0 + glyph->height / scale.y;

				float u0 = glyph->s0;
				float v0 = glyph->t0;
				float u1 = glyph->s1;
				float v1 = glyph->t1;

				m_Buffer->position = maths::vec3(x0, y1, 0.0f);
				m_Buffer->uv = maths::vec2(u0, v1);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_Buffer->position = maths::vec3(x0, y0, 0.0f);
				m_Buffer->uv = maths::vec2(u0, v0);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_Buffer->position = maths::vec3(x1, y0, 0.0f);
				m_Buffer->uv = maths::vec2(u1, v0);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_Buffer->position = maths::vec3(x1, y1, 0.0f);
				m_Buffer->uv = maths::vec2(u1, v1);
				m_Buffer->tid = ts;
				m_Buffer->color = color;
				m_Buffer++;

				m_IndexCount += 6;

				posX += glyph->advance_x / scale.x;
			}
		}
	}


	void BatchRenderer2D::DrawString(const INString& string, float x, float y, float width, float height, Font* font, const Color& color,
		HORIZONTAL_TEXT_ALIGNMENT horizontalTextAlignment, VERTICAL_TEXT_ALIGNMENT verticalTextAlignment)
	{
		DrawString(string, x, y, width, height, font, color.GetColor<INUint>(), horizontalTextAlignment, verticalTextAlignment);
	}

	void BatchRenderer2D::FillRect(float x, float y, float width, float height, INUint color)
	{
		m_Buffer->position = maths::vec3(x, y, 0.0f);
		m_Buffer->uv = maths::vec2(0.0f, 1.0f);
		m_Buffer->tid = -1;
		m_Buffer->color = color;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x, y + height, 0.0f);
		m_Buffer->uv = maths::vec2(0.0f, 0.0f);
		m_Buffer->tid = -1;
		m_Buffer->color = color;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x + width, y + height, 0.0f);
		m_Buffer->uv = maths::vec2(1.0f, 0.0f);
		m_Buffer->tid = -1;
		m_Buffer->color = color;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x + width, y, 0.0f);
		m_Buffer->uv = maths::vec2(1.0f, 1.0f);
		m_Buffer->tid = -1;
		m_Buffer->color = color;
		m_Buffer++;

		m_IndexCount += 6;
	}

	void BatchRenderer2D::FillRect(float x, float y, float width, float height, const Color& color)
	{
		FillRect(x, y, width, height, color.GetColor<INUint>());
	}

	void BatchRenderer2D::DrawTexture(float x, float y, float width, float height, Texture* texture)
	{
		float tid = SubmitTexture(texture);

		m_Buffer->position = maths::vec3(x, y, 0.0f);
		m_Buffer->uv = maths::vec2(0.0f, 0.0f);
		m_Buffer->tid = tid;
		m_Buffer->color = 0xffffffff;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x, y + height, 0.0f);
		m_Buffer->uv = maths::vec2(0.0f, 1.0f);
		m_Buffer->tid = tid;
		m_Buffer->color = 0xffffffff;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x + width, y + height, 0.0f);
		m_Buffer->uv = maths::vec2(1.0f, 1.0f);
		m_Buffer->tid = tid;
		m_Buffer->color = 0xffffffff;
		m_Buffer++;


		m_Buffer->position = maths::vec3(x + width, y, 0.0f);
		m_Buffer->uv = maths::vec2(1.0f, 0.0f);
		m_Buffer->tid = tid;
		m_Buffer->color = 0xffffffff;
		m_Buffer++;

		m_IndexCount += 6;
	}

	float BatchRenderer2D::SubmitTexture(INUint id)
	{
		float result = 0.0f;
		bool found = false;

		for (INUint i = 0; i < m_TextureSlots.size(); i++)
		{
			if (m_TextureSlots[i] == id)
			{
				result = (float)i + 1;
				found = true;
				break;
			}
		}

		if (!found)
		{
			if (m_TextureSlots.size() >= 32)
			{
				End();
				Flush();
				Begin();
				m_TextureSlots.push_back(id);
			}
			m_TextureSlots.push_back(id);
			result = (float)(m_TextureSlots.size());
		}
		return result;
	}

	float BatchRenderer2D::SubmitTexture(Texture* texture)
	{
		return SubmitTexture(texture->GetID());
	}

	void BatchRenderer2D::Flush()
	{
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		m_VAO->Bind();
		m_IBO->Bind();

		for (INUint i = 0; i < m_TextureSlots.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, m_TextureSlots[i]);
		}

		m_VAO->Draw(m_IndexCount);

		m_IBO->Unbind();
		m_VAO->Unbind();

		m_IndexCount = 0;
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
	}

} }