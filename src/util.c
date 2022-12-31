#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "util.h"

void *allocate(size_t size) {
	void *data = malloc(size);

	if(!data) {
		printf("Failed to allocate memory of size %zu\n", size);
		exit(EXIT_FAILURE);
	}

	return data;
}

char *read_file_to_string(const char *path) {
	FILE *file = fopen(path, "r");
	if(!file) {
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char *buffer = allocate(length + 1);

	if(fread(buffer, 1, length, file) != (usize) length) {
		// Couldn't read entire file, just return early
		free(buffer);
		return NULL;
	}

	// Very important
	buffer[length] = '\0';

	return buffer;
}