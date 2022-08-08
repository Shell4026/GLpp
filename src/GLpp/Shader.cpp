#include "OpenGL.h"
#include "Shader.h"

#include <vector>
#include <string>
namespace glpp
{
	Shader::Shader()
		:type(VERTEX_SHADER),
		shader(0)
	{
		shader = glCreateShader(type);
	}
	Shader::Shader(shader_type type)
		:shader(0),
		type(type)
	{
		shader = glCreateShader(type);
	}

	Shader::~Shader()
	{
		Destroy();
	}

	void Shader::Create()
	{
		Destroy();
		shader = glCreateShader(type);
	}

	void Shader::Destroy()
	{
		if (shader != 0)
		{
			glDeleteShader(shader);
			shader = 0;
		}
	}

	Shader::operator GLuint() const
	{
		return shader;
	}

	auto Shader::SetShaderType(shader_type type) -> void
	{
		this->type = type;
	}

	auto Shader::LoadShader(std::string_view str) -> bool
	{
		Destroy();
		if (shader == 0)
			Create();
		const char* data = str.data();
		glShaderSource(shader, 1, &data, NULL);
		glCompileShader(shader);

		GLint Result = GL_FALSE;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &Result);

		return Result;
	}
	auto Shader::GetError() const -> std::string
	{
		int InfoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> ShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(shader, InfoLogLength, NULL, &ShaderErrorMessage[0]);
			return std::string(ShaderErrorMessage.begin(), ShaderErrorMessage.end());
		}
		return "No Error";
	}
}