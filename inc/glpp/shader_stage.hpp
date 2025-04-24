
#ifndef __GLPP_SHADER_STAGE_HPP_INCLUDED__
#define __GLPP_SHADER_STAGE_HPP_INCLUDED__

#include <string>
#include "glad/glad.h"



namespace gl
{
    class ShaderStage
    {
    public:

        ShaderStage(GLenum stageType);
        ~ShaderStage();

        void setSource(const std::string& source);
        void compile();
        GLuint getHandle();
    private:
        GLuint handle;
    };
}

#endif
