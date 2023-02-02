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

    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GLfloat data[] = {
        0.00f, 0.00f,
        0.05f, 0.00f,
        0.05f, 0.05f,
        0.05f, 0.05f,
        0.00f, 0.05f,
        0.00f, 0.00f,
        0.025f, 0.025f,
        0.075f, 0.025f,
        0.075f, 0.075f,
        0.075f, 0.075f,
        0.025f, 0.075f,
        0.025f, 0.025f,
        0.00f, 0.00f,
        1.0f, 0.00f,
        1.0f, 1.0f,
        1.0f, 1.0f,
        0.00f, 1.0f,
        0.00f, 0.00f,
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);

    while(!glfwWindowShouldClose(window.handle)) {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 18);

        glfwSwapBuffers(window.handle);
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}
