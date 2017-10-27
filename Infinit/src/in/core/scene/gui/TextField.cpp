#include "TextField.h"

#include <in\core\scene\Scene.h>

namespace in { namespace core {

	TextField::TextField()
		: CanvasItem("Text Field"), m_Text(""), m_CursorLocation(0)
	{
		Init();
	}

	void TextField::Init()
	{
		textColor = graphics::Color(0.0f, 0.0f, 0.0f);
		font = manager::FontManager::Get("DefaultFont");
	}

	void TextField::OnUpdate()
	{
		if (m_Selected)
		{
			m_Text.append(Input::GetTypedText());
			m_CursorLocation = m_Text.size();
			if (Input::IsKeyTyped(IN_KEY_BACKSPACE))
			{
				if (m_Text.size() > 0)
				{
					m_Text.erase(m_CursorLocation - 1, 1);
					m_CursorLocation = m_Text.size();
				}
			}
		}
	}

	void TextField::OnStart()
	{
		
	}

	void TextField::OnRenderStatic2D(graphics::Renderer2D& renderer)
	{
		const maths::vec2& pos = m_Transform->position.xy();
		graphics::HORIZONTAL_TEXT_ALIGNMENT align = graphics::HORIZONTAL_TEXT_ALIGNMENT::LEFT;
		renderer.FillRect(pos.x, pos.y, m_Size->x, m_Size->y, graphics::Color::CANVAS_ITEM_NORMAL);
		if (font->GetWidth(m_Text) > m_Size->x)
		{
			align = graphics::HORIZONTAL_TEXT_ALIGNMENT::RIGHT;
		}
		renderer.DrawString(m_Text, pos.x, pos.y, m_Size->x, m_Size->y, font, textColor, align, graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

} }