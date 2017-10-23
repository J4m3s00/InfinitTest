#pragma once

namespace in { namespace maths {

	struct mat4;
	struct vec2;

	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(const float& value);
		vec3(const float& x, const float& y, const float& z);

		vec3& Add(const vec3& other);
		vec3& Substract(const vec3& other);
		vec3& Multiply(const vec3& other);
		vec3& Divide(const vec3& other);

		friend vec3& operator-(vec3 left, const vec3&right);
		friend vec3& operator+(vec3 left, const vec3&right);
		friend vec3& operator*(vec3 left, const vec3&right);
		friend vec3& operator/(vec3 left, const vec3&right);

		friend vec3& operator-(vec3 left, const float&right);
		friend vec3& operator+(vec3 left, const float&right);
		friend vec3& operator*(vec3 left, const float&right);
		friend vec3& operator/(vec3 left, const float&right);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);
		vec3& operator*=(const vec3& other);
		vec3& operator/=(const vec3& other);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		vec3& operator*=(const mat4& other);
		friend vec3& operator*(vec3 left, const mat4&right);

		friend vec3 operator-(const vec3& vector);

		vec2 xy() const;
		vec2 xz() const;
		vec2 yz() const;

		vec3& CrossProduct(const vec3& other);
		float Lenght();
		vec3& Normalize();
		float Dot(const vec3& other);
		float Distance(const vec3& other);
	};

} }