#include "Font.h"

#include <in\manager\managable.h>

#include <ext\freetype-gl\freetype-gl.h>

namespace in { namespace graphics {

	Font::Font(const INString& name, const INString& path, float size)
		: manager::Manageable(name), m_Size(size)
	{
		SetScale(1.0f, 1.0f);
		m_Atlas = ftgl::texture_atlas_new(1024, 1024, 2);
		m_Font = ftgl::texture_font_new_from_file(m_Atlas, size, path.c_str());
		if (!m_Font)
			IN_ERROR("Filed to load font ", name, " with path ", path, "!");
	}

	void Font::SetScale(float x, float y)
	{
		m_Scale.x = x;
		m_Scale.y = y;
	}

	const INUint Font::GetID() const
	{
		return m_Atlas->id;
	}

	float Font::GetWidth(const INString& text) const
	{
		using namespace ftgl;

		float width = 0.0f;
		const maths::vec2& scale = m_Scale;
		for (INUint i = 0; i < text.size(); i++)
		{
			texture_glyph_t* glyph = texture_font_get_glyph(m_Font, text[i]);
			if (i > 0)
			{
				float kerning = texture_glyph_get_kerning(glyph, text[i - 1]);
				width += kerning / scale.x;
			}
			width += glyph->advance_x / scale.x;
		}
		return width;
	}

	float Font::GetHeight(const INString& text) const
	{
		using namespace ftgl;

		const maths::vec2& scale = m_Scale;
		float min = 0.0f;
		float max = 0.0f;
		for (INUint i = 0; i < text.size(); i++)
		{
			texture_glyph_t* glyph = texture_font_get_glyph(m_Font, text[i]);
			float height = glyph->height / scale.y;
			float offset = glyph->offset_y / scale.y - height;
			if (offset < min)
				min = offset;
			if (height > max)
				max = height;
		}
		return abs(min) + abs(max);
	}

} }