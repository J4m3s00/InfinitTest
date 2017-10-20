#pragma once

#include <in\InfinitTypes.h>
#include <in\maths\Maths.h>

namespace in { namespace graphics {

	class Color
	{
	private:
		INByte m_Red;
		INByte m_Green;
		INByte m_Blue;
		INByte m_Alpha;
	public:
		Color() {}
		Color(INUint color);
		Color(INByte r, INByte g, INByte b, INByte a);
		Color(INByte r, INByte g, INByte b);
		Color(float r, float g, float b, float a);
		Color(float r, float g, float b);

		template <typename T>
		const T& GetColor() const
		{
			IN_WARNING("Can't convert color to ", typeid(T).name, "!");
		}

		template <> const maths::vec3& GetColor() const { return maths::vec3(m_Red / 255.0f, m_Green / 255.0f, m_Blue / 255.0f); }
		template <> const maths::vec4& GetColor() const { return maths::vec4(m_Red / 255.0f, m_Green / 255.0f, m_Blue / 255.0f, m_Alpha / 255.0f); }
		template <> const INUint& GetColor() const { return INUint(m_Red << 24 | m_Green << 16 | m_Blue << 8 | m_Alpha); }
	};

} }