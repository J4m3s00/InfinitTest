#pragma once

#include <in\maths\Maths.h>

namespace in { 

	namespace core {

	class Transform
	{
	public:
		const maths::vec3& position;
		const maths::vec3& rotation;
		const maths::vec3& scale;
	protected:
		maths::vec3 m_Position;
		maths::vec3 m_Rotation;
		maths::vec3 m_Scale;

		bool m_NeedUpdate;
	public:
		Transform();
		Transform(const Transform& other);
		Transform(const maths::vec3& position);
		Transform(const maths::vec3& position, const maths::vec3& scale);
		Transform(const maths::vec3& position, const maths::vec3& scale, const maths::vec3& rotation);
		Transform(const maths::vec3& position, float rotation);
		Transform(const float& x, const float& y, const float& z);
		Transform(const float& x, const float& y, const float& z, const float& zRotation);

		void SetPosition(const maths::vec3& position);
		void SetPosition(const float& x, const float& y, const float& z);
		void IncreasePosition(const maths::vec3& amount);
		void IncreasePosition(const float& xAmount, const float& yAmount, const float& zAmount);

		void SetScale(const maths::vec3& scale);
		void SetScale(const float& x, const float& y, const float& z);
		void SetScale(const float& scale);
		void IncreaseScale(const maths::vec3& amount);
		void IncreaseScale(const float& xAmount, const float& yAmount, const float& zAmount);
		void IncreaseScale(const float& amount);

		void SetRotation(const maths::vec3& rotation);
		void SetRotation(const float& x, const float& y, const float& z);
		void SetRotation(const float& zRotation);
		void IncreaseRotation(const maths::vec3& amount);
		void IncreaseRotation(const float& xAmount, const float& yAmount, const float& zAmount);
		void IncreaseRotation(const float& zAmount);

		bool operator==(const Transform& other);
		bool operator!=(const Transform& other);
	
		bool NeedUpdate() { return m_NeedUpdate; }

		const maths::mat4& GetModelMatrix() const;
	};

	class RectTransform : public Transform
	{
	public:
		const maths::vec2& size;
	private:
		maths::vec2 m_Size;
	public:
		RectTransform();
		RectTransform(float x, float y);
		RectTransform(const maths::vec2& position);
		RectTransform(const maths::vec3& position);
		RectTransform(const maths::vec2& position, const maths::vec2& size);
		RectTransform(float x, float y, float width, float height);
		RectTransform(const maths::vec3& position, const maths::vec2& size);
		RectTransform(float x, float y, float z, float width, float height);

		void SetPosition(float x, float y);
		void SetPosition(const maths::vec2& position);

		void SetSize(float x, float y);
		void SetSize(const maths::vec2& size);

		bool operator==(const RectTransform& other);
		bool operator!=(const RectTransform& other);
	};

} }