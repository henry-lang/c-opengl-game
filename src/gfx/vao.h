#pragma once

#include "libs.h"

typedef struct VAO {
	GLuint handle;
} VAO;

VAO vao_init(void);
void vao_bind(VAO *);
void vao_attr(VAO *);
void vao_free(VAO *);
