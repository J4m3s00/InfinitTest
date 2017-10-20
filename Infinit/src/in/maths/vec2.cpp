#include "vec2.h"

#include <math.h>

namespace in { namespace maths {

	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float& value)
	{
		this->x = value;
		this->y = value;
	}

	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}

	vec2& vec2::Add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::Substract(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	vec2& vec2::Multiply(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}

	vec2& vec2::Divide(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}

	float vec2::Lenght()
	{
		return (float) sqrt(x * x + y * y);
	}

	vec2& vec2::Normalize()
	{
		float lenght = Lenght();
		x = x / lenght;
		y = y / lenght;
		return *this;
	}

	float vec2::Dot(const vec2& other)
	{
		return x * other.x + y * other.y;
	}

	float vec2::Distance(const vec2& other)
	{
		float a = x - other.x;
		float b = y - other.y;
		return (float) sqrt(a * a + b * b);
	}

	vec2& operator+(vec2 left, const vec2 & right)
	{
		return *new vec2(left.x + right.x, left.y + right.y);
	}

	vec2& operator-(vec2 left, const vec2 & right)
	{
		return *new vec2(left.x - right.x, left.y - right.y);
	}

	vec2& operator*(vec2 left, const vec2 & right)
	{
		return *new vec2(left.x * right.x, left.y * right.y);
	}

	vec2& operator/(vec2 left, const vec2 & right)
	{
		return *new vec2(left.x / right.x, left.y / right.y);
	}

	vec2& operator+(vec2 left, const float & right)
	{
		return *new vec2(left.x + right, left.y + right);
	}

	vec2& operator-(vec2 left, const float & right)
	{
		return *new vec2(left.x - right, left.y - right);
	}

	vec2& operator*(vec2 left, const float & right)
	{
		return *new vec2(left.x * right, left.y * right);
	}

	vec2& operator/(vec2 left, const float & right)
	{
		return *new vec2(left.x / right, left.y / right);
	}

	vec2& vec2::operator+=(const vec2& other)
	{
		return Add(other);
	}

	vec2& vec2::operator-=(const vec2& other)
	{
		return Substract(other);
	}

	vec2& vec2::operator*=(const vec2& other)
	{
		return Multiply(other);
	}

	vec2& vec2::operator/=(const vec2& other)
	{
		return Divide(other);
	}

	vec2 operator-(const vec2& vector)
	{
		return *new vec2(-vector.x, -vector.y);
	}

	bool vec2::operator==(const vec2& other)
	{
		return x == other.x && y == other.y;
	}

	bool vec2::operator!=(const vec2& other)
	{
		return !(*this == other);
	}
	
} }