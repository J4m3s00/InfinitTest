#include "CanvasItem.h"

#include <in\core\scene\Scene.h>
#include <in\manager\Manager.h>

#include <in\input\input.h>

#include <in\graphics\renderable\Rectangle.h>

namespace in { namespace core {

	CanvasItem::CanvasItem(const INString& name, const maths::vec2& size)
		: Node(name), m_Size(size)
	{
	}

	void CanvasItem::OnUpdate()
	{
		printf(Input::GetTypedText().c_str());
		int mouseX = Input::GetMouseX();
		int mouseY = Input::GetMouseY();

		if (mouseX > m_Transform.position.x && mouseX < m_Transform.position.x + m_Size.x)
		{
			if (mouseY > m_Transform.position.y && mouseY < m_Transform.position.y + m_Size.y)
			{
				if (!m_MouseOver)
				{
					for (INUint i = 0; i < m_MouseEnterCallbacks.size(); i++)
					{
						m_MouseEnterCallbacks[i]();
					}
				}
				m_MouseOver = true;
			}
			else
			{
				if (m_MouseOver)
				{
					for (INUint i = 0; i < m_MouseLeaveCallbacks.size(); i++)
					{
						m_MouseLeaveCallbacks[i]();
					}
				}
				m_MouseOver = false;
			}
		}
		else
		{
			if (m_MouseOver)
			{
				for (INUint i = 0; i < m_MouseLeaveCallbacks.size(); i++)
				{
					m_MouseLeaveCallbacks[i]();
				}
			}
			m_MouseOver = false;
		}
		if (m_MouseOver && Input::IsMousePressed(0))
		{
			m_Pushed = true;
			m_Selected = true;
			m_LastDraggedX = mouseX;
			m_LastDraggedY = mouseY;
		}
		else if (!m_MouseOver && Input::IsMousePressed(0))
			m_Selected = false;
		if (m_Pushed && m_MouseOver && !Input::IsMouseDown(0))
		{
			m_Pushed = false;
			for (INUint i = 0; i < m_PressedCallbacks.size(); i++)
			{
				m_PressedCallbacks[i]();
			}
		}

		if (m_Pushed && !m_MouseOver)
			m_Pushed = false;
		else if (m_Pushed && m_MouseOver)
		{
			for (INUint i = 0; i < m_DraggedCallbacks.size(); i++)
			{
				m_DraggedCallbacks[i](mouseX - m_LastDraggedX, mouseY - m_LastDraggedY);
			}
			m_LastDraggedX = mouseX;
			m_LastDraggedY = mouseY;
		}
	}

} }