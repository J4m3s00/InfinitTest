#pragma once

#include "../2d/CanvasItem.h"


namespace in { 
	
	namespace graphics {
		class Label;
	}

	namespace core {

	class BaseButton : public CanvasItem
	{
		enum ButtonState
		{
			NORMAL,
			PRESSED,
			HOVERED
		};
	private:
		graphics::Label* m_Label;
	public:
		BaseButton(const INString& name, const maths::vec3& position, const maths::vec2& size);
		BaseButton(const INString& name, float x, float y, float width, float height);
		
		void OnRender() override;
	};

} }