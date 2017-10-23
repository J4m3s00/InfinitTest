#pragma once

#include <in\InfinitTypes.h>
#include "BaseButton.h"

namespace in { 
	
	namespace graphics {
		class Label;
	}

	namespace core {

	class Button : public BaseButton
	{
		INCLASS(Button, BaseButton)

	private:
		graphics::Label* m_Label;
	public:
		INString text;
	public:
		Button();
		Button(const maths::vec2& size, const INString& text);
		Button(float width, float height, const INString& text);

		void OnRender() override;
	};

} }