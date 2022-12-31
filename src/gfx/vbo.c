#include <stdbool.h>

#include "libs.h"
#include "vbo.h"

VBO vbo_create(GLenum target, bool dynamic) {
	VBO self = {
		.target = target,
		.dynamic = dynamic
	};

	glGenBuffers(1, &self.handle);

	return self;
}

void vbo_bind(VBO *self) {
	// TODO: see if we can use DSA
	glBindBuffer(self->target, self->handle);
}

void vbo_data(VBO *self, GLsizei size, const void *data) {
	// TODO: reduce amount of binding
	vbo_bind(self);
	glBufferData(self->target, size, data, self->dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}

void vbo_free(VBO *self) {
	glDeleteBuffers(1, &self->handle);
}