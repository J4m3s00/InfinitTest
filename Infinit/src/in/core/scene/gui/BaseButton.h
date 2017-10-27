#pragma once

#include "../2d/CanvasItem.h"

#include <functional>

namespace in { 
	
	namespace graphics {
		class Rectangle;
	}

	namespace core {

		
		
	class BaseButton : public CanvasItem
	{

		INCLASS(BaseButton, CanvasItem)

		enum ButtonState
		{
			NORMAL,
			PRESSED,
			HOVERED
		};
	public:
		graphics::Color m_NormalColor = graphics::Color::CANVAS_ITEM_NORMAL;
		graphics::Color m_HoveredColor = graphics::Color::CANVAS_ITEM_HOVERED;
		graphics::Color m_PressedColor = graphics::Color::CANVAS_ITEM_PRESSED;
	public:
		BaseButton();
		BaseButton(const INString& name);

		void OnRenderStatic2D(graphics::Renderer2D& renderer) override;

		void SetHoveredColor(const graphics::Color& color) { m_HoveredColor = color; }
		void SetPressedColor(const graphics::Color& color) { m_PressedColor = color; }
		void SetNormalColor(const graphics::Color& color) { m_NormalColor = color; }
	};

} }