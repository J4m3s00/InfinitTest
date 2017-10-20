#include "Label.h"

namespace in { namespace graphics {

	Label::Label(const maths::vec2& position, const INString& text, Font* font)
		: m_Text(text), m_Font(font), m_Position(position)
	{

	}

	void Label::Draw(Renderer2D& renderer)
	{
		renderer.DrawString(m_Text, m_Position.x, m_Position.y, m_Font, Color(1.0f, 1.0f, 1.0f, 1.0f));
	}

} }