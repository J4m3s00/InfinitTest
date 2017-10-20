#pragma once

#include <in\InfinitTypes.h>
#include <in\maths\Maths.h>
#include <in\manager\managable.h>

#include <ext\freetype-gl\freetype-gl.h>

namespace in { namespace graphics {

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
	};

} }