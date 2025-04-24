
#include "vertex_buffer.hpp"



namespace gl
{
    VertexBuffer::VertexBuffer(GLenum target, GLenum usage)
    :   target(target), usage(usage), size(0)
    {
        glGenBuffers(1, &handle);
    }

    VertexBuffer::~VertexBuffer()
    {
        if(handle != 0)
        {
            glDeleteBuffers(1, &handle);
        }
    }

    void VertexBuffer::bind()
    {
        glBindBuffer(target, handle);
    }

    void VertexBuffer::unbind()
    {
        glBindBuffer(target, 0);
    }

    void VertexBuffer::setData(const void* data, size_t size)
    {
        glBufferData(target, size, data, usage);
        this->size = size;
    }

    void VertexBuffer::getData(void* data)
    {
        getSubData(data, 0, size);
    }

    void VertexBuffer::setSubData(const void * data, size_t offset, size_t size)
    {
        glBufferSubData(target, offset, size, data);
    }

    void VertexBuffer::getSubData (void * data, size_t offset, size_t size)
    {
        glGetBufferSubData(target, offset, size, data);
    }

    GLenum VertexBuffer::getTarget()
    {
        return(target);
    }
}
