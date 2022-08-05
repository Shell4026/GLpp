#pragma once
#ifdef __ANDROID__
#include <GLES3/gl32.h>
#include <GLES3/gl3ext.h>
#endif

#ifdef _WIN32
#include <GL/glew.h>
#include <gl/GL.h>
#endif

#include "glSingleton.hpp"
#include "Types.h"
#include "VAO.h"
#include "VBO.h"
#include "Shader.h"
#include "Program.h"
#include "Context.h"