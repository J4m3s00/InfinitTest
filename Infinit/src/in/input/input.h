#pragma once

#include <Infinit.h>
#include <in\maths\vec2.h>

#define INPUT_MAX_BUTTONS 16
#define INPUT_MAX_KEYS 512

namespace in {

	namespace graphics {
		class Window;
	}

	class Input
	{
	private:
		static graphics::Window* m_Window;

		static float m_MouseWheelAmmount;

		static INInt m_MouseX;
		static INInt m_MouseY;

		static bool m_KeysRepeated[INPUT_MAX_KEYS];
		static bool m_KeysPressed[INPUT_MAX_KEYS];
		static bool m_KeysReleased[INPUT_MAX_KEYS];

		static bool m_ButtonsRepeated[INPUT_MAX_BUTTONS];
		static bool m_ButtonsPressed[INPUT_MAX_BUTTONS];
		static bool m_ButtonsReleased[INPUT_MAX_BUTTONS];
	public:
		static void Update();

		static maths::vec2& GetMousePosition() { return maths::vec2((float) m_MouseX, (float) m_MouseY); }
		static INInt GetMouseX() { return m_MouseX; }
		static INInt GetMouseY() { return m_MouseY; }
		static float GetOrthographicsMouseX(float width);
		static float GetOrthographicsMouseY(float height);

		//Gettinfinitg the mouse and keyboard states
		static bool IsKeyPressed(INUint key);
		static bool IsKeyDown(INUint key);

		static bool IsMousePressed(INUint key);
		static bool IsMouseDown(INUint key);

		static float GetMouseWheel() { return m_MouseWheelAmmount; }

		static void SetMouseHidden(INUint cursorState);

		//Settinfinitg the buttons should not happen outside the enigne
		static void SetKeyPressed(INUint key, bool state) { m_KeysPressed[key] = state; }
		static void SetKeyDown(INUint key, bool state) { m_KeysRepeated[key] = state; }

		static void SetMousePressed(INUint key, bool state) { m_ButtonsPressed[key] = state; }
		static void SetMouseDown(INUint key, bool state) { m_ButtonsRepeated[key] = state; }

		static void SetMousePosition(double x, double y) { m_MouseX = (INInt) x; m_MouseY = (INInt) y; }
		static void SetWindow(graphics::Window* window) { m_Window = window; }

		static void SetMouseWheelAmmount(const float& ammt) { m_MouseWheelAmmount = ammt; }
	};

}