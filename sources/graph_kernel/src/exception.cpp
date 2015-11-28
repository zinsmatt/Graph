#include "exception.h"
#include <sstream>




LogException::LogException(const char *msg, int line, const char *file)
{
    std::stringstream ss;
    ss << "Error : " << msg << ", line " << line << " in file " << file;
    this->msg = ss.str();
}

const char* LogException::what() const throw()
{
    return this->msg.c_str();
}
