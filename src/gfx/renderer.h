#pragma once

#include "shader.h"
#include "camera.h"
#include "vao.h"
#include "vbo.h"
#include "../math/mat4.h"

typedef enum ShaderType {
	SHADER_BASIC,
	NUM_SHADERS // Must always be last element
} ShaderType;

typedef struct Renderer {
	Shader shaders[NUM_SHADERS];
	Camera camera;
	VAO quad_vao;
	VBO quad_vbo;
	VBO quad_ibo;
} Renderer;

Renderer renderer_init(void);
void renderer_use_shader(Renderer *, ShaderType);
void renderer_free(Renderer *);