#include "Node.h"

#include "Transform.h"

namespace in { namespace core {

	Node::Node(const INString& name)
		: m_Name(name), m_Transform()
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
		
	}

	void Node::OnRenderStatic2D(graphics::Renderer2D& renderer)
	{

	}

} }