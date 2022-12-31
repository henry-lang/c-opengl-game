#include "libs.h"
#include "vao.h"
#include "vbo.h"

VAO vao_init(void) {
	VAO self;
	glGenVertexArrays(1, &self.handle);
	return self;
}

void vao_bind(VAO *self) {
	glBindVertexArray(self->handle);
}

void vao_attr(VAO *self) {

}

void vao_free(VAO *self) {
	glDeleteVertexArrays(1, &self->handle);
}
