#include "window.h"

#include <in\utils\log.h>

#include <in\input\input.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace in { namespace graphics {

	Window* Window::instance = nullptr;

	Window::Window(const INString& title, INUint width, INUint height)
		: m_Title(title)
	{
		m_Width = width;
		m_Height = height;

		if (!Init())
			return;
		instance = this;
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			INFINIT_ASSERT(false, "Could not init glfw");
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			INFINIT_ASSERT(false, "Coudl not create window!");
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, mouse_pos_callback);
		glfwSetWindowSizeCallback(m_Window, window_resize);
		glfwSetScrollCallback(m_Window, scroll_callback);
		glfwSetCharModsCallback(m_Window, text_input);


		if (glewInit() != GLEW_OK)
		{
			INFINIT_ASSERT(false, "Could not infinititialize GLEW!");
			return false;
		}

		return true;
	}

	int Window::Closed()
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::UpdateInput()
	{
		for (int i = 0; i < INPUT_MAX_KEYS; i++)
		{
			Input::SetKeyPressed(i, false);
			Input::SetKeyTyped(i, false);
		}
		for (int i = 0; i < INPUT_MAX_BUTTONS; i++)
		{
			Input::SetMousePressed(i, false);
		}

		Input::SetMouseWheelAmmount(0.0f);
		Input::SetTypedText("");
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	//Callbacks
	void window_resize(GLFWwindow* window, int width, int height)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		glViewport(0, 0, width, height);
		win->m_Width = width;
		win->m_Height = height;
	}

	void key_callback(GLFWwindow* window, INInt key, INInt scancode, INInt action, INInt mods)
	{
		if (action == GLFW_RELEASE)
		{
			Input::SetKeyDown(key, false);
			Input::SetKeyPressed(key, false);
			Input::SetKeyTyped(key, false);
		}
		else if (action == GLFW_PRESS)
		{
			Input::SetKeyDown(key, true);
			Input::SetKeyPressed(key, true);
			Input::SetKeyTyped(key, true);
		}
		else if (action == GLFW_REPEAT)
		{
			Input::SetKeyDown(key, true);
			Input::SetKeyTyped(key, true);
		}
	}

	void scroll_callback(GLFWwindow* window, double xOffset, double yOffset)
	{
		Input::SetMouseWheelAmmount((float)yOffset);
	}

	void mouse_pos_callback(GLFWwindow* window, double xPos, double yPos)
	{
		Input::SetMousePosition(xPos, yPos);
	}

	void mouse_button_callback(GLFWwindow* window, INInt button, INInt action, INInt mods)
	{
		if (action == GLFW_RELEASE)
		{
			Input::SetMouseDown(button, false);
			Input::SetMousePressed(button, false);
		}
		else if (action == GLFW_PRESS || action == GLFW_REPEAT)
		{
			Input::SetMouseDown(button, true);
			Input::SetMousePressed(button, true);
		}
	}

	void text_input(GLFWwindow* window, INUint codepoint, int mods)
	{
		Input::AppendTypedText(static_cast<char>(codepoint));
	}

} }