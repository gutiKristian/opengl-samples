#version 450 core

// final color that is drawn inside framebuffer 0 -> screen
layout (location = 0) out vec4 FragColor;

void main()
{
    FragColor = vec4(0.5f, 0.3f, 0.2f, 1.0f);
}