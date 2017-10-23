#include "Object.h"

#include "Node.h"

namespace in { namespace core {

	Object::Object(const INString& name)
		: m_Name(name), m_Transform(), m_PrevTransform(m_Transform)
	{
	}

	Object::Object(const INString& name, const Transform& transform)
		: m_Name(name), m_Transform(transform), m_PrevTransform(m_Transform)
	{
	}


	Object::~Object()
	{
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				delete m_Nodes[i];
		m_Nodes.clear();
	}

	void Object::Start()
	{
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				m_Nodes[i]->Start_();

		for (INUint i = 0; i < m_Childs.size(); i++)
			if (m_Childs[i])
				m_Childs[i]->Start();
	}

	void Object::AddNode(Node* node)
	{
		node->m_Transform = &m_Transform;
		m_Nodes.push_back(node);
	}

	void Object::Update()
	{
		if (m_PrevTransform != m_Transform)
		{
			ReculculateModelMatrix();
		}

		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				m_Nodes[i]->Update_();

		for (INUint i = 0; i < m_Childs.size(); i++)
			if (m_Childs[i])
				m_Childs[i]->Update();
	}

	void Object::Render()
	{
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				m_Nodes[i]->Render_();

		for (INUint i = 0; i < m_Childs.size(); i++)
			if (m_Childs[i])
				m_Childs[i]->Render();
	}

	void Object::SetParent(Object* object)
	{
		SetParent_(object);
		object->AddChild_(this);
	}

	void Object::SetParent_(Object* object)
	{
		m_Parent = object;
	}

	void Object::AddChild(Object* object)
	{
		AddChild_(object);
		object->SetParent_(this);
	}

	void Object::AddChild_(Object* object)
	{
		m_Parent = object;
	}

	const maths::vec3& Object::GetWorldPosition()
	{
		if (m_Parent)
			return m_Parent->GetWorldPosition() + m_Transform.position;
		else
			return m_Transform.position;
	}

	const maths::vec3& Object::GetWorldRotation()
	{
		if (m_Parent)
			return m_Parent->GetWorldRotation() + m_Transform.rotation;
		else
			return m_Transform.rotation;
	}

	const maths::vec3& Object::GetWorldScale()
	{
		if (m_Parent)
			return m_Parent->GetWorldScale() + m_Transform.scale;
		else
			return m_Transform.scale;
	}

	void Object::ReculculateModelMatrix()
	{
		if (m_Parent)
			m_ModelMatrix = m_Parent->m_Transform.GetModelMatrix() * m_Transform.GetModelMatrix();
		else
			m_ModelMatrix = m_Transform.GetModelMatrix();
	}

	const maths::mat4& Object::GetModelMatrix() const
	{
		return m_ModelMatrix;
	}

} }