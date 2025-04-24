
#include "shader_program.hpp"
#include "exception.hpp"
#include "error.hpp"



namespace gl
{
    ShaderProgram::ShaderProgram()
    {
        handle = glCreateProgram();
        if(Error::check() == true)
        {
            //throw(Exception("ShaderProgram::ShaderProgram", "glCreateProgram", Error::get()));
            throw(Exception(Error::get()));
        }
    }

    ShaderProgram::~ShaderProgram()
    {
        if(handle != 0)
        {
            glDeleteProgram(handle);
        }
    }

    void ShaderProgram::bind()
    {
        glUseProgram(handle);
    }

    void ShaderProgram::unbind()
    {
        glUseProgram(0);
    }

    void ShaderProgram::attachStage(GLuint shaderStageHandle)
    {
        glAttachShader(handle, shaderStageHandle);
        if(Error::check() == true)
        {
            //throw(Exception("ShaderProgram::attachStage", "glAttachShader", Error::get()));
            throw(Exception(Error::get()));
        }
    }

    void ShaderProgram::detachStage(GLuint shaderStageHandle)
    {
        glDetachShader(handle, shaderStageHandle);
        if(Error::check() == true)
        {
            //throw(Exception("ShaderProgram::detachStage", "glDetachShader", Error::get()));
            throw(Exception(Error::get()));
        }
    }

    void ShaderProgram::link()
    {
        glLinkProgram(handle);
        if(Error::check() == true)
        {
            //throw(Exception("ShaderProgram::link", "glLinkProgram", Error::get()));
            throw(Exception(Error::get()));
        }

        int linkStatus;
        glGetProgramiv(handle, GL_LINK_STATUS, &linkStatus);
        if(linkStatus == GL_FALSE)
        {
            char log[512];
            glGetProgramInfoLog(handle, 512, NULL, log);
            glDeleteProgram(handle);
            //throw Exception("ShaderProgram::link", "glLinkProgram", std::string(log, 512));
            throw(Exception(std::string(log, 512)));
        }
    }

    GLuint ShaderProgram::getHandle()
    {
        return(handle);
    }
}
