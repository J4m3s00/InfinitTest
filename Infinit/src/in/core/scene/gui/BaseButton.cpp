#include "BaseButton.h"

#include <in\core\scene\Scene.h>
#include <in\graphics\renderable\Rectangle.h>
#include <in\graphics\Font.h>
#include <in\core\Transform.h>

namespace in { namespace core {

	BaseButton::BaseButton(const INString& name, const maths::vec3& position, const maths::vec2& size)
		: CanvasItem(name, size)
	{
		m_Transform.SetPosition(position.x, position.y, position.z);
		m_Rect = new graphics::Rectangle(maths::vec2(position.x, position.y), m_Size, graphics::Color(0.3f, 0.3f, 0.3f));
	}

	BaseButton::BaseButton(const INString& name, float x, float y, float width, float height)
		: CanvasItem(name, maths::vec2(width, height))
	{
		m_Transform.SetPosition(maths::vec3(x, y, 0.0f));
		m_Rect = new graphics::Rectangle(maths::vec2(x, y), m_Size, graphics::Color(0.3f, 0.3f, 0.3f));
	}

	void BaseButton::OnRender()
	{
		if (Scene::HasActiveScene())
		{
			m_Rect->SetColor(m_NormalColor);

			if (m_MouseOver)
				m_Rect->SetColor(m_HoveredColor);
			if (m_Pushed)
				m_Rect->SetColor(m_PressedColor);

			Scene::GetActiveScene()->AddRenderable(m_Rect);
		}
	}

} }