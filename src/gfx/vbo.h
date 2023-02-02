#pragma once

#include <stdbool.h>

typedef struct VBO {
	GLenum target;
	bool dynamic;
	GLuint handle;
} VBO;

VBO vbo_init(GLenum, bool);
void vbo_bind(VBO *);
void vbo_data(VBO *, GLsizei, const void *);
void vbo_free(VBO *);