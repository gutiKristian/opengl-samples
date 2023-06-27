//
// Created by krist on 27. 6. 2023.
//

#ifndef OPENGL_SAMPLES_SHADERPROGRAM_H
#define OPENGL_SAMPLES_SHADERPROGRAM_H

#include <filesystem>
#include "glutil/Shader.h"
#include "glad/glad.h"

namespace Dunno
{
    struct ShaderProgram
    {

        /**
         * Initializes the ShaderProgram using paths. Shader objects are constructed and ShaderProgram(Shader, Shader)
         * ctor is called.
         *
         * @param vertexShader      Path to this file.
         * @param fragmentShader    Path to this file.
         */
        ShaderProgram(const std::filesystem::path& vertexShader, const std::filesystem::path& fragmentShader);

        /**
         * Initializes ShaderProgram with provided Shaders.
         * @param vertex
         * @param fragment
         */
        ShaderProgram(Shader vertex, Shader fragment);
    private:
        /**
         * Initializes the mProgram, it's always called when we create ShaderProgram, therefore
         * OpenGL context must be initialized.
         */
        ShaderProgram();

        /**
         * ID of the program.
         */
        GLuint mProgram;

        /**
         * Status of the program.
         */
        bool mStatus;

        /**
         * In the future we might use more than two default shaders (e.g. Tesselation, Geometry).
         */
        std::vector<Shader> mShaders;
    };


}

#endif //OPENGL_SAMPLES_SHADERPROGRAM_H
