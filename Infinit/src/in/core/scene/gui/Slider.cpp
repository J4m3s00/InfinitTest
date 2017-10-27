#include "Slider.h"

#include <iostream>
#include <sstream>

namespace in { namespace core {

	Slider::Slider()
		: CanvasItem("Slider")
	{
		Init();
	}

	Slider::Slider(float value)
		: CanvasItem("Slider"), m_Value(value)
	{
		Init();
	}

	Slider::Slider(float value, float minValue, float maxValue, float step)
		: CanvasItem("Slider"), m_Value(value), minValue(minValue), maxValue(maxValue), step(step)
	{
		Init();
	}

	void Slider::Init()
	{
		step = 0.1f;
		minValue = 0.0f;
		maxValue = 1.0f;
		m_Font = manager::FontManager::Get("DefaultFont");
	}

	void Slider::OnStart()
	{
		m_SliderPin.m_Transform = new Transform(*m_Transform);
		m_SliderPin.m_Size = new maths::vec2(32.0f, 32.0f);
	}

	std::string ftos(float f) {
		using namespace std;
		ostringstream ostr;
		ostr << f;
		return ostr.str();
	}

	float round(float f, float step)
	{
		return floor(f * (1.0f / step) + 0.5) / (1.0f / step);
	}

	float map(float value, float curMin, float curMax, float min, float max)
	{
		return ((value - curMin) / (curMin - curMax)) * (min - max) + min;
	}

	void Slider::OnRenderStatic2D(graphics::Renderer2D& renderer)
	{
		renderer.FillRect(m_Transform->position.x, m_Transform->position.y, m_Size->x, m_Size->y, graphics::Color::CANVAS_ITEM_NORMAL);
		renderer.DrawString(ftos(m_Value), m_Transform->position.x + m_Size->x + 12, m_Transform->position.y, 0.0f, m_Size->y, m_Font, graphics::Color(1.0f, 1.0f, 1.0f), graphics::HORIZONTAL_TEXT_ALIGNMENT::LEFT, graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
		m_SliderPin.RenderStatic2D_(renderer);
	}

	void Slider::OnUpdate()
	{
		m_SliderPin.Update_();
		if (m_SliderPin.m_Transform->position.x <= m_Transform->position.x)
			m_SliderPin.m_Transform->SetPosition(m_Transform->position);
		else if (m_SliderPin.m_Transform->position.x + m_SliderPin.m_Size->x >= m_Transform->position.x + m_Size->x)
			m_SliderPin.m_Transform->SetPosition(m_Transform->position.x + m_Size->x - m_SliderPin.m_Size->x, m_Transform->position.y, m_Transform->position.z);

		float newValue = round(map((m_SliderPin.m_Transform->position.x - m_Transform->position.x) / (m_Size->x - m_SliderPin.m_Size->x), 0.0f, 1.0f, minValue, maxValue), step);
		if (newValue != m_Value)
		{
			m_Value = newValue;
			printf("%d\n", m_Value);
			for (ValueChangeCallback func : m_OnValueChangeCallback)
			{
				func(this, newValue);
			}
		}
	}

	SliderPin::SliderPin()
		: MoveableItem("Slider Pin", MOVE_LOCK::VERTICAL)
	{

	}

	void SliderPin::OnRenderStatic2D(graphics::Renderer2D& renderer)
	{
		renderer.FillRect(m_Transform->position.x, m_Transform->position.y, m_Size->x, m_Size->y, graphics::Color::CANVAS_ITEM_HOVERED);
	}

} }