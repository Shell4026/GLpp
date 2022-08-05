#include "pch.h"
#include "Program.h"

#include "Shader.h"
namespace glpp
{
	Program::Program()
		:vert(nullptr), frag(nullptr)
	{
		program = glCreateProgram();
	}
	Program::Program(const Shader& vert, const Shader& frag)
		:
		vert(&vert),
		frag(&frag)
	{
		program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		glLinkProgram(program);
		glDetachShader(program, vert);
		glDetachShader(program, frag);
	}

	Program::~Program()
	{
		glDeleteProgram(program);
	}

	auto Program::SetNativeHandle(GLuint program) -> void
	{
		glDeleteProgram(this->program);
		this->program = program;
	}

	auto Program::SetVertexShader(const Shader& vert) -> void
	{
		this->vert = &vert;
	}

	auto Program::SetFragmentShader(const Shader& frag) -> void
	{
		this->frag = &frag;
	}

	auto Program::Link() -> bool
	{
		glAttachShader(program, *vert);
		glAttachShader(program, *frag);
		glLinkProgram(program);

		GLint result = GL_FALSE;
		glGetProgramiv(program, GL_LINK_STATUS, &result);

		glDetachShader(program, *vert);
		glDetachShader(program, *frag);
		return result;
	}

	auto Program::GetError() -> std::string
	{
		int InfoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> ErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(program, InfoLogLength, NULL, &ErrorMessage[0]);
			return std::string(ErrorMessage.begin(), ErrorMessage.end());
		}
		return "No error";
	}

	GLint Program::GetAttribute(const std::string& str)
	{
		return glGetAttribLocation(program, str.c_str());
	}

	bool Program::SetAttribute(Attribute attrib, float v)
	{
		if (attrib == -1)
			return false;
		glVertexAttrib1f(attrib, v);
		return true;
	}

	bool Program::SetAttribute(Attribute attrib, float *v)
	{
		if (attrib == -1)
			return false;
		glVertexAttrib1fv(attrib, v);
		return true;
	}

	bool Program::SetAttribute(Attribute attrib, float v1, float v2)
	{
		if (attrib == -1)
			return false;
		glVertexAttrib2f(attrib, v1, v2);
		return true;
	}

	bool Program::SetAttribute(Attribute attrib, float v1, float v2, float v3)
	{
		if (attrib == -1)
			return false;
		glVertexAttrib3f(attrib, v1, v2, v3);
		return true;
	}

	bool Program::SetAttribute(Attribute attrib, float v1, float v2, float v3, float v4)
	{
		if (attrib == -1)
			return false;
		glVertexAttrib4f(attrib, v1, v2, v3, v4);
		return true;
	}

	Uniform Program::GetUniform(const std::string& str) const
	{
		return glGetUniformLocation(program, str.c_str());
	}

	bool Program::SetUniform(Uniform u, int v)
	{
		if(u == -1)
			return false;
		glUniform1i(u, v);
		return true;
	}

	bool Program::SetUniform(Uniform u, float v)
	{
		if (u == -1)
			return false;
		glUniform1f(u, v);
		return true;
	}

	bool Program::SetUniform(Uniform u, float v1, float v2)
	{
		if (u == -1)
			return false;
		glUniform2f(u, v1, v2);
		return true;
	}

	bool Program::SetUniform(Uniform u, float v1, float v2, float v3)
	{
		if (u == -1)
			return false;
		glUniform3f(u, v1, v2, v3);
		return true;
	}

	bool Program::SetUniform(Uniform u, float v1, float v2, float v3, float v4)
	{
		if (u == -1)
			return false;
		glUniform4f(u, v1, v2, v3, v4);
		return true;
	}

	Program::operator GLuint() const
	{
		return program;
	}

	void Program::Bind()
	{
		glUseProgram(program);
	}
}
