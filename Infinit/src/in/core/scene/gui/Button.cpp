#include "Button.h"

#include <in\core\scene\Scene.h>

#include <in\graphics\renderable\Label.h>

#include <in\manager\Manager.h>

namespace in { namespace core {

	Button::Button()
		: BaseButton("Button"), text("")
	{
		Init();
	}

	void Button::Init()
	{
		font = manager::FontManager::Get("DefaultFont");
		textColor = graphics::Color(0.0f, 0.0f, 0.0f);
	}

	void Button::OnRenderStatic2D(graphics::Renderer2D& renderer)
	{
		renderer.DrawString(text, m_Transform->position.x, m_Transform->position.y, m_Size->x, m_Size->y, font, textColor, graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER, graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
	}

} }