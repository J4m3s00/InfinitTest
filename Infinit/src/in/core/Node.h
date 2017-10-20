#pragma once

#include "Object.h"
#include "Transform.h"

namespace in { namespace core {

	class Node : public Object
	{
		INCLASS(Node, Object)

	private:
		bool m_UpdateModelMatrix;
		Transform m_PrevTransform;

		maths::mat4 m_ModelMatrix;
	protected:
		Transform m_Transform;
	public:
		Node(const INString& name);
		~Node();
	private:
	protected:
		void ReculculateModelMatrix();
		void OnRender() override;
		void OnStart() override;
		void OnUpdate() override;
	};

} }