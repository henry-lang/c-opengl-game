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

    Renderer renderer = renderer_init();

    renderer_use_shader(&renderer, SHADER_BASIC);

    while(!glfwWindowShouldClose(window.handle)) {
        renderer_begin(&renderer);
        glfwSwapBuffers(window.handle);
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}
