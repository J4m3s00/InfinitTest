#pragma once

#include <in\InfinitTypes.h>
#include <in\Preprocessor.h>

#include "Transform.h"

namespace in { 
	
	namespace graphics {
		class Renderer2D;
	}

	namespace core {

	class Node;

	class Object
	{
	protected:
		INString m_Name;
		vector<Object*> m_Childs;
		vector<Node*> m_Nodes;
		vector<Node*> m_Static2DNodes;
		Object* m_Parent;
	private:
		Transform* m_Transform;

		maths::mat4 m_ModelMatrix;
	public:
		Object(const INString& name);
		Object(const INString& name, Transform* transform);
		virtual ~Object();

		void SetParent(Object* object);
		void AddChild(Object* object);

		const maths::vec3& GetWorldPosition();
		const maths::vec3& GetWorldRotation();
		const maths::vec3& GetWorldScale();

		void AddNode(Node* node);

		template <typename T> 
		T* AddNode()
		{
			T* result = new T();
			AddNode(result);
			return result;
		}

		void Start();
		void Render();
		void Update();
		void RenderStatic2D(graphics::Renderer2D& renderer);

		const maths::mat4& GetModelMatrix() const;
	private:
		void ReculculateModelMatrix();
		void SetParent_(Object* object);
		void AddChild_(Object* object);

	};

} }