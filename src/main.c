#include <stdio.h>
#include <stdlib.h>

#include "gfx/libs.h"
#include "gfx/window.h"
#include "gfx/renderer.h"
#include "gfx/shader.h"
#include "gfx/vao.h"
#include "gfx/vbo.h"

int main(int argc, char **argv) {
    window_init();

    while(!glfwWindowShouldClose(window.handle)) {
        glClearColor(1.0, 0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window.handle);
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}
