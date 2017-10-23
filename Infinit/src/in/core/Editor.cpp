#include "Editor.h"

#include "scene\2d\CanvasItem.h"
#include <in\graphics\Font.h>
#include <GL\glew.h>
#include "scene\gui\Button.h"
#include "scene\gui\TextField.h"

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

		Object* object = new Object("Test Object");
		TextField* textField = object->AddNode<TextField>();
		textField->m_Size = maths::vec2(200.0f, 32.0f);

		scene->AddObject(object);

		//scene->AddNode(new CanvasItem("Canvas ITem", maths::vec2()));
		//scene->AddNode(new TextField("Text Field", 100.0f, 100.0f, 200.0f, 30.0f));

		scene->Start();
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