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

	public:
		maths::vec2 m_Size;
	protected:
		vector<PressedCallback> m_PressedCallbacks;
		vector<MouseEnterCallback> m_MouseEnterCallbacks;
		vector<MouseLeaveCallback> m_MouseLeaveCallbacks;
		vector<DraggedCallback> m_DraggedCallbacks;
		bool m_MouseOver;
		bool m_Pushed;
		bool m_Selected;
	private:
		float m_LastDraggedX;
		float m_LastDraggedY;
	public:
		CanvasItem();
		CanvasItem(const INString& name);
		CanvasItem(const INString& name, const maths::vec2& size);

		CanvasItem* AddPressedCallback(const PressedCallback& callback) { m_PressedCallbacks.push_back(callback); return this; }
		CanvasItem* AddMouseEnterCallback(const MouseEnterCallback& callback) { m_MouseEnterCallbacks.push_back(callback); return this; }
		CanvasItem* AddMouseLeaveCallback(const MouseLeaveCallback& callback) { m_MouseLeaveCallbacks.push_back(callback); return this; }
		CanvasItem* AddDraggedCallback(const DraggedCallback& callback) { m_DraggedCallbacks.push_back(callback); return this; }

		void OnUpdate() override;
	};

} }