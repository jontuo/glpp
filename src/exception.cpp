
#include "exception.hpp"



namespace gl
{
    Exception::Exception(std::string reason): reason(reason) {}

    const char* Exception::getReason() const throw()
    {
        return reason.c_str();
    }
}
