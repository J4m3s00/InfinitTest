#include "Node.h"

#include "Transform.h"

namespace in { namespace core {

	Node::Node(const INString& name)
		: Object(name), m_Transform(), m_PrevTransform(m_Transform)
	{
		
	}

	Node::~Node()
	{

	}

	void Node::OnStart()
	{

	}

	void Node::OnRender()
	{

	}

	void Node::OnUpdate()
	{
		if (m_PrevTransform != m_Transform)
		{
			ReculculateModelMatrix();
		}
	}

	void Node::ReculculateModelMatrix()
	{
		if (m_Parent)
			m_ModelMatrix = ((Node*)m_Parent)->m_Transform.GetModelMatrix();
		else
			m_ModelMatrix = m_Transform.GetModelMatrix();
	}

} }