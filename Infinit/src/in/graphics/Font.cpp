#include "Font.h"

namespace in { namespace graphics {

	Font::Font(const INString& name, const INString& path, float size)
		: manager::Manageable(name), m_Size(size)
	{
		SetScale(32.0f, 18.0f);
		m_Atlas = ftgl::texture_atlas_new(1024, 1024, 2);
		m_Font = ftgl::texture_font_new_from_file(m_Atlas, size, path.c_str());
		if (!m_Font)
			IN_ERROR("Filed to load font ", name, " with path ", path, "!");
	}

	void Font::SetScale(float x, float y)
	{
		m_Scale.x = x;
		m_Scale.y = y;
	}

	const INUint Font::GetID() const
	{
		return m_Atlas->id;
	}

} }