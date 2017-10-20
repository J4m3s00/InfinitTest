#pragma once

#include <in\graphics\BatchRenderer2D.h>
#include <in\core\Node.h>

namespace in { namespace core {

	class CanvasItem : public Node
	{

		INCLASS(CanvasItem, Node)

	private:
		maths::vec2 m_Size;
	public:
		CanvasItem(const INString& name, const maths::vec2& size);
	};

} }