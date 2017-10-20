#include "input.h"

#include <in\graphics\window.h>
#include <iostream>

#include <in\utils\log.h>

#include <GLFW\glfw3.h>

namespace in { 
	
	bool Input::m_ButtonsPressed[INPUT_MAX_BUTTONS];
	bool Input::m_ButtonsRepeated[INPUT_MAX_BUTTONS];
	bool Input::m_ButtonsReleased[INPUT_MAX_BUTTONS];

	bool Input::m_KeysPressed[INPUT_MAX_KEYS];
	bool Input::m_KeysRepeated[INPUT_MAX_KEYS];
	bool Input::m_KeysReleased[INPUT_MAX_KEYS];

	INInt Input::m_MouseX = 0;
	INInt Input::m_MouseY = 0;
	float Input::m_MouseWheelAmmount = 0.0f;
	
	graphics::Window* Input::m_Window = NULL;
	
	void Input::Update()
	{
		
	}

	void Input::SetMouseHidden(INUint cursorState)
	{
		if (m_Window == NULL)
		{
			IN_WARNING("The window for the input is not set!");
			return;
		}

		glfwSetInputMode(m_Window->GetGLFWWindow(), GLFW_CURSOR, cursorState);
	}

	bool Input::IsKeyDown(INUint key)
	{
		if (key >= INPUT_MAX_KEYS) return false;

		return m_KeysRepeated[key];
	}

	bool Input::IsKeyPressed(INUint key)
	{
		if (key >= INPUT_MAX_KEYS) return false;

		return m_KeysPressed[key];
	}

	bool Input::IsMouseDown(INUint mouse)
	{
		if (mouse >= INPUT_MAX_BUTTONS) return false;

		return m_ButtonsRepeated[mouse];
	}

	bool Input::IsMousePressed(INUint mouse)
	{
		if (mouse >= INPUT_MAX_BUTTONS) return false;

		return m_ButtonsPressed[mouse];
	}


	float Input::GetOrthographicsMouseX(float width)
	{
		return (m_MouseX / (float) graphics::Window::GetWidth()) * (float) width - (width / 2.0f);
	}

	float Input::GetOrthographicsMouseY(float height)
	{
		return -((m_MouseY / (float) graphics::Window::GetHeight()) * (float) height - (height / 2.0f));
	}

}