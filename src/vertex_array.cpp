
#include "vertex_array.hpp"



namespace gl
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &handle);
    }

    VertexArray::~VertexArray()
    {
        if(handle != 0)
        {
            glDeleteVertexArrays(1, &handle);
        }
    }

    void VertexArray::bind()
    {
        glBindVertexArray(handle);
    }

    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::enableAttribute(GLuint index)
    {
        glEnableVertexAttribArray(index);
    }

    void VertexArray::disableAttribute(GLuint index)
    {
        glDisableVertexAttribArray(index);
    }

    void VertexArray::setFloatingAttribute(GLuint index, GLint size, GLenum type, GLboolean normal, GLsizei stride, const GLvoid* offset)
    {
        glVertexAttribPointer(index, size, type, normal, stride, offset);
    }

    void VertexArray::setIntegerAttribute(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* offset)
    {
        glVertexAttribIPointer(index, size, type, stride, offset);
    }
}
