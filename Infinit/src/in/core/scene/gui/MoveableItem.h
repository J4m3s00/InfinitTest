#pragma once

#include <in\core\scene\2d\CanvasItem.h>

namespace in { namespace core {

	enum MOVE_LOCK
	{
		NON,
		HORIZONTAL,
		VERTICAL
	};

	class MoveableItem : public CanvasItem
	{
		INCLASS(MoveableItem, CanvasItem)

	private:
		MOVE_LOCK m_MoveLock;
	public:
		MoveableItem(const INString& name);
		MoveableItem(const INString& name, MOVE_LOCK moveLock);
	};

} }