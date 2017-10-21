#pragma once

#include <in\graphics\BatchRenderer2D.h>
#include <in\core\Node.h>
#include <functional>

namespace in { namespace core {

	typedef std::function<void()> PressedCallback;
	typedef std::function<void()> MouseEnterCallback;
	typedef std::function<void()> MouseLeaveCallback;
	typedef std::function<void(float deltaX, float deltaY)> DraggedCallback;


	class CanvasItem : public Node
	{

		INCLASS(CanvasItem, Node)

	protected:
		maths::vec2 m_Size;
		vector<PressedCallback> m_PressedCallbacks;
		vector<MouseEnterCallback> m_MouseEnterCallbacks;
		vector<MouseLeaveCallback> m_MouseLeaveCallbacks;
		vector<DraggedCallback> m_DraggedCallbacks;
		bool m_MouseOver;
		bool m_Pushed;
	private:
		float m_LastDraggedX;
		float m_LastDraggedY;
	public:
		CanvasItem(const INString& name, const maths::vec2& size);

		CanvasItem* AddPressedCallback(const PressedCallback& callback) { m_PressedCallbacks.push_back(callback); return this; }
		CanvasItem* AddMouseEnterCallback(const MouseEnterCallback& callback) { m_MouseEnterCallbacks.push_back(callback); return this; }
		CanvasItem* AddMouseLeaveCallback(const MouseLeaveCallback& callback) { m_MouseLeaveCallbacks.push_back(callback); return this; }
		CanvasItem* AddDraggedCallback(const DraggedCallback& callback) { m_DraggedCallbacks.push_back(callback); return this; }

		void OnUpdate() override;
	};

} }