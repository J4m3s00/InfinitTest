#pragma once

#include "vec3.h"

namespace in { namespace maths {

	struct  vec2
	{
		float x, y;

		vec2();
		vec2(const float& value);
		vec2(const float& x, const float& y);
		
		vec2& Add(const vec2& other);
		vec2& Substract(const vec2& other);
		vec2& Multiply(const vec2& other);
		vec2& Divide(const vec2& other);

		friend vec2& operator-(vec2 left, const vec2&right);
		friend vec2& operator+(vec2 left, const vec2&right);
		friend vec2& operator*(vec2 left, const vec2&right);
		friend vec2& operator/(vec2 left, const vec2&right);

		friend vec2& operator-(vec2 left, const float&right);
		friend vec2& operator+(vec2 left, const float&right);
		friend vec2& operator*(vec2 left, const float&right);
		friend vec2& operator/(vec2 left, const float&right);

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);
		vec2& operator*=(const vec2& other);
		vec2& operator/=(const vec2& other);

		bool operator==(const vec2& other);
		bool operator!=(const vec2& other);

		friend vec2 operator-(const vec2& vector);

		float Lenght();
		vec2& Normalize();
		float Dot(const vec2& other);
		float Distance(const vec2& other);
	};

} }