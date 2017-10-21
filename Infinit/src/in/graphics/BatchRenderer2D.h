#pragma once

#include "Renderer2D.h"
#include <in\maths\Maths.h>

namespace in { namespace graphics {

#define RENDERER_MAX_SPRITES	70000
#define RENDERER_VERTEX_SIZE	sizeof(Vertex)
#define RENDERER_SPRITE_SIZE	RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE	RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICES_SIZE	RENDERER_MAX_SPRITES * 6
#define RENDERER_MAX_TEXTURES	16

#define SHADER_VERTEX_INDEX	0
#define SHADER_UV_INDEX		1
#define SHADER_TID_INDEX	2
#define SHADER_COLOR_INDEX	3

	namespace buffers
	{
		struct Buffer;
		class VertexArray;
		class IndexBuffer;
	}

	class BatchRenderer2D : public Renderer2D
	{
	private:
		struct Vertex
		{
			maths::vec3 position;
			maths::vec2 uv;
			float tid;
			INUint color;
		};

		Vertex* m_Buffer;
		buffers::Buffer* m_VBO;
		buffers::IndexBuffer* m_IBO;
		buffers::VertexArray* m_VAO;

		INUint m_IndexCount;

		vector<INUint> m_TextureSlots;
	public:
		BatchRenderer2D();
		~BatchRenderer2D();

		void DrawRect(float x, float y, float width, float height, INUint color, float thickness = 0.02f) override;
		void DrawRect(float x, float y, float width, float height, const Color& color, float thickness = 0.02f) override;

		void DrawLine(float x1, float y1, float x2, float y2, INUint color, float thickness = 0.02f) override;
		void DrawLine(float x1, float y1, float x2, float y2, const Color& color, float thickness = 0.02f) override;

		void DrawString(const INString& string, float x, float y, Font* font, INUint color) override;
		void DrawString(const INString& string, float x, float y, Font* font, const Color& color) override;

		void DrawString(const INString& string, float x, float y, float width, float height, Font* font, INUint color,
			HORIZONTAL_TEXT_ALIGNMENT horizontalTextAlignment = LEFT, VERTICAL_TEXT_ALIGNMENT verticalTextAlignment = BOTTOM);
		void DrawString(const INString& string, float x, float y, float width, float height, Font* font, const Color& color,
			HORIZONTAL_TEXT_ALIGNMENT horizontalTextAlignment = LEFT, VERTICAL_TEXT_ALIGNMENT verticalTextAlignment = BOTTOM);

		void FillRect(float x, float y, float width, float height, INUint color) override;
		void FillRect(float x, float y, float width, float height, const Color& color) override;

		void DrawTexture(float x, float y, float width, float height, Texture* texture) override;

		void Begin() override;
		void End() override;
		void Flush() override;
	private:
		void Init();

		float SubmitTexture(Texture* texture);
		float SubmitTexture(INUint id);
	};

} }