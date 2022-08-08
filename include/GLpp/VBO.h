#pragma once

#include "Types.h"

namespace glpp {
	class VAO;

	class VBO
	{
	private:
		GLuint vbo;
	public:
		enum buffer_usage
		{
			STREAM_DRAW = GL_STREAM_DRAW,
			STREAM_READ = GL_STREAM_READ,
			STREAM_COPY = GL_STREAM_COPY,
			STATIC_DRAW = GL_STATIC_DRAW,
			STATIC_READ = GL_STATIC_READ,
			STATIC_COPY = GL_STATIC_COPY,
			DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
			DYNAMIC_READ = GL_DYNAMIC_READ,
			DYNAMIC_COPY = GL_DYNAMIC_COPY
		};
		enum buffer_type
		{
			ElementArray = GL_ELEMENT_ARRAY_BUFFER,
			Array = GL_ARRAY_BUFFER
		};
	public:
		VBO();
		VBO(const VBO& vbo);
		VBO(const void* data, size_t length, buffer_usage usage);

		~VBO();

		void BindAttribute(GLint attrib, const VAO& vao, glpp::Type type, GLuint count, GLuint stride = 0, size_t offset = 0);

		void SetData(const void* data, size_t length, buffer_usage usage, buffer_type type = buffer_type::Array);
		void SubSetData(const void* data, size_t offset, size_t length);

		void Create();
		void Destroy();
		operator GLuint() const;
	};
}
