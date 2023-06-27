//
// Created by krist on 27. 6. 2023.
//

#ifndef OPENGL_SAMPLES_SHADER_H
#define OPENGL_SAMPLES_SHADER_H
#include "glad/glad.h"
#include <filesystem>

namespace Dunno
{
    struct Shader
    {
        static std::string LoadShader(const std::filesystem::path shaderPath);
        Shader(std::string sourceCode, GLenum type);
        inline int GetId() const { return mId;}

    private:
        int mId;
    };
}


#endif //OPENGL_SAMPLES_SHADER_H
