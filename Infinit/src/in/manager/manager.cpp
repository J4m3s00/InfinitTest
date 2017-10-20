#include "Manager.h"

#include <in\graphics\shader\Shader.h>
#include <in\graphics\Texture.h>

namespace in { namespace manager {

	INIT_MANAGER(ShaderManager, graphics::Shader)

	INIT_MANAGER(TextureManager, graphics::Texture)

	template <typename T>
	Manager<T>::Manager()
	{
		//static_assert(std::is_base_of<Manageable, T>::value, "T must be derived from Managable!");
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