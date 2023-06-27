//
// Created by krist on 27. 6. 2023.
//

#include "ShaderProgram.h"
#include "core/Log.h"
namespace Dunno
{
    ShaderProgram::ShaderProgram(const std::filesystem::path& vertexShader, const std::filesystem::path& fragmentShader)
        :ShaderProgram(Shader(vertexShader, GL_VERTEX_SHADER),
                       Shader(fragmentShader, GL_FRAGMENT_SHADER))
    {
    }

    ShaderProgram::ShaderProgram(Shader vertex, Shader fragment)
        :ShaderProgram()
    {
        if (!mProgram)
        {
            LOG_ERROR("Error while creating ShaderProgram, invalid mProgram!!!");
        }

        mShaders.push_back(vertex);
        mShaders.push_back(fragment);

        // Check if GetId returns non-zero, then proceed? -- we already log such thing inside Shader

        glAttachShader(mProgram, vertex.GetId());
        glAttachShader(mProgram, fragment.GetId());

        glLinkProgram(mProgram);
        int link;
        glGetProgramiv(mProgram, GL_LINK_STATUS, &link);

        if (link == GL_FALSE)
        {
            mStatus = false;
        }
        else
        {
            mStatus = true;
        }

    }

    ShaderProgram::ShaderProgram()
    {
        mProgram = glCreateProgram();
    }

}