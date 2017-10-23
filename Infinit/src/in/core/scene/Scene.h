#pragma once

#include <in\InfinitTypes.h>

#include <in\graphics\BatchRenderer2D.h>
#include <in\graphics\renderable\Renderable.h>
#include "../Object.h"

namespace in { namespace core {

	class Scene
	{
	private:
		vector<Object*> m_Objects;
		vector<graphics::Renderable*> m_Renderables;
		static Scene* activeScene;

		INString m_Name;
		graphics::BatchRenderer2D m_Renderer;
		graphics::Shader* m_BatchShader;
	public:
		Scene(const INString& name);
		~Scene();

		void Render();
		void Update();
		void Start();

		const INString& GetName() const { return m_Name; }

		void AddObject(Object* node);

		void AddRenderable(graphics::Renderable* renderable);
	public:
		static Scene* GetActiveScene();
		static bool HasActiveScene();
		static void SetActiveScene(Scene* scene);
	};

} }