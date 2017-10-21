#pragma once

#include <in\InfinitTypes.h>

namespace in { namespace graphics {

	class Color;
	class Texture;
	class Font;

	enum HORIZONTAL_TEXT_ALIGNMENT
	{
		LEFT,
		CENTER,
		RIGHT
	};

	enum VERTICAL_TEXT_ALIGNMENT
	{
		TOP,
		MIDDLE,
		BOTTOM
	};

	class Renderer2D
	{
	private:
		
	public:
		virtual void DrawRect(float x, float y, float width, float height, INUint color, float thickness = 0.02f) {}
		virtual void DrawRect(float x, float y, float width, float height, const Color& color, float thickness = 0.02f) {}

		virtual void DrawLine(float x1, float y1, float x2, float y2, INUint color, float thickness = 0.02f) {}
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color, float thickness = 0.02f) {}

		virtual void DrawString(const INString& string, float x, float y, Font* font, INUint color) {}
		virtual void DrawString(const INString& string, float x, float y, Font* font, const Color& color) {}

		virtual void DrawString(const INString& string, float x, float y, float width, float height, Font* font, INUint color, HORIZONTAL_TEXT_ALIGNMENT horizontalTextAlignment = LEFT, VERTICAL_TEXT_ALIGNMENT verticalTextAlignment = BOTTOM) {}
		virtual void DrawString(const INString& string, float x, float y, float width, float height, Font* font, const Color& color, HORIZONTAL_TEXT_ALIGNMENT horizontalTextAlignment = LEFT, VERTICAL_TEXT_ALIGNMENT verticalTextAlignment = BOTTOM) {}

		virtual void FillRect(float x, float y, float width, float height, INUint color) {}
		virtual void FillRect(float x, float y, float width, float height, const Color& color) {}

		virtual void DrawTexture(float x, float y, float width, float height, Texture* texture) {}

		virtual void Begin() = 0;
		virtual void End() = 0;
		virtual void Flush() = 0;
	};

} }