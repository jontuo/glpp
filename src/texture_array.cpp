
#include "texture_array.hpp"



namespace gl
{
    TextureArray::TextureArray():
        target(GL_TEXTURE_2D_ARRAY)
    {
        glGenTextures(1, &handle);
    }

    TextureArray::~TextureArray()
    {
        glDeleteTextures(1, &handle);
    }

    void TextureArray::bind()
    {
        glBindTexture(target, handle);
    }

    void TextureArray::unbind()
    {
        glBindTexture(target, 0);
    }

    void TextureArray::setData(const GLvoid* data)
    {

        GLsizei imageWidth = 640;
        GLsizei imageHeight = 640;
        GLsizei textureWidth = 16;
        GLsizei textureHeight = 16;
        GLsizei textureDepth = 1600;
        GLint textureZ = 0;

        glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        //glTexStorage3D (GL_TEXTURE_2D_ARRAY, 1, GL_RGBA8, this->size.x, this->size.y, this->depth);
        glTexImage3D(target, 0, GL_RGBA8, textureWidth, textureHeight, textureDepth, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);


        for(GLsizei imageY = 0; imageY < imageHeight; imageY = imageY + textureHeight)
        {
            for(GLsizei imageX = 0; imageX < imageWidth; imageX = imageX + textureWidth)
            {
                glPixelStorei(GL_UNPACK_ROW_LENGTH, imageWidth);
                glPixelStorei(GL_UNPACK_SKIP_PIXELS, imageX);
                glPixelStorei(GL_UNPACK_SKIP_ROWS, imageY);
                
                glTexSubImage3D(target, 0, 0, 0, textureZ, textureWidth, textureHeight, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);

                textureZ = textureZ + 1;
            }
        }
    }
}
