
#ifndef __GLPP_ERROR_HPP_INCLUDED__
#define __GLPP_ERROR_HPP_INCLUDED__

#include <string>



namespace gl
{
    class Error
    {
    public:

        static bool check();
        static std::string get();

    private:
        static std::string error;
    };
}

// Later you do not need checkError(), if you use a gl function, this class will checkError for you. And set a bool error = true;
// Later add Opengl::popError();

#endif
