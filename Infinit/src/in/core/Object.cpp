#include "Object.h"

namespace in { namespace core {

	Object::Object(const INString& name)
		: m_Name(name)
	{

	}

	void Object::Start()
	{
		Start_();
		for (INUint i = 0; i < m_Childs.size(); i++)
			if (m_Childs[i])
				m_Childs[i]->Start();
	}

	void Object::Update()
	{
		Update_();
		for (INUint i = 0; i < m_Childs.size(); i++)
			if (m_Childs[i])
				m_Childs[i]->Update();
	}

	void Object::Render()
	{
		Render_();
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

} }