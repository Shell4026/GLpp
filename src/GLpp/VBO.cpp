#include "OpenGL.h"

#include "VBO.h"
#include "VAO.h"
namespace glpp {
	VBO::VBO()
	{
		glGenBuffers(1, &vbo);
	}
	VBO::VBO(const VBO& vbo)
	{

	}
	VBO::VBO(const void* data, size_t length, buffer_usage usage)
		:VBO()
	{
		SetData(data, length, usage);
	}
	VBO::~VBO()
	{
		glDeleteBuffers(1, &vbo);
	}
	auto VBO::SetData(const void* data, size_t length, buffer_usage usage, buffer_type type)->void
	{
		glBindBuffer(type, vbo);
		glBufferData(type, length, data, usage);
		//glBindBuffer(type, 0);
	}
	auto VBO::BindAttribute(GLint attrib, const VAO& vao, glpp::Type type, GLuint count, GLuint stride, size_t offset) -> void
	{
		if (attrib == -1)
		{
			return;
		}
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(attrib, count, type, GL_FALSE, stride, (const GLvoid*)offset);
		glEnableVertexAttribArray(attrib);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	void VBO::SubSetData(const void* data, size_t offset, size_t length)
	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferSubData(GL_ARRAY_BUFFER, length, offset, data);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	auto VBO::Create() -> void
	{
		if (vbo != 0)
			Destroy();
		glGenBuffers(1, &vbo);
	}
	auto VBO::Destroy() -> void
	{
		if (vbo == 0)
			return;

		glDeleteBuffers(1, &vbo);
		vbo = 0;
	}
	VBO::operator GLuint() const
	{
		return vbo;
	}
}