#include "MoveableItem.h"

namespace in { namespace core {

	MoveableItem::MoveableItem(const INString& name)
		: CanvasItem(name), m_MoveLock(NON)
	{
		AddDraggedCallback([](CanvasItem* item, float x, float y) {
			item->GetTransform()->IncreasePosition(x, y, 0.0f);
		});
	}

	MoveableItem::MoveableItem(const INString& name, MOVE_LOCK moveLock)
		: CanvasItem(name), m_MoveLock(moveLock)
	{
		AddPressedCallback([](CanvasItem*) {printf("Hello World"); });
		AddDraggedCallback([](CanvasItem* item, float x, float y) {
			switch (((MoveableItem*)item)->m_MoveLock)
			{
			case HORIZONTAL:
				item->GetTransform()->IncreasePosition(0.0f, y, 0.0f);
				break;
			case VERTICAL:
				item->GetTransform()->IncreasePosition(x, 0.0f, 0.0f);
				break;
			default:
				item->GetTransform()->IncreasePosition(x, y, 0.0f);
				break;
			}
			
		});
	}

} }