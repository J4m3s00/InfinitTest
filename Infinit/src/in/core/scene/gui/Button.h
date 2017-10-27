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

		graphics::Font* font;
		graphics::Color textColor;
	public:
		Button();

		void OnRenderStatic2D(graphics::Renderer2D& renderer) override;
	private:
		void Init();
	};

} }