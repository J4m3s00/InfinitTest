#pragma once

#include <in\InfinitTypes.h>
#include <in\Preprocessor.h>

namespace in { namespace core {


	class Object
	{

		INCLASS_(Object)

	protected:
		INString m_Name;
		vector<Object*> m_Childs;
		Object* m_Parent;
	protected:
		Object(const INString& name);
		virtual ~Object() = default;
	public:
		void SetParent(Object* object);
		void AddChild(Object* object);

		void Start();
		void Render();
		void Update();
	protected:
		virtual void OnStart() {}
		virtual void OnRender() {}
		virtual void OnUpdate() {}
	private:
		void SetParent_(Object* object);
		void AddChild_(Object* object);

	};

} }