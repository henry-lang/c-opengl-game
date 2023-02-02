#include "renderer.h"
#include "shader.h"
#include "camera.h"
#include "vao.h"
#include "vbo.h"
#include "window.h"
#include "../math/mat4.h"

Vec2 QUAD_POSITIONS[] = {
	{{0.0f, 0.0f}},
	{{0.0f, 1.0f}},
	{{1.0f, 0.0f}}
};
GLuint QUAD_INDICES[] = {0, 1, 2, 2, 1, 3};

Renderer renderer_init(void) {
	Renderer self = {0};

	self.shaders[SHADER_BASIC] = shader_init(
		"./res/shaders/basic.vs",
		"./res/shaders/basic.fs",
		1,
		(VertexAttribute[]) {{0, "position"}}
	);

	self.camera = camera_init((Vec2) {{0.0f, 0.0f}}, (Vec2) {{window.size.x, window.size.y}}, 100.0f);


	self.quad_vbo = vbo_init(GL_ARRAY_BUFFER, false);
	vbo_data(&self.quad_vbo, sizeof(QUAD_POSITIONS), QUAD_POSITIONS);

	self.quad_ibo = vbo_init(GL_ELEMENT_ARRAY_BUFFER, false);
	vbo_data(&self.quad_ibo, sizeof(QUAD_INDICES), QUAD_INDICES);

	self.quad_vao = vao_init();
	


	return self;
}

void renderer_use_shader(Renderer *self, ShaderType type) {
	glUseProgram(self->shaders[type].program_handle);
}

void renderer_free(Renderer *self) {
	for(int i = 0; i < NUM_SHADERS; i++) {
		shader_free(&self->shaders[i]);
	}
}