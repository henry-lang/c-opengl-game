#pragma once

#include "shader.h"

typedef enum ShaderType {
	SHADER_BASIC,
	NUM_SHADERS // Must always be last element
} ShaderType;

typedef struct Renderer {
	Shader shaders[NUM_SHADERS];
} Renderer;

Renderer renderer_init();
void renderer_free(Renderer *);