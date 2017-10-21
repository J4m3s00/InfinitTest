#include "Editor.h"

#include "scene\2d\CanvasItem.h"
#include <in\graphics\Font.h>
#include <GL\glew.h>
#include "scene\gui\Button.h"

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

		manager::FontManager::Add(new graphics::Font("DefaultFont", "font.ttf", 16));

		graphics::Shader::FromSource("BatchRenderer",
#include <in\graphics\shader\presets\BatchRenderer2D.shader>
			);

		Scene* scene = new Scene("First Scene");
		Scene::SetActiveScene(scene);

		//scene->AddNode(new CanvasItem("Canvas ITem", maths::vec2()));
		scene->AddNode((new Button("Button", 0.0f, 100.0f, 150.0f, 64.0f, "Hello World"))->AddPressedCallback([]() {
			printf("Hello World");
		}));
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
			m_Window->UpdateInput();

			Render();

			m_Window->Update();
			m_Running = !m_Window->Closed();
		}
	}

} }