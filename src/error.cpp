
#include "error.hpp"
#include "glad/glad.h"



namespace gl
{
    std::string Error::error;

    bool Error::check()
    {
        GLenum code;
        if((code = glGetError()) != GL_NO_ERROR)
        {
            switch(code)
            {
                case GL_INVALID_ENUM:                  error = "Invalid enumerate"; break;
                case GL_INVALID_VALUE:                 error = "Invalid value"; break;
                case GL_INVALID_OPERATION:             error = "Invalid operation"; break;
                case GL_STACK_OVERFLOW:                error = "Stack overflow"; break;
                case GL_STACK_UNDERFLOW:               error = "Stack underflow"; break;
                case GL_OUT_OF_MEMORY:                 error = "Out of memory"; break;
                case GL_INVALID_FRAMEBUFFER_OPERATION: error = "Invalid framebuffer operation"; break;
            }

            return(true);
        }

        return(false);
    }

    std::string Error::get()
    {
        return(error);
    }
}