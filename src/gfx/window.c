#include <stdio.h>
#include <stdlib.h>

#include "../math/ivec2.h"
#include "libs.h"
#include "window.h"

Window window;

static void _window_size_cb(GLFWwindow *handle, int width, int height) {
	window.size = ivec2(width, height);
	glViewport(0, 0, width, height);
}

static void _error_cb(int code, const char *description) {
    fprintf(stderr, "GLFW error %d: %s\n", code, description);
}

void window_init(void) {
    glfwSetErrorCallback(_error_cb);

    if(!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window.size = ivec2(800, 600);
    window.handle = glfwCreateWindow(window.size.x, window.size.y, "Game", NULL, NULL);
    if(!window.handle) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window.handle);
    glfwSetFramebufferSizeCallback(window.handle, _window_size_cb);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "%s",  "error initializing GLAD\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}