#pragma once

#include <string>

namespace glpp
{
	class VAO;
	class VBO;
	class Shader;

	typedef GLint Attribute;
	typedef GLint Uniform;

	class Program
	{
	private:
		GLuint program;


		const Shader* vert;
		const Shader* frag;
	public:
		Program();
		Program(const Shader& vert, const Shader& frag);
		~Program();

		void Create();
		void Destroy();

		auto SetNativeHandle(GLuint program)->void;

		auto SetVertexShader(const Shader& vert)->void;
		auto SetFragmentShader(const Shader& frag)->void;
		auto Link()->bool;
		auto GetError()->std::string;

		Attribute GetAttribute(const std::string &str);
		bool SetAttribute(Attribute, float v);
		bool SetAttribute(Attribute, float *v);
		bool SetAttribute(Attribute, float v1, float v2);
		bool SetAttribute(Attribute, float v1, float v2, float v3);
		bool SetAttribute(Attribute, float v1, float v2, float v3, float v4);

		Uniform GetUniform(const std::string &str) const;
		bool SetUniform(Uniform u, int v);
		bool SetUniform(Uniform u, float v);
		bool SetUniform(Uniform u, float v1, float v2);
		bool SetUniform(Uniform u, float v1, float v2, float v3);
		bool SetUniform(Uniform u, float v1, float v2, float v3, float v4);

		operator GLuint() const;

		void Bind();
	};
}