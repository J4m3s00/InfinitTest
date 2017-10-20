#pragma once

#include "Renderable.h"
#include <in\maths\Maths.h>

namespace in { namespace graphics {

	class Color;

	class Line : public Renderable
	{
	private:
		maths::vec3 m_Point1;
		maths::vec3 m_Point2;
		Color m_Color;
		float m_Thickness;
	public:
		Line(float x0, float y0, float x1, float y1, const Color& color = Color(1.0f, 1.0f, 1.0f), float thickness = 0.02f);
		Line(const maths::vec2& point1, const maths::vec2& point2, const Color& color = Color(1.0f, 1.0f, 1.0f), float thickness = 0.02f);
		Line(float x0, float y0, float z0, float x1, float y1, float z1, const Color& color = Color(1.0f, 1.0f, 1.0f), float thickness = 0.02f);
		Line(const maths::vec3& point1, const maths::vec3& point3, const Color& color = Color(1.0f, 1.0f, 1.0f), float thickness = 0.02f);

		void Draw(Renderer2D& renderer) override;
	};

} }