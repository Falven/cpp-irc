#ifndef IRC_EXCEPTION_H
#define IRC_EXCEPTION_H

#include <boost/system/error_code.hpp>
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
			explicit irc_exception(const std::string & message, const boost::system::error_code & ec)
				: runtime_error(message + delim + ec.message()),
				error_message(message),
				error_code(ec)
            {
			}

        private:
			static const std::string delim;
            const std::string error_message;
			const boost::system::error_code error_code;
        };

		const std::string irc_exception::delim(": ");
    }
}

#endif