#pragma once
#include "glSingleton.hpp"
#include "Types.h"
#include "VAO.h"

namespace glpp {
	typedef GLuint uint;
	class Context : public Singleton<Context>
	{
	public:
		Context();
		~Context();

		void Clear(uint buffer = Buffer::Color | Buffer::Depth);
		auto DrawArrays(const VAO &vao, Primitive mode, uint count, uint offset) -> void;
		auto DrawElements(const VAO &vao, Primitive mode, uint count, uint offset) -> void;
	};
}

