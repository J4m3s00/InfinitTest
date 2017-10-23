#include "Scene.h"

#include <GL\glew.h>
#include <in\graphics\shader\Shader.h>

namespace in { namespace core {

	Scene* Scene::activeScene = nullptr;

	Scene::Scene(const INString& name)
	{
		m_BatchShader = manager::ShaderManager::Get("BatchRenderer");
		m_BatchShader->Bind();
		m_BatchShader->SetUniformMat4("pr_matrix", maths::mat4::Orthographic(0.0f, graphics::Window::GetWidth(), graphics::Window::GetHeight(), 0.0f, -1.0f, 1.0f));
		for (int i = 0; i < 16; i++)
			m_BatchShader->SetUniform1i("textures[" + std::to_string(i) + "]", i);
		m_BatchShader->Unbind();
	}

	Scene::~Scene()
	{
		for (INUint i = 0; i < m_Objects.size(); i++)
			if (m_Objects[i])
				delete m_Objects[i];
		m_Objects.clear();
	}

	void Scene::AddObject(Object* object)
	{
		if (object)
			m_Objects.push_back(object);
	}

	void Scene::AddRenderable(graphics::Renderable* renderable)
	{
		if (renderable)
			m_Renderables.push_back(renderable);
		else
			IN_ERROR("Renderable is NULL");
	}

	void Scene::Render()
	{
		m_Renderables.clear();
		for (INUint i = 0; i < m_Objects.size(); i++)
			if (m_Objects[i])
				m_Objects[i]->Render();

		glDisable(GL_DEPTH_TEST);
		m_BatchShader->Bind();
		m_Renderer.Begin();
		for (INUint i = 0; i < m_Renderables.size(); i++)
			m_Renderables[i]->Draw(m_Renderer);
		m_Renderer.End();
		m_Renderer.Flush();
		m_BatchShader->Unbind();
		glEnable(GL_DEPTH_TEST);
	}

	void Scene::Update()
	{
		for (INUint i = 0; i < m_Objects.size(); i++)
			if (m_Objects[i])
				m_Objects[i]->Update();
	}

	void Scene::Start()
	{
		for (INUint i = 0; i < m_Objects.size(); i++)
			if (m_Objects[i])
				m_Objects[i]->Start();
	}

	Scene* Scene::GetActiveScene()
	{
		return activeScene;
	}

	void Scene::SetActiveScene(Scene* scene)
	{
		activeScene = scene;
	}

	bool Scene::HasActiveScene()
	{
		return (activeScene != nullptr);
	}

} }