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
				: runtime_error(message + DELIM_ + ec.message()),
				error_message_(message),
				error_code_(ec)
            {
			}

			const std::string error_message() const
			{
				return error_message_;
			}

			const boost::system::error_code error_code() const
			{
				return error_code_;
			}

        private:
			static const std::string DELIM_;
            const std::string error_message_;
			const boost::system::error_code error_code_;
        };

		const std::string irc_exception::DELIM_(": ");
    }
}

#endif