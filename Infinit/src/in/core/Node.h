#pragma once

#include "Object.h"
#include "Transform.h"

#include <in\graphics\Renderer2D.h>

namespace in { namespace core {

	class Node
	{
		INCLASS_(Node)

		friend class Object;
	protected:
		bool m_Static2D = false;

		Transform* m_Transform;
		INString m_Name;
	protected:
		Node(const INString& name);
	public:
		~Node();

		Transform* GetTransform() { return m_Transform; }
		bool IsStatic2D() { return m_Static2D; }
	public:
		virtual void OnRenderStatic2D(graphics::Renderer2D& renderer);
		virtual void OnRender();
		virtual void OnStart();
		virtual void OnUpdate();
	};

} }