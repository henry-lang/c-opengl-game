#version 330 core

uniform mat4 proj;

layout (location = 0) in vec2 position;

void main() {
    gl_Position = proj * vec4(position, 1.0, 1.0);
}
