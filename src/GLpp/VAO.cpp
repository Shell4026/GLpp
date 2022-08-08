#include "OpenGL.h"
#include "VAO.h"

namespace glpp{
	VAO::VAO()
	{
		glGenVertexArrays(1, &vao);
	}

	VAO::~VAO()
	{
		Destroy();
	}

	VAO::VAO(const VAO& vao)
	{
		this->vao = vao.vao;
	}

	VAO::VAO(VAO&& vao) noexcept
	{
		this->vao = vao.vao;
		vao.vao = 0;
	}

	VAO::operator GLuint() const
	{
		return vao;
	}

	void VAO::operator=(const VAO& vao)
	{
		glDeleteVertexArrays(1, &this->vao);
		this->vao = vao.vao;
	}

	void VAO::operator=(VAO&& vao) noexcept
	{
		glDeleteVertexArrays(1, &this->vao);
		this->vao = vao.vao;
		vao.vao = 0;
	}

	void VAO::Bind() const
	{
		glBindVertexArray(vao);
	}
	void VAO::UnBind() const
	{
		glBindVertexArray(0);
	}
	void VAO::Create()
	{
		Destroy();
		glGenVertexArrays(1, &vao);
	}
	void VAO::Destroy()
	{
		if (vao == 0)
			return;
		glDeleteVertexArrays(1, &vao);
		vao = 0;
	}
}