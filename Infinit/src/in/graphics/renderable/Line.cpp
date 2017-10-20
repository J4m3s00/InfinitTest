#include "Line.h"

#include <in\graphics\Color.h>

namespace in { namespace graphics {

	Line::Line(float x0, float y0, float x1, float y1, const Color& color, float thickness)
		: m_Point1(x0, y0, 0.0f), m_Point2(x1, y1, 0.0f), m_Color(color), m_Thickness(thickness)
	{
		
	}

	Line::Line(const maths::vec2& point1, const maths::vec2& point2, const Color& color, float thickness)
		: m_Point1(point1.x, point1.y, 0.0f), m_Point2(point2.x, point2.y, 0.0f), m_Color(color), m_Thickness(thickness)
	{

	}

	Line::Line(float x0, float y0, float z0, float x1, float y1, float z1, const Color& color, float thickness)
		: m_Point1(x0, y0, z0), m_Point2(x1, y1, z1), m_Color(color), m_Thickness(thickness)
	{

	}

	Line::Line(const maths::vec3& point1, const maths::vec3& point2, const Color& color, float thickness)
		: m_Point1(point1), m_Point2(point2), m_Color(color), m_Thickness(thickness)
	{

	}

	void Line::Draw(Renderer2D& renderer)
	{
		renderer.DrawLine(m_Point1.x, m_Point1.y, m_Point2.x, m_Point2.y, m_Color, m_Thickness);
	}

} }