#pragma once

#include <in\InfinitTypes.h>
#include <in\maths\Maths.h>

namespace ftgl
{
	struct texture_atlas_t;
	struct texture_font_t;
}

namespace in { 
	namespace manager
	{
		class Manageable;
	}
	
	namespace graphics {

	class Font : public manager::Manageable
	{
	private:
		ftgl::texture_atlas_t* m_Atlas;
		ftgl::texture_font_t* m_Font;

		maths::vec2 m_Scale;
		float m_Size;
	public:
		Font(const INString& name, const INString& path, float size);

		ftgl::texture_font_t* GetFont() { return m_Font; }
		const maths::vec2& GetScale() { return m_Scale; }
		float GetSize() { return m_Size; }

		void SetScale(float x, float y);
		const INUint GetID() const;

		float GetWidth(const INString& text) const;
		float GetHeight(const INString& text) const;
	};

} }