#include "Rectangle.h"

namespace in { namespace graphics {

	Rectangle::Rectangle(float x, float y, float width, float height, const Color& color, DrawMode drawMode, float thickness)
		: m_Position(x, y), m_Size(width, height), m_Color(color), m_DrawMode(drawMode), m_Thickness(thickness)
	{

	}

	Rectangle::Rectangle(const maths::vec2& position, const maths::vec2& size, const Color& color, DrawMode drawMode, float thickness)
		: m_Position(position), m_Size(size), m_Color(color), m_DrawMode(drawMode), m_Thickness(thickness)
	{

	}

	Rectangle::Rectangle(float x, float y, float width, float height, Texture* texture)
		: m_Position(x, y), m_Size(width, height), m_Texture(texture), m_DrawMode(TEXTURED)
	{

	}

	Rectangle::Rectangle(const maths::vec2& position, const maths::vec2& size, Texture* texture)
		: m_Position(position), m_Size(size), m_Texture(texture), m_DrawMode(TEXTURED)
	{

	}

	void Rectangle::Draw(Renderer2D& renderer)
	{
		switch (m_DrawMode)
		{
		case FILL:
			renderer.FillRect(m_Position.x, m_Position.y, m_Size.x, m_Size.y, m_Color);
			break;
		case DRAW:
			renderer.DrawRect(m_Position.x, m_Position.y, m_Size.x, m_Size.y, m_Color);
			break;
		case TEXTURED:
			renderer.DrawTexture(m_Position.x, m_Position.y, m_Size.x, m_Size.y, m_Texture);
			break;
		}
	}

} }