#include "Color.h"

namespace in { namespace graphics {

	const Color& Color::CANVAS_ITEM_HOVERED = Color(0.9f, 0.9f, 0.9f, 1.0f);
	const Color& Color::CANVAS_ITEM_NORMAL = Color(0.8f, 0.8f, 0.8f, 1.0f);
	const Color& Color::CANVAS_ITEM_PRESSED = Color(0.5f, 0.5f, 0.5f, 1.0f);

	Color::Color(INUint color)
	{
		m_Red = (color & 0xff000000) >> 24;
		m_Green = (color & 0x00ff0000) >> 16;
		m_Blue = (color & 0x0000ff00) >> 8;
		m_Alpha = (color & 0x000000ff);
	}

	Color::Color(INByte r, INByte g, INByte b, INByte a)
	{
		m_Red = r;
		m_Green = g;
		m_Blue = b;
		m_Alpha = a;
	}

	Color::Color(INByte r, INByte g, INByte b)
	{
		m_Red = r;
		m_Green = g;
		m_Blue = b;
		m_Alpha = 255;
	}

	Color::Color(float r, float g, float b, float a)
	{
		m_Red = (INByte)(r * 255);
		m_Green = (INByte)(g * 255);
		m_Blue = (INByte)(b * 255);
		m_Alpha = (INByte)(a * 255);
	}

	Color::Color(float r, float g, float b)
	{
		m_Red = (INByte)(r * 255);
		m_Green = (INByte)(g * 255);
		m_Blue = (INByte)(b * 255);
		m_Alpha = 255;
	}

} }