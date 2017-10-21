#include "Button.h"

#include <in\core\scene\Scene.h>

#include <in\graphics\renderable\Label.h>

#include <in\manager\Manager.h>

namespace in { namespace core {

	Button::Button(const INString& name, const maths::vec3& position, const maths::vec2& size, const INString& text)
		: BaseButton(name, position, size)
	{
		m_Label = new graphics::Label(maths::vec2(position.x, position.y), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(size);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

	Button::Button(const INString& name, float x, float y, float width, float height, const INString& text)
		: BaseButton(name, x, y, width, height)
	{
		m_Label = new graphics::Label(maths::vec2(x, y), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(width, height);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

	void Button::OnRender()
	{
		if (Scene::HasActiveScene())
			Scene::GetActiveScene()->AddRenderable(m_Label);
	}

} }