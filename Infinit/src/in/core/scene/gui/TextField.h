#pragma once

#include <in\core\scene\2d\CanvasItem.h>

#include <in\graphics\renderable\Label.h>
#include <in\graphics\renderable\Rectangle.h>

namespace in { namespace core {

	class TextField : public CanvasItem
	{
		INCLASS(TextField, CanvasItem)

	private:
		graphics::Label* m_Label;
		graphics::Rectangle* m_Rect;

		INString m_Text;
		INUint m_CursorLocation;
	public:
		TextField();
		TextField(const maths::vec2& size, const INString& text = "");
		TextField(float width, float height, const INString& text = "");

		void OnStart() override;
		void OnUpdate() override;
		void OnRender() override;
	};

} }