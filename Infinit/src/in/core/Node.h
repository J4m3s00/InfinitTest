#pragma once

#include "Object.h"
#include "Transform.h"

namespace in { namespace core {

	class Node
	{
		INCLASS_(Node)

			friend class Object;
	protected:
		Transform* m_Transform;
		INString m_Name;
	protected:
		Node(const INString& name);
	public:
		~Node();
	public:
		virtual void OnRender();
		virtual void OnStart();
		virtual void OnUpdate();
	};

} }