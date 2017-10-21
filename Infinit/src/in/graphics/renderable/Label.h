#pragma once

#include "Renderable.h"
#include <in\maths\Maths.h>

namespace in { namespace graphics {

	class Label : public Renderable
	{
	private:
		INString m_Text;
		Font* m_Font;
		HORIZONTAL_TEXT_ALIGNMENT m_HorizontalTextAlignment;
		VERTICAL_TEXT_ALIGNMENT m_VerticalTextAlignment;
		maths::vec2 m_Position;
		maths::vec2 m_Bounds;
	public:
		Label(const maths::vec2& position, const INString& text, Font* font);
		virtual void Draw(Renderer2D& renderer);

		void SetHorizontalTextAlignment(HORIZONTAL_TEXT_ALIGNMENT alignment) { m_HorizontalTextAlignment = alignment; }
		void SetVerticalTextAlignment(VERTICAL_TEXT_ALIGNMENT alignment) { m_VerticalTextAlignment = alignment; }

		void SetBounds(float width, float height);
		void SetBounds(const maths::vec2& bound);
	};

} }