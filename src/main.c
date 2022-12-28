#include <stdio.h>
#include <stdlib.h>

#include "gfx/gfx.h"
#include "math/math.h"

void error_callback(int code, const char *description) {
    fprintf(stderr, "GLFW error %d: %s\n", code, description);
}

int main(int argc, char **argv) {
    GLFWwindow *window;

    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
        return EXIT_FAILURE;

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    if(!window) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "%s",  "error initializing GLAD\n");
        glfwTerminate();
        exit(1);
    }

    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
