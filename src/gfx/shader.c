#include <stdio.h>
#include <stdlib.h>

#include "../util.h"
#include "libs.h"
#include "shader.h"

static void shader_log_failure(
	GLuint handle,
	const char *path,
	const char *stage,
	void (*get_log)(GLuint, GLsizei, GLsizei *, GLchar *),
	void (*get_iv)(GLuint, GLenum, GLint *)
) {
	GLint length;
	get_iv(handle, GL_INFO_LOG_LENGTH, &length);
	
	char *info_log = allocate(length);
	get_log(handle, length, NULL, info_log);

	printf("Error while %s shader %s:\n%s", stage, path, info_log);

	free(info_log);
	exit(EXIT_FAILURE);
}

static GLuint shader_compile(const char *path, GLenum type) {
	char *source = read_file_to_string(path);
	if(!source) {
		printf("Failed to read shader %s to file.", path);
		exit(EXIT_FAILURE);
	}

	GLuint handle = glCreateShader(type);
	glShaderSource(handle, 1, (const GLchar *const *) &source, NULL);
	glCompileShader(handle);

	GLint success;
	glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
	if(!success) {
		shader_log_failure(handle, path, "compiling", glGetShaderInfoLog, glGetShaderiv);
	}
	
	free(source);
	return handle;
}

Shader shader_init(
	const char *vs_path,
	const char *fs_path,
	usize num_attrs,
	const VertexAttribute attrs[]
) {
	Shader self = {
		.program_handle = glCreateProgram()
	};

	GLuint vs = shader_compile(vs_path, GL_VERTEX_SHADER);
	GLuint fs = shader_compile(fs_path, GL_FRAGMENT_SHADER);

	glAttachShader(self.program_handle, vs); 
	glAttachShader(self.program_handle, fs);

	for(usize i = 0; i < num_attrs; i++) {
		glBindAttribLocation(self.program_handle, attrs[i].index, attrs[i].name);
	}

	glLinkProgram(self.program_handle);
	GLint success;
	glGetProgramiv(self.program_handle, GL_LINK_STATUS, &success);
	if(!success) {
		shader_log_failure(self.program_handle, vs_path, "linking", glGetProgramInfoLog, glGetProgramiv);
	}

	glDetachShader(self.program_handle, vs);
	glDetachShader(self.program_handle, fs);
	glDeleteShader(vs);
	glDeleteShader(fs);

	return self;
}

void shader_free(Shader *self) {
	glDeleteProgram(self->program_handle);
}