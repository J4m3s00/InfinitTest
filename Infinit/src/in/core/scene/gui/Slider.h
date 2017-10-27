#pragma once

#include "../2d/CanvasItem.h"
#include "MoveableItem.h"

namespace in { namespace core {

	class Slider;

	typedef std::function<void(Slider*, float)> ValueChangeCallback;

	class SliderPin : public MoveableItem
	{
		INCLASS(SliderPin, MoveableItem)
			friend class Slider;
	public:
		SliderPin();

		void OnRenderStatic2D(graphics::Renderer2D& renderer);
	};

	class Slider : public CanvasItem
	{
		INCLASS(Slider, CanvasItem)

	private:
		float m_Value;
		SliderPin m_SliderPin;
		std::vector<ValueChangeCallback> m_OnValueChangeCallback;
		graphics::Font* m_Font;
	public:
		float step;
		float minValue;
		float maxValue;
	public:
		Slider();
		Slider(float value);
		Slider(float value, float minValue, float maxValue, float step);

		void OnRenderStatic2D(graphics::Renderer2D& renderer) override;

		float GetValue() { return m_Value; }

		void OnUpdate() override;
		void OnStart() override;

		void AddOnValueChangeCallback(const ValueChangeCallback& callback) { m_OnValueChangeCallback.push_back(callback); }
	private:
		void Init();
	};

} }