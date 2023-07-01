#pragma once

#include "shader.h"
#include "camera.h"
#include "vao.h"
#include "vbo.h"
#include "../math/vec2.h"
#include "../math/mat4.h"

#define MAX_BATCH_VERTS 240000
_Static_assert(MAX_BATCH_VERTS % 6 == 0, "MAX_BATCH_VERTS must be divisible by 6");

typedef enum ShaderType {
	SHADER_BASIC,
	NUM_SHADERS // Must always be last element
} ShaderType;

typedef struct QuadRenderer {
    VAO vao;
    VBO vbo;
    Vec2 *vertices;
    usize vertex_count;
} QuadRenderer;

typedef struct Renderer {
	Shader shaders[NUM_SHADERS];
	Camera camera;
    QuadRenderer quad_renderer;
} Renderer;

QuadRenderer quad_renderer_init(void);
void quad_renderer_draw(QuadRenderer *, Vec2, Vec2);
void quad_renderer_free(QuadRenderer *);

Renderer renderer_init(void);
void renderer_begin(Renderer *);
void renderer_use_shader(Renderer *, ShaderType);
void renderer_free(Renderer *);
