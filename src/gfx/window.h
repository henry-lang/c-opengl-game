#pragma once

#include "../math/ivec2.h"
#include "libs.h"

typedef struct Window {
	GLFWwindow *handle;
	IVec2 size;
} Window;

// Evil global window
extern struct Window window;

void window_init(void);