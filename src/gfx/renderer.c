#include "renderer.h"
#include "shader.h"
#include "camera.h"
#include "vao.h"
#include "vbo.h"
#include "window.h"
#include "../math/mat4.h"

Renderer renderer_init(void) {
	Renderer self = {0};

	self.shaders[SHADER_BASIC] = shader_init(
		"./res/shaders/basic.vert",
		"./res/shaders/basic.frag",
		1,
		(VertexAttribute[]) {{0, "position"}}
	);

	self.camera = camera_init((Vec2) {{0.0f, 0.0f}}, (Vec2) {{window.size.x, window.size.y}}, 100.0f);


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