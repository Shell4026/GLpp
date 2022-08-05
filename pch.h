
#include <errno.h>

#include <vector>
#include <string>
#include <string_view>

#ifdef __ANDROID__
#include <jni.h>
#include <unistd.h>
#include <sys/resource.h>
#include <android/log.h>
#include <GLES3/gl32.h>
#include <GLES3/gl3ext.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <GL/glew.h>
#include <gl/GL.h>
#endif