#include "vec3.h"

#include "mat4.h"
#include <math.h>

namespace in { namespace maths {

	vec3::vec3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vec3::vec3(const float& value)
	{
		this->x = value;
		this->y = value;
		this->z = value;
	}

	vec3::vec3(const float& x, const float& y, const float& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3& vec3::Add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	vec3& vec3::Substract(const vec3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	vec3& vec3::Multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	vec3& vec3::Divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	float vec3::Lenght()
	{
		return (float) sqrt(x * x + y * y + z * z);
	}

	vec3& vec3::Normalize()
	{
		float lenght = Lenght();
		x = x / lenght;
		y = y / lenght;
		z = z / lenght;
		return *this;
	}

	float vec3::Dot(const vec3& other)
	{
		return x * other.x + y * other.y + z * other.z;
	}

	float vec3::Distance(const vec3& other)
	{
		float a = x - other.x;
		float b = y - other.y;
		float c = z - other.z;
		return (float) sqrt(a * a + b * b + c * c);
	}

	vec3& operator+(vec3 left, const float & right)
	{
		return *new vec3(left.x + right, left.y + right, left.z + right);
	}

	vec3& operator-(vec3 left, const float & right)
	{
		return *new vec3(left.x - right, left.y - right, left.z - right);
	}

	vec3& operator*(vec3 left, const float & right)
	{
		return *new vec3(left.x * right, left.y * right, left.z * right);
	}

	vec3& operator/(vec3 left, const float & right)
	{
		return *new vec3(left.x / right, left.y / right, left.z / right);
	}

	vec3& operator+(vec3 left, const vec3 & right)
	{
		return *new vec3(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	vec3& operator-(vec3 left, const vec3 & right)
	{
		return *new vec3(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	vec3& operator*(vec3 left, const vec3 & right)
	{
		return *new vec3(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	vec3& operator/(vec3 left, const vec3 & right)
	{
		return *new vec3(left.x / right.x, left.y / right.y, left.x / right.z);
	}

	vec3& vec3::operator+=(const vec3& other)
	{
		return Add(other);
	}

	vec3& vec3::operator-=(const vec3& other)
	{
		return Substract(other);
	}

	vec3& vec3::operator*=(const vec3& other)
	{
		return Multiply(other);
	}

	vec3& vec3::operator/=(const vec3& other)
	{
		return Divide(other);
	}

	vec3& operator*(vec3 left, const mat4&right)
	{
		return *new vec3(right * left);
	}

	vec3& vec3::operator*=(const mat4& other)
	{
		return *new vec3(other * *this);
	}

	vec3 operator-(const vec3& vector)
	{
		return *new vec3(-vector.x, -vector.y, -vector.z);
	}

	bool vec3::operator==(const vec3& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	bool vec3::operator!=(const vec3& other)
	{
		return !(*this == other);
	}

	vec3& vec3::CrossProduct(const vec3& other)
	{
		float a = y * other.z - z * other.y;
		float b = z * other.x - x * other.z;
		float c = x * other.y - y * other.x;
		return vec3(a, b, c);
	}

} }