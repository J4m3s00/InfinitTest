#include "BaseButton.h"

#include <in\core\scene\Scene.h>
#include <in\graphics\renderable\Label.h>
#include <in\graphics\Font.h>
#include <in\core\Transform.h>

namespace in { namespace core {

	BaseButton::BaseButton(const INString& name, const maths::vec3& position, const maths::vec2& size)
		: CanvasItem(name, size)
	{
		m_Transform.SetPosition(position.x, position.y, position.z);
		m_Label = new graphics::Label(maths::vec2(position.x, position.y), "Hello World", new graphics::Font("Hasojhfd", "font.ttf", 32));
	}

	BaseButton::BaseButton(const INString& name, float x, float y, float width, float height)
		: CanvasItem(name, maths::vec2(width, height))
	{
		m_Transform.SetPosition(maths::vec3(x, y, 0.0f));
	}

	void BaseButton::OnRender()
	{
		if (Scene::HasActiveScene())
			Scene::GetActiveScene()->AddRenderable(m_Label);
	}

} }