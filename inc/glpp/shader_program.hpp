
#ifndef __GLPP_SHADER_PROGRAM_HPP_INCLUDED__
#define __GLPP_SHADER_PROGRAM_HPP_INCLUDED__

#include "glad/glad.h"



namespace gl
{
    struct ShaderProgram
    {
    public:
        
        ShaderProgram();
        ~ShaderProgram();

        void bind();
        void unbind();

        void attachStage(GLuint shaderStageHandle);
        void detachStage(GLuint shaderStageHandle);
        void link();

        GLuint getHandle();

    private:

        GLuint handle;

    };
}

#endif
