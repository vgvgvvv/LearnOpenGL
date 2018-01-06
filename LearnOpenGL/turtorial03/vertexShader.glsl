#version 330 core

layout(location = 0) in vec3 aPos;//位置变量
layout(location = 1) in vec3 aColor;//位置颜色

out vec3 ourColor;

void main() {
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
}