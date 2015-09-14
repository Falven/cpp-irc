#ifndef IRC_EXCEPTION_H
#define IRC_EXCEPTION_H

#include <string>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////
/// <summary>   Base class for all irc exceptions. </summary>
///
/// <remarks>   Francisco, 5/8/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_exception : public std::exception
{
public:
    typedef std::exception base;

    explicit irc_exception(const std::string & message)
        : base(message.c_str()) {}

    explicit irc_exception(const char * message)
        : base(message) {}
};

#endif IRC_EXCEPTION_H