#include "TextField.h"

#include <in\core\scene\Scene.h>

namespace in { namespace core {

	TextField::TextField()
		: CanvasItem("Text Field"), m_Text(""), m_CursorLocation(0)
	{
	}

	TextField::TextField(const maths::vec2& size, const INString& text)
		: CanvasItem("Text Field", size), m_Text(text), m_CursorLocation(text.size())
	{
	}

	TextField::TextField(float width, float height, const INString& text)
		: CanvasItem("Text Field", maths::vec2(width, height)), m_Text(text), m_CursorLocation(text.size())
	{
		
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
		m_Label = new graphics::Label(m_Transform->position.xy(), m_Text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(m_Size);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::LEFT);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
		m_Rect = new graphics::Rectangle(m_Transform->position.xy(), m_Size, graphics::Color(0.6f, 0.6f, 0.6f));
	}

	void TextField::OnRender()
	{
		m_Label->SetBounds(m_Size);
		m_Label->SetText(m_Text);

		if (m_Selected)
			m_Rect->SetColor(graphics::Color(0.1f, 0.1f, 0.1f));
		else
			m_Rect->SetColor(graphics::Color(0.6f, 0.6f, 0.6f));

		m_Rect->SetSize(m_Size);

		m_Rect->SetPosition(m_Transform->position.xy());

		if (Scene::HasActiveScene())
		{
			Scene::GetActiveScene()->AddRenderable(m_Rect);
			Scene::GetActiveScene()->AddRenderable(m_Label);
		}
	}

} }