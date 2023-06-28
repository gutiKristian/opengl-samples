//
// Created by krist on 27. 6. 2023.
//
#include "core/Application.h"
#include "core/Layer.h"
#include "glutil/Shader.h"
#include "glutil/ShaderProgram.h"


class SimpleTriangleLayer : public Dunno::Layer
{
    // Data are provided in NDC -- normalized device coordinates
    float data[9] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

    GLuint mVbo{};
    GLuint mVao{};

    std::unique_ptr<Dunno::ShaderProgram> pProgram;

public:

    SimpleTriangleLayer() = default;

    void OnAttach() override
    {

        glGenVertexArrays(1, &mVao);
        glBindVertexArray(mVao);

        // Create Vertex buffer object --> it's the object where we store the data on GPU
        glCreateBuffers(1, &mVbo);
        // Bind create buffer
        glBindBuffer(GL_ARRAY_BUFFER, mVbo);
        // Copying data to currently bound buffer -- opengl works like state machine
        // currently selected/bounded things are edited or in other words we work with them
        glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

        std::filesystem::path shadersDir = R"(C:\dev\graphics\opengl-samples\SimpleTriangle\shaders)";

        // Just compiled shaders
        auto vertexShader = Dunno::Shader(shadersDir / "default.vert", GL_VERTEX_SHADER);
        auto fragmentShader = Dunno::Shader(shadersDir / "default.frag", GL_FRAGMENT_SHADER);
        // Now create Shader Program
        pProgram = std::make_unique<Dunno::ShaderProgram>(vertexShader, fragmentShader);

        // Do not forget/Think of this like this --> the OpenGL is a state machine and here we changed the state for used program
        pProgram->Use();

        // Once we linked the Shader objects to ShaderProgram we would
        // Delete these shader objects (glDeleteShader(<id>)), but we will keep them here


        // We uploaded the data, but we need to help OpenGL interpret them, like how should vertex shader know what
        // is the vertex in that array --> We created the VAO on line 30
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    };

    // We won't make a use of OnUpdate

    void OnUpdate() override
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

};