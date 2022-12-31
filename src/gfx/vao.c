#include "libs.h"
#include "vao.h"
#include "vbo.h"

VAO vao_init() {
	VAO self;
	glGenVertexArrays(1, &self.handle);
	return self;
}

void vao_bind(VAO *self) {
	glBindVertexArray(1, &self->handle);
}

void vao_attr(VAO *self, VBO *vbo, ) {

}

void vao_free(VAO *self) {
	glDeleteVertexArrays(1, )
}