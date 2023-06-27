//
// Created by krist on 27. 6. 2023.
//

#include <fstream>

#include "Shader.h"
#include "core/Log.h"

namespace Dunno
{

    Shader::Shader(const std::filesystem::path& path, GLenum type) : mPath(path), mType(type)
    {
        std::string sourceCode = LoadShader();
        // glCreateShader takes the type of the shader we want to create
        mId = glCreateShader(type);
        const char *source = sourceCode.c_str();

        // Then we link this shader with source code, we send it as a one chunk
        glShaderSource(mId, 1, &source, nullptr);

        glCompileShader(mId);

        int status;
        glGetShaderiv(mId, GL_COMPILE_STATUS, &status);

        if (status == GL_TRUE)
        {
            return;
        }

        // Fail!
        switch (type)
        {
            case GL_VERTEX_SHADER:
                LOG_ERROR("Failed to compile Vertex shader");
                break;
            case GL_FRAGMENT_SHADER:
                LOG_ERROR("Failed to compile Fragment shader");
                break;
            default:
                // will add another types as we are going to work with them
                LOG_ERROR("Failed to compile shader");
                break;
        }

        glDeleteShader(mId);
        mId = 0;

    }

    std::string Shader::LoadShader()
    {
        std::ifstream stream(mPath);
        std::string source;

        if (!stream.is_open())
        {
            LOG_ERROR("Couldn't open file: ", mPath.string());
            return source;
        }

        std::string line;
        while(std::getline(stream, line))
        {
            source += line + '\n';
        }

        return source;
    }

    Shader::Shader()
    {
        mId = 0;
    }

    Shader::~Shader()
    {
        glDeleteShader(mId);
    }

}
