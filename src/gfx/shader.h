#pragma once

#include "../types.h"
#include "libs.h"

typedef struct VertexAttribute {
	GLuint index;
	char *name;
} VertexAttribute;

typedef struct Shader {
	GLuint program_handle;
} Shader;

Shader shader_init(const char *, const char *, usize, const VertexAttribute[]);
void shader_free(Shader *);