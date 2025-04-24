
#ifndef __GLPP_UNIFORM_VARIABLE_HPP_INCLUDED__
#define __GLPP_UNIFORM_VARIABLE_HPP_INCLUDED__

#include "glad/glad.h"



namespace gl
{
    class UniformVariable
    {

    public:
        UniformVariable();
        ~UniformVariable();

        void setLocation(GLuint shaderProgramHandle, const GLchar* uniformVariableName);
        GLint getLocation();

        void setData(const GLfloat* data);
        void setData(const GLint data);

    private:
        GLint location;

    };
}

#endif
