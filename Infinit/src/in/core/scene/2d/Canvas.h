#pragma once

#include <in\core\Node.h>
#include <in\Preprocessor.h>

namespace in { namespace core {

	class Canvas : public Node
	{
		INCLASS(Canvas, Node)

	private:
		graphics::BatchRenderer2D m_Renderer;
	public:
		Canvas(const INString& name);

		void OnRender();

		graphics::BatchRenderer2D& GetBatchRenderer();
	};

} }