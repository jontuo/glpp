
#ifndef __GLPP_TEXTURE_ARRAY_HPP_INCLUDED__
#define __GLPP_TEXTURE_ARRAY_HPP_INCLUDED__

#include "glad/glad.h"



namespace gl
{
    class TextureArray
    {
    public:

        TextureArray();
        ~TextureArray();

        void bind();
        void unbind();

        void setData(const GLvoid* data);
        
    private:
        GLuint handle;
        GLenum target;
    };
}

#endif
