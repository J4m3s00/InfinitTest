#include "Manager.h"

#include <in\graphics\shader\Shader.h>
#include <in\graphics\Texture.h>
#include <in\graphics\Font.h>

namespace in { namespace manager {

	INIT_MANAGER(ShaderManager, graphics::Shader)

	INIT_MANAGER(TextureManager, graphics::Texture)

	INIT_MANAGER(FontManager, graphics::Font)

	template <typename T>
	Manager<T>::Manager()
	{
		
	}

	template <typename T>
	Manager<T>::~Manager()
	{
		for (INUint i = 0; i < m_Handles.size(); i++)
			if (m_Handles[i])
				delete m_Handles[i];
		m_Handles.clear();
	}

} }