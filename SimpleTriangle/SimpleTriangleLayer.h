//
// Created by krist on 27. 6. 2023.
//
#include "core/Application.h"
#include "core/Layer.h"
#include "glad/glad.h"
#include "glutil/Shader.h"

class SimpleTriangleLayer : public Dunno::Layer
{
    // Data are provided in NDC -- normalized device coordinates
    float data[9] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    GLuint vbo;
    Dunno::Shader fragmentShader;
    Dunno::Shader vertexShader;


public:

    void OnAttach() override
    {
        // Create Vertex buffer object --> it's the object where we store the data on GPU
        glCreateBuffers(1, &vbo);
        // Bind create buffer
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        // Copying data to currently bound buffer -- opengl works like state machine
        // currently selected/bounded things are edited or in other words we work with them
        glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

        // Just compiled shaders
        vertexShader = Dunno::Shader("shaders/default.vert", GL_VERTEX_SHADER);
        fragmentShader = Dunno::Shader("shaders/default.frag", GL_FRAGMENT_DEPTH);
        // Now create Shader Program

    };

};