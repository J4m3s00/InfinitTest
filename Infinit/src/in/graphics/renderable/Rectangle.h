#pragma once

#include "Renderable.h"
#include <in\maths\Maths.h>

namespace in { namespace graphics {

	enum DrawMode {
		DRAW,
		FILL,
		TEXTURED
	};

	class Rectangle : public Renderable
	{
	private:
		maths::vec2 m_Position;
		maths::vec2 m_Size;
		Color m_Color;
		DrawMode m_DrawMode;
		Texture* m_Texture;
		float m_Thickness;
	public:
		Rectangle(float x, float y, float width, float height, const Color& color, DrawMode drawMode = FILL, float thickness = 0.02f);
		Rectangle(const maths::vec2& position, const maths::vec2& size, const Color& color, DrawMode drawMode = FILL, float thickness = 0.02f);
		Rectangle(float x, float y, float width, float height, Texture* texture);
		Rectangle(const maths::vec2& position, const maths::vec2& size, Texture* texture);

		void Draw(Renderer2D& renderer) override;
	};

} }