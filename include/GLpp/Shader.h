#pragma once

#include <string_view>

namespace glpp
{
	class Shader
	{
	public:
		enum shader_type
		{
			
			VERTEX_SHADER = GL_VERTEX_SHADER,
			FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
		};
	private:
		GLuint shader;

		shader_type type;
	public:
		Shader();
		Shader(shader_type type);
		~Shader();

		void Create();
		void Destroy();

		operator GLuint() const;

		auto SetShaderType(shader_type type)->void;
		auto LoadShader(std::string_view str)->bool;
		auto GetError() const->std::string;
	};
}
