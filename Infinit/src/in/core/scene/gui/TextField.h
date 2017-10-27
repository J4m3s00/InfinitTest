#pragma once

#include <in\core\scene\2d\CanvasItem.h>

#include <in\graphics\renderable\Label.h>
#include <in\graphics\renderable\Rectangle.h>

namespace in { namespace core {

	class TextField : public CanvasItem
	{
		INCLASS(TextField, CanvasItem)

	private:
		INString m_Text;
		INUint m_CursorLocation;
	public:
		graphics::Font* font;

		graphics::Color textColor;
	public:
		TextField();

		void OnStart() override;
		void OnUpdate() override;
		void OnRenderStatic2D(graphics::Renderer2D& renderer) override;
	private:
		void Init();
	};

} }