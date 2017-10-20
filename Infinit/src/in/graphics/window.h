#pragma once

#include <Infinit.h>

struct GLFWwindow;

namespace in { namespace graphics {

	class Window
	{
	private:
		INString m_Title;
		INUint m_Width, m_Height;
		GLFWwindow* m_Window;
		static Window* instance;
	public:
		Window(const INString& name, INUint width, INUint height);
		~Window();

		INInt Closed();
		void Update();

		void UpdateInput();

		void Clear();

		static INUint GetWidth() { return instance ? instance->m_Width : 0; }
		static INUint GetHeight() { return instance ? instance->m_Height : 0; }

		GLFWwindow* GetGLFWWindow() { return m_Window; }
	private:
		bool Init();

		friend static void window_resize(GLFWwindow* window, int width, int height);
		friend static void key_callback(GLFWwindow* window, INInt key, INInt scancode, INInt action, INInt mods);
		friend static void mouse_button_callback(GLFWwindow* window, INInt button, INInt action, INInt mods);
		friend static void mouse_pos_callback(GLFWwindow* window, double xPos, double yPos);
		friend static void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
	};

} }