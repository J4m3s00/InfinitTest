#include "Texture.h"

#include <in\utils\imageutils.h>
#include <GL\glew.h>

namespace in { namespace graphics {

	Texture::Texture(const INString& name, INByte* pixels, INUint width, INUint height, INUint bbp)
		: manager::Manageable(name), m_Width(width), m_Height(height), m_BBP(bbp)
	{
		m_Pixels = pixels;
		Load();
	}

	Texture::Texture(const INString& name, const INString& path)
		: manager::Manageable(name)
	{
		m_Pixels = utils::LoadTexture(path, &m_Width, &m_Height, &m_BBP);
		Load();
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_ID);
	}

	void Texture::Load()
	{
		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, m_BBP == 3 ? GL_RGB : GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Pixels);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_ID);
	}

	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	Texture* Texture::FromFile(const INString& name, const INString& path)
	{
		Texture* result = new Texture(name, path);
		manager::TextureManager::Add(result);
		return result;
	}

} }