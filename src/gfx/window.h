#pragma once

#include "../math/ivec2.h"

typedef struct Window {
	GLFWwindow *handle;
	ivec2 size;
} Window;

extern 