
#include "uniform_variable.hpp"
#include "exception.hpp"
#include "error.hpp"



namespace gl
{
    UniformVariable::UniformVariable(): location(0) {}

    UniformVariable::~UniformVariable() {}

    void UniformVariable::setLocation(GLuint shaderProgramHandle, const GLchar* uniformVariableName)
    {
        location = glGetUniformLocation(shaderProgramHandle, uniformVariableName);

        if(location == -1)
        {
            //throw(Exception("OpenglUniform::getLocation", "glGetUniformLocation", "Uniform name doesn't correspond to an active uniform variable."));
            throw(Exception("Uniform name doesn't correspond to an active uniform variable."));
        }
        if(Error::check() == true)
        {
            //throw(Exception("OpenglUniform::getLocation", "glGetUniformLocation", Error::get()));
            throw(Exception(Error::get()));
        }
    }

    GLint UniformVariable::getLocation()
    {
        return(location);
    }

    void UniformVariable::setData(const GLfloat* data)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, data);
    }

    void UniformVariable::setData(const GLint data) // FIX: Pointer here?
    {
        glUniform1i(location, data);
    }

    /*

        void setUniformMatrix (unsigned int location, glm::mat4 matrix)
        {
            checkError (glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr (matrix)));
        }

        void setUniformVector (unsigned int location, glm::vec2 vector)
        {
            checkError (glUniform2fv(location, 1, glm::value_ptr (vector)));
        }

        void setUniformVector (unsigned int location, float x, float y)
        {
            checkError (glUniform2fv(location, 1, glm::value_ptr (glm::vec2 (x, y))));
        }

        void setUniformFloat (const char * name, float data)
        {
            checkError (glUniform1f ( uniforms[ name ], data ) );
        }

        void setUniformInteger (const char * name, int data)
        {
            checkError (glUniform1i ( uniforms[ name ], data ) );
        }

        void setUniformUnsignedInteger (const char * name, unsigned int data)
        {
            checkError (glUniform1ui ( uniforms[ name ], data ) );
        }

        void setUniformMatrix( const char * name, glm::mat4 matrix )
        {
            glUniformMatrix4fv( uniforms[ name ], 1, GL_FALSE, glm::value_ptr( matrix ) );
        }

    */
}
