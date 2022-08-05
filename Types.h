#pragma once

namespace glpp
{
	enum Type
	{
		Byte = GL_BYTE,
		UnsignedByte = GL_UNSIGNED_BYTE,
		Short = GL_SHORT,
		UnsignedShort = GL_UNSIGNED_SHORT,
		Int = GL_INT,
		UnsignedInt = GL_UNSIGNED_INT,
		Float = GL_FLOAT,
#ifndef __ANDROID__
		Double = GL_DOUBLE
#endif
	};
	enum Buffer
	{
		Color = GL_COLOR_BUFFER_BIT,
		Depth = GL_DEPTH_BUFFER_BIT,
		Stencil = GL_STENCIL_BUFFER_BIT
	};
	enum Primitive
	{
		Points = GL_POINTS,
		Triangles = GL_TRIANGLES,
		Lines = GL_LINES
	};
}