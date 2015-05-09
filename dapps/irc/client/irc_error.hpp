#ifndef IRC_EXCEPTIONS_H
#define IRC_EXCEPTIONS_H

#include <string>
#include <stdexcept>

#include "irc_exception.hpp"

///////////////////////////////////////////////////////////////////////////////
/// <summary>   Base class for all irc exceptions. </summary>
///
/// <remarks>   Francisco, 5/8/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_error
{
public:
private:
    const irc_exception exception_;
};

#endif IRC_EXCEPTIONS_H