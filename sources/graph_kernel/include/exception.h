#ifndef EXCEPTION
#define EXCEPTION

#include <exception>
#include <string>


class LogException : public std::exception
{
    std::string msg;
public:
    LogException(const char *msg, int line, const char *file);
    virtual ~LogException() throw () {}

    virtual const char * what() const throw();
};









#endif // EXCEPTION

