#pragma once

#include <in\InfinitTypes.h>
#include <in\maths\Maths.h>
#include <in\manager\managable.h>

namespace in { namespace graphics {

	class Shader : public manager::Manageable
	{
	private:
		INUint m_ID;
		INString m_Source;
		INString m_VertexSource;
		INString m_FragmentSource;
	private:
		enum ShaderType
		{
			NON,
			VERTEX,
			FRAGMENT
		};

		Shader(const INString& name, const INString& source);
	public:
		~Shader();

		void SetUniform1f(const INString& name, float value);
		void SetUniform1i(const INString& name, int value);
		void SetUniform2f(const INString& name, const maths::vec2& value);
		void SetUniform3f(const INString& name, const maths::vec3& value);
		void SetUniform4f(const INString& name, const maths::vec4& value);
		void SetUniformMat4(const INString& name, const maths::mat4& value);

		void Bind();
		void Unbind();
	private:
		INUint GetUniformLocation(const INString& name);

		INUint Load(const INString& vertexSource, const INString& fragmentSource);
		INUint CreateShader(const char* source, INUint type, const INString& shaderString = "Shader");

		void ProcessShader(const INString& source, INString** shaders);
	public:
		static void FromFile(const INString& name, const INString& path);
		static void FromSource(const INString& name, const INString& source);
	};

} }