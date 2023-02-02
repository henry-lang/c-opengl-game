#pragma once

#include "../types.h"
#include "libs.h"
#include "vbo.h"

typedef struct VAO {
	GLuint handle;
} VAO;

VAO vao_init(void);
void vao_bind(VAO *);
void vao_attr(VAO *, VBO *, GLuint, GLint, GLenum, GLsizei, size_t, bool);
void vao_free(VAO *);
