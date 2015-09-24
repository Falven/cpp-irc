#ifndef IRC_EXCEPTION_H
#define IRC_EXCEPTION_H

#include <string>
#include <stdexcept>

namespace dapps
{
    namespace irc
    {
        ///////////////////////////////////////////////////////////////////////////////
        /// <summary>   Base class for all irc exceptions. </summary>
        ///
        /// <remarks>   Francisco, 5/8/2015. </remarks>
        ///////////////////////////////////////////////////////////////////////////////
        class irc_exception : public std::runtime_error
        {
        public:
            explicit irc_exception(const std::string & message)
                : std::runtime_error(message.c_str())
            {}

            explicit irc_exception(const char * message)
                : std::runtime_error(message)
            {}

            virtual const char * what() const throw()
            {
                return ((std::runtime_error *)this)->what();
            }
        };
    }
}

#endif