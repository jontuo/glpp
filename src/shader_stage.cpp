
#include "shader_stage.hpp"
#include "exception.hpp"
#include "error.hpp"



namespace gl
{
    ShaderStage::ShaderStage(GLenum stageType): handle((GLuint)0)
    {
        handle = glCreateShader(stageType);
        if(Error::check() == true)
        {
            //throw(Exception("ShaderStage::ShaderStage", "glCreateShader", Error::get()));
            throw(Exception(Error::get()));
        }
    }

    ShaderStage::~ShaderStage()
    {
        if(handle != 0)
        {
            glDeleteShader(handle);
        }
    }

    void ShaderStage::setSource(const std::string& source)
    {
        const char* sourcePointer = source.c_str();
        //const char* sourcePointer = source.data();
        glShaderSource(handle, 1, &sourcePointer, NULL);
        if(Error::check() == true)
        {
            //throw(Exception("ShaderStage::setSource", "glShaderSource", Error::get()));
            throw(Exception(Error::get()));
        }
    }

    void ShaderStage::compile()
    {
        glCompileShader(handle);
        if(Error::check() == true)
        {
            //throw(Exception("ShaderStage::compile", "glCompileShader", Error::get()));
            throw(Exception(Error::get()));
        }

        signed int compileStatus;
        glGetShaderiv(handle, GL_COMPILE_STATUS, &compileStatus);
        if(compileStatus == GL_FALSE)
        {
            char logData[512];
            glGetShaderInfoLog(handle, 512, NULL, logData);
            //throw(Exception("ShaderStage::compile", "glCompileShader", std::string(logData, 512)));
            throw(Exception(std::string(logData, 512)));
        }
    }

    GLuint ShaderStage::getHandle()
    {
        return(handle);
    }
}