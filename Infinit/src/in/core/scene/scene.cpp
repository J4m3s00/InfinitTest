#include "Scene.h"

#include <in\graphics\shader\Shader.h>

namespace in { namespace core {

	Scene* Scene::activeScene = nullptr;

	Scene::Scene(const INString& name)
	{
		m_BatchShader = manager::ShaderManager::Get("BatchRenderer");
		m_BatchShader->Bind();
		m_BatchShader->SetUniformMat4("pr_matrix", maths::mat4::Orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		for (int i = 0; i < 16; i++)
			m_BatchShader->SetUniform1i("textures[" + std::to_string(i) + "]", i);
		m_BatchShader->Unbind();
	}

	Scene::~Scene()
	{
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				delete m_Nodes[i];
		m_Nodes.clear();
	}

	void Scene::AddNode(Node* node)
	{
		if (node)
			m_Nodes.push_back(node);
	}

	void Scene::AddRenderable(graphics::Renderable* renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void Scene::Render()
	{
		m_Renderables.clear();
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				m_Nodes[i]->Render();

		m_BatchShader->Bind();
		m_Renderer.Begin();
		for (INUint i = 0; i < m_Renderables.size(); i++)
			m_Renderables[i]->Draw(m_Renderer);
		m_Renderer.End();
		m_Renderer.Flush();
		m_BatchShader->Unbind();
	}

	void Scene::Update()
	{
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				m_Nodes[i]->Update();
	}

	void Scene::Start()
	{
		for (INUint i = 0; i < m_Nodes.size(); i++)
			if (m_Nodes[i])
				m_Nodes[i]->Start();
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