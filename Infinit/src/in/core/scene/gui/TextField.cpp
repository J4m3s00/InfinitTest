#include "TextField.h"

#include <in\core\scene\Scene.h>

namespace in { namespace core {

	TextField::TextField(const INString& name, const maths::vec3& position, const maths::vec2& size, const INString& text)
		: CanvasItem(name, size), m_Text(text)
	{
		m_Transform.SetPosition(position.x, position.y, position.z);
		m_Label = new graphics::Label(maths::vec2(position.x, position.y), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(size);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
		m_Rect = new graphics::Rectangle(maths::vec2(position.x, position.y), size, graphics::Color(0.6f, 0.6f, 0.6f));
	}

	TextField::TextField(const INString& name, const maths::vec2& position, const maths::vec2& size, const INString& text)
		: CanvasItem(name, size), m_Text(text)
	{
		m_Transform.SetPosition(position.x, position.y, 0.0f);
		m_Label = new graphics::Label(position, text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(size);
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
		m_Rect = new graphics::Rectangle(maths::vec2(position.x, position.y), size, graphics::Color(0.6f, 0.6f, 0.6f));
	}

	TextField::TextField(const INString& name, float x, float y, float width, float height, const INString& text)
		: CanvasItem(name, maths::vec2(width, height)), m_Text(text)
	{
		m_Transform.SetPosition(x, y, 0.0f);
		m_Label = new graphics::Label(maths::vec2(x, y), text, manager::FontManager::Get("DefaultFont"));
		m_Label->SetBounds(maths::vec2(width, height));
		m_Label->SetHorizontalTextAlignment(graphics::HORIZONTAL_TEXT_ALIGNMENT::CENTER);
		m_Label->SetVerticalTextAlignment(graphics::VERTICAL_TEXT_ALIGNMENT::MIDDLE);
		m_Rect = new graphics::Rectangle(maths::vec2(x, y), maths::vec2(width, height), graphics::Color(0.6f, 0.6f, 0.6f));
	}

	void TextField::OnUpdate()
	{
		if (m_Selected)
			m_Text.append(Input::GetTypedText());
	}

	void TextField::OnRender()
	{
		m_Label->SetText(m_Text);

		if (m_Selected)
			m_Rect->SetColor(graphics::Color(1.0f, 1.0f, 1.0f));
		else
			m_Rect->SetColor(graphics::Color(0.6f, 0.6f, 0.6f));

		if (Scene::HasActiveScene())
		{
			Scene::GetActiveScene()->AddRenderable(m_Rect);
			Scene::GetActiveScene()->AddRenderable(m_Label);
		}
	}

} }