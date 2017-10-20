#include "CanvasItem.h"

#include <in\core\scene\Scene.h>
#include <in\manager\Manager.h>

#include <in\graphics\renderable\Rectangle.h>

namespace in { namespace core {

	CanvasItem::CanvasItem(const INString& name, const maths::vec2& size)
		: Node(name)
	{
	}

} }