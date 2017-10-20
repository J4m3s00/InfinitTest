#include "Editor.h"

#include <GL\glew.h>
#include "scene\gui\BaseButton.h"

namespace in { namespace core {

	Editor::Editor()
	{
		
	}

	Editor::~Editor()
	{
		delete m_Window;
	}

	void Editor::Start()
	{
		m_Running = true;
		m_Window = new graphics::Window("Infinit Editor", 1270, 720);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		graphics::Shader::FromSource("BatchRenderer",
#include <in\graphics\shader\presets\BatchRenderer2D.shader>
			);

		Scene* scene = new Scene("First Scene");
		Scene::SetActiveScene(scene);

		scene->AddNode(new BaseButton("FIRST ITEM", maths::vec3(0.0f, 0.0f, 0.0f), maths::vec2()));
		Run();
	}

	void Editor::Update()
	{
		if (Scene::HasActiveScene())
			Scene::GetActiveScene()->Update();
	}

	void Editor::Render()
	{
		if (Scene::HasActiveScene())
			Scene::GetActiveScene()->Render();
	}

	void Editor::Run()
	{
		while (m_Running)
		{
			m_Window->Clear();

			Update();
			Render();

			m_Window->UpdateInput();
			m_Window->Update();
			m_Running = !m_Window->Closed();
		}
	}

} }