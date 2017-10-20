#pragma once

#include "Renderable.h"
#include <in\maths\Maths.h>

namespace in { namespace graphics {

	class Label : public Renderable
	{
	private:
		INString m_Text;
		Font* m_Font;
		maths::vec2 m_Position;
	public:
		Label(const maths::vec2& position, const INString& text, Font* font);
		virtual void Draw(Renderer2D& renderer);
	};

} }