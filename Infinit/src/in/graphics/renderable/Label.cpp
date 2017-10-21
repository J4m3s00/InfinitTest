#include "Label.h"

namespace in { namespace graphics {

	Label::Label(const maths::vec2& position, const INString& text, Font* font)
		: m_Text(text), m_Font(font), m_Position(position), m_Bounds()
	{

	}

	void Label::Draw(Renderer2D& renderer)
	{
		if (m_Bounds.x != 0.0f && m_Bounds.y != 0.0f)
			renderer.DrawString(m_Text, m_Position.x, m_Position.y, m_Bounds.x, m_Bounds.y, m_Font, Color(1.0f, 1.0f, 1.0f, 1.0f), m_HorizontalTextAlignment, m_VerticalTextAlignment);
		else
			renderer.DrawString(m_Text, m_Position.x, m_Position.y, m_Font, Color(1.0f, 1.0f, 1.0f, 1.0f));
	}

	void Label::SetBounds(float width, float height)
	{
		m_Bounds.x = width;
		m_Bounds.y = height;
	}

	void Label::SetBounds(const maths::vec2& bounds)
	{
		m_Bounds = bounds;
	}

} }