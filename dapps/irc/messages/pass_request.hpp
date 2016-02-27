#ifndef PASS_REQUEST_HPP
#define PASS_REQUEST_HPP

#include <string>

#include "request.hpp"

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: PASS
		/// Parameters: <password>
		///
		/// The PASS command is used to set a 'connection password'. The optional
		/// password can and MUST be set before any attempt to register the
		/// connection is made. Currently this requires that user send a PASS command
		/// before sending the NICK / USER combination.
		///
		/// Numeric Replies:
		/// ERR_NEEDMOREPARAMS  ERR_ALREADYREGISTRED
		///
		/// Example:
		/// PASS secretpasswordhere
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class pass_request : public request
		{
		public:
			pass_request(const std::string & pass)
				: request(COMMAND, { pass }) {}

			static const std::string COMMAND;
		};

		const std::string pass_request::COMMAND("PASS");
	}
}

#endif