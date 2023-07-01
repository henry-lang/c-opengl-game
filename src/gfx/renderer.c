#include "renderer.h"
#include "shader.h"
#include "camera.h"
#include "vao.h"
#include "vbo.h"
#include "window.h"
#include "../math/mat4.h"
#include "../math/vec2.h"
#include "../util.h"

QuadRenderer quad_renderer_init(void) {
    QuadRenderer self;
    
    self.vertex_count = 0;
    self.vertices = allocate(sizeof(Vec2) * MAX_BATCH_VERTS);

    VBO vbo = vbo_init(GL_ARRAY_BUFFER, true);
    self.vbo = vbo;

    VAO vao = vao_init();
    vao_attr(&vao, &vbo, 0, 2, GL_FLOAT, 0, 0, false);
    self.vao = vao;

    return self;
}

void quad_renderer_draw(QuadRenderer *self, Vec2 pos, Vec2 size) {
    Vec2 top_right = {{pos.x + size.x, pos.y}};
    Vec2 bottom_right = {{pos.x + size.x, pos.y + size.y}};
    Vec2 bottom_left = {{pos.x, pos.y + size.y}};

    self->vertices[self->vertex_count++] = pos;
    self->vertices[self->vertex_count++] = top_right;
    self->vertices[self->vertex_count++] = bottom_left;
    self->vertices[self->vertex_count++] = bottom_left;
    self->vertices[self->vertex_count++] = bottom_right;
    self->vertices[self->vertex_count++] = top_right;
}

// Renderer is needed for changing shaders
void quad_renderer_end(QuadRenderer *self, Renderer *renderer) {
    
    vao_bind(&self->vao);
    vbo_bind(&self->vbo);
    glDrawArrays(GL_TRIANGLES, 0, self->vertex_count / 6);

    self->vertex_count = 0;
}

void quad_renderer_free(QuadRenderer *self) {
    vao_free(&self->vao);
    vbo_free(&self->vbo);
    free(self->vertices);
}

Renderer renderer_init(void) {
	Renderer self = {0};

	self.shaders[SHADER_BASIC] = shader_init(
		"./res/shaders/basic.vs",
		"./res/shaders/basic.fs",
		1,
		(VertexAttribute[]) {{0, "position"}}
	);

	self.camera = camera_init((Vec2) {{0.0f, 0.0f}}, (Vec2) {{window.size.x, window.size.y}}, 100.0f);

    self.quad_renderer = quad_renderer_init();

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);

	return self;
}

void renderer_begin(Renderer *self) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    renderer_use_shader(self, SHADER_BASIC);


}

void renderer_quad(Renderer *self, Vec2 pos, Vec2 size) {
    quad_renderer_draw(&self->quad_renderer, pos, size);
}

void renderer_use_shader(Renderer *self, ShaderType type) {
	glUseProgram(self->shaders[type].program_handle);
}

void renderer_free(Renderer *self) {
	for(int i = 0; i < NUM_SHADERS; i++) {
		shader_free(&self->shaders[i]);
	}

    quad_renderer_free(&self->quad_renderer);
}
