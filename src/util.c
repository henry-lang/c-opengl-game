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
	FILE *file = fopen(path, "rb");
	if(!file) {
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);

	// Allocate enough space for null-terminator.
	char *buffer = allocate(length + 1);

	fread(buffer, 1, length, file);
	if(ferror(file)) {
		// Couldn't read file.
		free(buffer);
		return NULL;
	}
	fclose(file);

	// Very important
	buffer[length] = '\0';
	
	return buffer;
}