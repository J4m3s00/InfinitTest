#pragma once

namespace in { namespace maths {

	struct mat4;

	struct vec4
	{
		float x, y, z, w;

		vec4();
		vec4(const float& value);
		vec4(const float& x, const float& y, const float& z, const float& w);

		vec4& Add(const vec4& other);
		vec4& Substract(const vec4& other);
		vec4& Multiply(const vec4& other);
		vec4& Divide(const vec4& other);

		friend vec4& operator-(vec4 left, const vec4&right);
		friend vec4& operator+(vec4 left, const vec4&right);
		friend vec4& operator*(vec4 left, const vec4&right);
		friend vec4& operator/(vec4 left, const vec4&right);

		friend vec4& operator-(vec4 left, const float&right);
		friend vec4& operator+(vec4 left, const float&right);
		friend vec4& operator*(vec4 left, const float&right);
		friend vec4& operator/(vec4 left, const float&right);

		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);
		vec4& operator*=(const vec4& other);
		vec4& operator/=(const vec4& other);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		friend vec4 operator-(const vec4 vector);

		vec4& operator*=(const mat4& other);
		friend vec4& operator*(vec4 left, const mat4& right);

		float Length();
		vec4& Normalize();
		float Dot(const vec4& other);
		float Distance(const vec4& other);
	};

} }