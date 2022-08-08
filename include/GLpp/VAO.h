#pragma once

namespace glpp {
	class VAO
	{
	private:
		GLuint vao;
	public:
		VAO();
		~VAO();
		VAO(const VAO& vao);
		VAO(VAO&& vao) noexcept;

		operator GLuint() const;
		void operator=(const VAO& vao);
		void operator=(VAO&& vao) noexcept;

		void Bind() const;
		void UnBind() const;

		void Create();
		void Destroy();
	};
}
