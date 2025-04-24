
#ifndef __GLPP_VERTEX_ARRAY_HPP_INCLUDED__
#define __GLPP_VERTEX_ARRAY_HPP_INCLUDED__

#include "glad/glad.h"



namespace gl
{
    class VertexArray
    {
    public:

        VertexArray();
        ~VertexArray();

        void bind();
        void unbind();

        void enableAttribute(GLuint index);
        void disableAttribute(GLuint index);
        void setFloatingAttribute(GLuint index, GLint size, GLenum type, GLboolean normal, GLsizei stride, const GLvoid* offset);
        void setIntegerAttribute(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid* offset);

    private:
        GLuint handle;
    };
}  

#endif
