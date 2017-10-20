#pragma once

#include "../Renderer2D.h"

namespace in { namespace graphics {

	class Renderable
	{
	public:
		virtual void Draw(Renderer2D& renderer) {}
	};

} }