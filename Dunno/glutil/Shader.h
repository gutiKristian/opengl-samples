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
        Shader(const std::filesystem::path& shaderPath, GLenum type);
        ~Shader();
        inline int GetId() const { return mId;}

    private:
        std::string LoadShader();

    private:
        GLuint mId;
        GLenum mType;
        std::filesystem::path mPath{};
    };
}


#endif //OPENGL_SAMPLES_SHADER_H
