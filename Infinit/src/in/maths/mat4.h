#pragma once

#include <Infinit.h>

namespace in { namespace maths {

	struct mat4
	{
		union
		{
			float elements[4 * 4];
			vec4 columns[4];
		};

		mat4();
		mat4(float diagonal);

		vec4 getColumn(int index)
		{
			index *= 4;
			return vec4(elements[index], elements[index + 1], elements[index + 2], elements[index + 3]);
		}

		static mat4 Identity();

		mat4& Multiply(const mat4& other);
		static mat4& Multiply(const mat4& left, const mat4& right);
		friend mat4 operator*(mat4 left, const mat4& right);
		mat4& operator*=(const mat4& other);

		vec3 Multiply(const vec3& other) const;
		friend vec3 operator*(const mat4& left, const vec3& right);
		vec3 operator*=(const vec3& other);

		vec4 Multiply(const vec4& other) const;
		friend vec4 operator*(const mat4& left, const vec4& right);
		vec4 operator*=(const vec4& other);

		mat4& Invert();

		static mat4 Orthographic(float left, float right, float bottom, float top, float _near, float _far);
		static mat4 Perspective(float fov, float aspectRatio, float _near, float _far);

		static mat4 Translation(const vec3& translation);
		static mat4 Rotation(float angle, const vec3& rotation);
		static mat4 Scale(const vec3& scale);
		static mat4 Invert(const mat4& matrix);
	};

} }