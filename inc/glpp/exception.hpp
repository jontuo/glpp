
#ifndef __GLPP_EXCEPTION_HPP_INCLUDED__
#define __GLPP_EXCEPTION_HPP_INCLUDED__

#include <string>


namespace gl
{
    class Exception: public std::exception
    {
    public:
        Exception(std::string reason);
        const char* getReason() const throw();
    private:
        std::string reason;
    };
}

#endif
