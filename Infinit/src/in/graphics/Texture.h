#pragma once

#include <in\manager\managable.h>

namespace in { namespace graphics {

	class Texture : public manager::Manageable
	{
	private:
		INUint m_ID;
		INUint m_Width;
		INUint m_Height;
		INUint m_BBP;
		INByte* m_Pixels;
	private:
		Texture(const INString& name, INByte* pixels, INUint width, INUint height, INUint bbp);
		Texture(const INString& name, const INString& path);
	public:
		~Texture();

		const INUint GetWidth() const { return m_Width; }
		const INUint GetHeight() const { return m_Height; }

		const INUint GetID() const { return m_ID; }

		void Bind();
		void Unbind();

		void Load();
	public:
		static Texture* FromFile(const INString& name, const INString& path);
	};

} }