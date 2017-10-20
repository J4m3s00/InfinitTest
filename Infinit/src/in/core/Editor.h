#pragma once

#include "scene\Scene.h"

#include "scene\2d\CanvasItem.h"
#include <in\graphics\window.h>

namespace in { namespace core {

	class Editor
	{
	private:
		graphics::Window* m_Window;
		bool m_Running;
	public:
		Editor();
		~Editor();

		void Start();
	private:
		void Run();
		void Render();
		void Update();
	};

} }