#include "Shader.h"

#include <GL\glew.h>

namespace in { namespace graphics {

	Shader::Shader(const INString& name, const INString& source)
		: manager::Manageable(name)
	{
		m_Source = source;

		INString** shaders = new String*[2];
		shaders[0] = &m_VertexSource;
		shaders[1] = &m_FragmentSource;

		ProcessShader(m_Source, shaders);
		m_ID = Load(m_VertexSource, m_FragmentSource);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_ID);
	}

	void Shader::Bind()
	{
		glUseProgram(m_ID);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::FromFile(const INString& name, const INString& path)
	{
		INString source = utils::ReadFile(path);
		Shader* result = new Shader(name, source);
		manager::ShaderManager::Add(result);
	}

	void Shader::FromSource(const INString& name, const INString& source)
	{
		Shader* result = new Shader(name, source);
		manager::ShaderManager::Add(result);
	}

	INUint Shader::Load(const INString& vertSource, const INString& fragSource)
	{
		const char* vertexSource = vertSource.c_str();
		const char* fragmentSource = fragSource.c_str();

		INUint program = glCreateProgram();
		INUint vertex = CreateShader(vertexSource, GL_VERTEX_SHADER, "Vertex Shader");
		INUint fragment = CreateShader(fragmentSource, GL_FRAGMENT_SHADER, "Fragment Shader");

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	INUint Shader::CreateShader(const char* source, INUint type, const INString& shaderName)
	{
		INUint result = glCreateShader(type);

		glShaderSource(result, 1, &source, NULL);
		glCompileShader(result);

		INInt failure;
		glGetShaderiv(result, GL_COMPILE_STATUS, &failure);
		if (failure == GL_FALSE)
		{
			INInt length;
			glGetShaderiv(result, GL_INFO_LOG_LENGTH, &length);
			vector<char> error(length);
			glGetShaderInfoLog(result, length, &length, &error[0]);
			const char* errorChar = new char[length];
			errorChar = &error[0];
			IN_ERROR("Could not Compile ", shaderName, "\n", errorChar);
			return result;
		}
		return result;
	}

	void Shader::ProcessShader(const INString& source, INString** shaders)
	{
		ShaderType type = ShaderType::NON;

		vector<INString> lines = utils::SplitString(source, '\n');
		for (INUint i = 0; i < lines.size(); i++)
		{
			const char* str = lines[i].c_str();
			if (strstr(str, "#shader"))
			{
				if (strstr(str, "vertex"))
					type = ShaderType::VERTEX;
				else if (strstr(str, "fragment"))
					type = ShaderType::FRAGMENT;
			}
			else if (type != ShaderType::NON)
			{
				shaders[(int)type - 1]->append(str);
				shaders[(int)type - 1]->append("\n");
			}
		}
	}

	void Shader::SetUniform1f(const INString& name, float value)
	{
		glUniform1f(GetUniformLocation(name), value);
	}

	void Shader::SetUniform1i(const INString& name, int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

	void Shader::SetUniform2f(const INString& name, const maths::vec2& value)
	{
		glUniform2f(GetUniformLocation(name), value.x, value.y);
	}

	void Shader::SetUniform3f(const INString& name, const maths::vec3& value)
	{
		glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
	}

	void Shader::SetUniform4f(const INString& name, const maths::vec4& value)
	{
		glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
	}

	void Shader::SetUniformMat4(const INString& name, const maths::mat4& value)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value.elements);
	}

	INUint Shader::GetUniformLocation(const INString& name)
	{
		INUint result = glGetUniformLocation(m_ID, name.c_str());
		if (result == -1)
		{
			IN_WARNING("Could not find Uniform ", name, "!");
		}
		return result;
	}

} }