
#ifndef __GLPP_VERTEX_BUFFER_HPP_INCLUDED__
#define __GLPP_VERTEX_BUFFER_HPP_INCLUDED__

#include "glad/glad.h"



namespace gl
{
    class VertexBuffer
    {
    public:

        VertexBuffer(GLenum target, GLenum usage);
        ~VertexBuffer();

        void bind();
        void unbind();

        void setData(const void* data, size_t size);
        void getData(void* data);
        void setSubData(const void* data, size_t offset, size_t size);
        void getSubData(void* data, size_t offset, size_t size);

        GLenum getTarget();


    private:
        GLuint handle;
        GLenum target;
        GLenum usage;

        size_t size;
    };
}

#endif
