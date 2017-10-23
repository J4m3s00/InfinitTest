#include "BaseButton.h"

#include <in\core\scene\Scene.h>
#include <in\graphics\renderable\Rectangle.h>
#include <in\graphics\Font.h>
#include <in\core\Transform.h>

namespace in { namespace core {

	BaseButton::BaseButton()
		: CanvasItem("BaseButton")
	{
		m_Rect = new graphics::Rectangle(m_Transform->position.xy(), m_Size, graphics::Color(0.3f, 0.3f, 0.3f));
	}

	BaseButton::BaseButton(const INString& name)
		: CanvasItem(name)
	{
		m_Rect = new graphics::Rectangle(m_Transform->position.xy(), m_Size, graphics::Color(0.3f, 0.3f, 0.3f));
	}

	BaseButton::BaseButton(const INString& name, const maths::vec2& size)
		: CanvasItem(name, size)
	{
		m_Rect = new graphics::Rectangle(m_Transform->position.xy(), m_Size, graphics::Color(0.3f, 0.3f, 0.3f));
	}

	BaseButton::BaseButton(const INString& name, float width, float height)
		: CanvasItem(name, maths::vec2(width, height))
	{
		m_Rect = new graphics::Rectangle(m_Transform->position.xy(), m_Size, graphics::Color(0.3f, 0.3f, 0.3f));
	}

	void BaseButton::OnRender()
	{
		if (Scene::HasActiveScene())
		{
			m_Rect->SetPosition((maths::vec2&) m_Transform->position);
			m_Rect->SetColor(m_NormalColor);

			if (m_MouseOver)
				m_Rect->SetColor(m_HoveredColor);
			if (m_Pushed)
				m_Rect->SetColor(m_PressedColor);

			Scene::GetActiveScene()->AddRenderable(m_Rect);
		}
	}

} }