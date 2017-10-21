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
	public:
		TextField(const INString& name, const maths::vec3& position, const maths::vec2& size, const INString& text = "");
		TextField(const INString& name, const maths::vec2& position, const maths::vec2& size, const INString& text = "");
		TextField(const INString& name, float x, float y, float width, float height, const INString& text = "");

		void OnUpdate() override;
		void OnRender() override;
	};

} }