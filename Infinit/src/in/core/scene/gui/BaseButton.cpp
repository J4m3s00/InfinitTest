#include "BaseButton.h"

#include <in\core\scene\Scene.h>
#include <in\graphics\renderable\Rectangle.h>
#include <in\graphics\Font.h>
#include <in\core\Transform.h>

namespace in { namespace core {

	BaseButton::BaseButton()
		: CanvasItem("BaseButton")
	{
	}

	BaseButton::BaseButton(const INString& name)
		: CanvasItem(name)
	{
	}

	void BaseButton::OnRenderStatic2D(graphics::Renderer2D& renderer)
	{
		renderer.FillRect(m_Transform->position.x, m_Transform->position.y, m_Size->x, m_Size->y, m_Pushed ? graphics::Color::CANVAS_ITEM_PRESSED : m_MouseOver ? graphics::Color::CANVAS_ITEM_HOVERED : graphics::Color::CANVAS_ITEM_NORMAL);
	}

} }