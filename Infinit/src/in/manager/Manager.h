#pragma once

#include <in\utils\log.h>

#include <map>

#include "managable.h"

namespace in {

#define MANAGER_CLASS(className, classType) class className {\
private: \
	static Manager<classType> m_Manager; \
public: \
	static void Add(classType* item) \
{ \
m_Manager.AddItem(item); \
} \
static classType* Get(const INString& name) \
{ \
return m_Manager.GetItem(name); \
} \
	};

#define INIT_MANAGER(className, classType) Manager<classType> className::m_Manager;

	namespace graphics {
		class Shader;
		class Texture;
		class Font;
	}

	namespace manager {

	template <typename T>
	class Manager
	{
	private:
		vector<T*> m_Handles;
	public:
		Manager();
		~Manager();

		void AddItem(T* item)
		{
			if (item)
				m_Handles.push_back(item);
		}

		T* GetItem(const INString& name)
		{
			for (INUint i = 0; i < m_Handles.size(); i++)
			{
				if (m_Handles[i]->GetName() == name)
				{
					return m_Handles[i];
				}
			}
			IN_WARNING("Could not find ", typeid(T).name(), " ", name);
			return nullptr;
		}

	};

	MANAGER_CLASS(ShaderManager, graphics::Shader)

	MANAGER_CLASS(TextureManager, graphics::Texture)

	MANAGER_CLASS(FontManager, graphics::Font)
		
} }