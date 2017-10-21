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
		Button(const INString& name, const maths::vec3& position, const maths::vec2& size, const INString& text);
		Button(const INString& name, float x, float y, float width, float height, const INString& text);

		void OnRender() override;
	};

} }