#include "renderer.h"
#include "shader.h"

Renderer renderer_init(void) {
	Renderer self = {0};

	self.shaders[SHADER_BASIC] = shader_init(
		"./res/shaders/basic.vs",
		"./res/shaders/basic.fs",
		1,
		(VertexAttribute[]) {{0, "position"}}
	);

	return self;
}

void renderer_free(Renderer *self) {
	for(int i = 0; i < NUM_SHADERS; i++) {
		shader_free(&self->shaders[i]);
	}
}