#include "OpenGL.h"
#include "Context.h"

namespace glpp
{
	Context::Context()
	{

	}
	Context::~Context()
	{
	}
	void Context::Clear(uint buffer)
	{
		glClear(buffer);
	}

	auto Context::DrawArrays(const VAO& vao, Primitive mode, uint count, uint offset) -> void
	{
		vao.Bind();
		glDrawArrays(mode, offset, count);
		glBindVertexArray(0);
		glUseProgram(0);
	}
	auto Context::DrawElements(const VAO& vao, Primitive mode, uint count, uint offset) -> void
	{
		vao.Bind();
		glDrawElements(mode, count, GL_UNSIGNED_SHORT, 0);
		glBindVertexArray(0);
		glUseProgram(0);
	}
}