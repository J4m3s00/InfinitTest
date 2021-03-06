#include "Transform.h"

namespace in { namespace core {

	Transform::Transform()
		: m_Position(), m_Scale(1.0f), m_Rotation(), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	Transform::Transform(const Transform& other)
		: m_Position(other.m_Position), m_Scale(other.m_Scale), m_Rotation(other.m_Rotation), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{
	}

	Transform::Transform(const maths::vec3& position)
		: m_Position(position), m_Scale(1.0f), m_Rotation(), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	Transform::Transform(const maths::vec3& position, const maths::vec3& scale)
		: m_Position(position), m_Scale(scale), m_Rotation(), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	Transform::Transform(const maths::vec3& position, const maths::vec3& scale, const maths::vec3& rotation)
		: m_Position(position), m_Scale(scale), m_Rotation(rotation), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	Transform::Transform(const maths::vec3& position, float zRotation)
		: m_Position(position), m_Scale(1.0f), m_Rotation(0.0f, 0.0f, zRotation), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	Transform::Transform(const float& x, const float& y, const float& z)
		: m_Position(x, y, z), m_Scale(1.0f), m_Rotation(), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	Transform::Transform(const float& x, const float& y, const float& z, const float& zRotation)
		: m_Position(x, y, z), m_Scale(1.0f), m_Rotation(0.0f, 0.0f, zRotation), position(m_Position), scale(m_Scale), rotation(m_Rotation), m_NeedUpdate(false)
	{

	}

	void Transform::SetPosition(const maths::vec3& position)
	{
		m_Position = position;
		m_NeedUpdate = true;
	}

	void Transform::SetPosition(const float& x, const float& y, const float& z)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_Position.z = z;
		m_NeedUpdate = true;
	}

	void Transform::IncreasePosition(const maths::vec3& amount)
	{
		m_Position += amount;
		m_NeedUpdate = true;
	}

	void Transform::IncreasePosition(const float& xAmount, const float& yAmount, const float& zAmount)
	{
		m_Position.x += xAmount;
		m_Position.y += yAmount;
		m_Position.z += zAmount;
		m_NeedUpdate = true;
	}

	void Transform::SetScale(const maths::vec3& scale)
	{
		m_Scale = scale;
		m_NeedUpdate = true;
	}

	void Transform::SetScale(const float& x, const float& y, const float& z)
	{
		m_Scale.x = x;
		m_Scale.y = y;
		m_Scale.z = z;
		m_NeedUpdate = true;
	}

	void Transform::SetScale(const float& scale)
	{
		m_Scale.x = scale;
		m_Scale.y = scale;
		m_Scale.z = scale;
		m_NeedUpdate = true;
	}

	void Transform::IncreaseScale(const maths::vec3& amount)
	{
		m_Scale += amount;
		m_NeedUpdate = true;
	}

	void Transform::IncreaseScale(const float& xAmount, const float& yAmount, const float& zAmount)
	{
		m_Scale.x += xAmount;
		m_Scale.y += yAmount;
		m_Scale.z += zAmount;
		m_NeedUpdate = true;
	}

	void Transform::IncreaseScale(const float& amount)
	{
		m_Scale.x += amount;
		m_Scale.y += amount;
		m_Scale.z += amount;
		m_NeedUpdate = true;
	}

	void Transform::SetRotation(const maths::vec3& rotation)
	{
		m_Rotation = rotation;
		m_NeedUpdate = true;
	}

	void Transform::SetRotation(const float& x, const float& y, const float& z)
	{
		m_Rotation.x = x;
		m_Rotation.y = y;
		m_Rotation.z = z;
		m_NeedUpdate = true;
	}

	void Transform::SetRotation(const float& zRotation)
	{
		m_Rotation.z = zRotation;
		m_NeedUpdate = true;
	}

	void Transform::IncreaseRotation(const maths::vec3& amount)
	{
		m_Rotation += amount;
		m_NeedUpdate = true;
	}

	void Transform::IncreaseRotation(const float& xAmount, const float& yAmount, const float& zAmount)
	{
		m_Rotation.x += xAmount;
		m_Rotation.y += yAmount;
		m_Rotation.z += zAmount;
		m_NeedUpdate = true;
	}

	void Transform::IncreaseRotation(const float& zAmount)
	{
		m_Rotation.z += zAmount;
		m_NeedUpdate = true;
	}

	bool Transform::operator==(const Transform& other)
	{
		return m_Position == other.m_Position && m_Rotation == other.m_Rotation && m_Scale == other.m_Scale;
	}

	bool Transform::operator!=(const Transform& other)
	{
		return !((*this) == other);
	}

	const maths::mat4& Transform::GetModelMatrix() const
	{
		using namespace maths;
		mat4 result = mat4::Identity();
		result *= mat4::Scale(m_Scale);
		result *=	mat4::Rotation(m_Rotation.x, vec3(1.0f, 0.0f, 0.0f)) * 
					mat4::Rotation(m_Rotation.y, vec3(0.0f, 1.0f, 0.0f)) * 
					mat4::Rotation(m_Rotation.y, vec3(0.0f, 0.0f, 1.0f));
		result *= mat4::Translation(m_Position);
		return result;
	}

	RectTransform::RectTransform()
		: Transform(), m_Size(), size(m_Size)
	{

	}

	RectTransform::RectTransform(float x, float y)
		: Transform(x, y, 0.0f), m_Size(), size(m_Size)
	{

	}

	RectTransform::RectTransform(float x, float y, float width, float height)
		: Transform(x, y, 0.0f), m_Size(width, height), size(m_Size)
	{

	}

	RectTransform::RectTransform(const maths::vec2& position, const maths::vec2& size)
		: Transform(position.x, position.y, 0.0f), m_Size(size), size(m_Size)
	{

	}

	RectTransform::RectTransform(float x, float y, float z, float width, float height)
		: Transform(x, y, z), m_Size(width, height), size(m_Size)
	{

	}

	RectTransform::RectTransform(const maths::vec3& position, const maths::vec2& size)
		: Transform(position), m_Size(size), size(m_Size)
	{

	}

	RectTransform::RectTransform(const maths::vec2& position)
		: Transform(position.x, position.y), m_Size(), size(m_Size)
	{

	}

	RectTransform::RectTransform(const maths::vec3& position)
		: Transform(position), m_Size(), size(m_Size)
	{

	}

	void RectTransform::SetSize(float width, float height)
	{
		m_Size.x = width;
		m_Size.y = height;
		m_NeedUpdate = true;
	}

	void RectTransform::SetSize(const maths::vec2& size)
	{
		m_Size = size;
		m_NeedUpdate = true;
	}

	void RectTransform::SetPosition(float x, float y)
	{
		m_Position.x = x;
		m_Position.y = y;
		m_NeedUpdate = true;
	}

	void RectTransform::SetPosition(const maths::vec2& position)
	{
		m_Position.x = position.x;
		m_Position.y = position.y;
		m_NeedUpdate = true;
	}

	bool RectTransform::operator==(const RectTransform& other)
	{
		return m_Position == other.m_Position && m_Scale == other.m_Scale && m_Rotation == other.m_Rotation && m_Size == other.m_Size;
	}

	bool RectTransform::operator!=(const RectTransform& other)
	{
		return !(*this == other);
	}

} }