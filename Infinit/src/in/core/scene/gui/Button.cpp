#include "Button.h"

#include <in\core\scene\Scene.h>

#include <in\graphics\renderable\Label.h>

#include <in\manager\Manager.h>

namespace in { namespace core {

	Button::Button()
		: BaseButton("Button"), text("")
	{
		m_Label = new graphics::Label(m_Transform->position.xy(), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

	Button::Button(const maths::vec2& size, const INString& text)
		: BaseButton("Button", size), text(text)
	{
		m_Label = new graphics::Label(m_Transform->position.xy(), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(size);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

	Button::Button(float width, float height, const INString& text)
		: BaseButton("Button", width, height), text(text)
	{
		m_Label = new graphics::Label(m_Transform->position.xy(), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(width, height);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

	void Button::OnRender()
	{
		if (Scene::HasActiveScene())
		{
			m_Label->SetText(text);

			m_Label->SetBounds(m_Size);

			Scene::GetActiveScene()->AddRenderable(m_Label);
		}
	}

} }