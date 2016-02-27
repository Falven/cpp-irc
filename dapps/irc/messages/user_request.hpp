#ifndef USER_REQUEST_H
#define USER_REQUEST_H

#include <string>
#include "request.hpp"
#include "..\username.hpp"
#include "..\user_mode.hpp"

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: USER
		/// Parameters: <user> <mode> <unused> <realname>
		///
		/// The USER command is used at the beginning of connection to specify
		/// the username, hostname and realname of a new user.
		///
		/// The <mode> parameter should be a numeric, and can be used to
		/// automatically set user modes when registering with the server.This
		/// parameter is a bitmask, with only 2 bits having any signification : if
		/// the bit 2 is set, the user mode 'w' will be set and if the bit 3 is
		/// set, the user mode 'i' will be set.  (See Section 3.1.5 "User
		/// Modes"). The <realname> may contain space characters.
		///
		/// Numeric Replies:
		/// ERR_NEEDMOREPARAMS              ERR_ALREADYREGISTRED
		///
		/// Example:
		/// USER guest 0 * : Ronnie Reagan
		/// ; User registering themselves with a username of
		/// "guest" and real name "Ronnie Reagan".
		///
		/// USER guest 8 * :Ronnie Reagan
		/// ; User registering themselves with a username of
		/// "guest" and real name "Ronnie Reagan", and
		/// asking to be set invisible.
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class user_request : public request
		{
		public:
			user_request(const username & user, const user_mode & mode)
				: request(COMMAND, { user.get_nickname().str(), std::to_string(mode.get_mask()), UNUSED, user.get_real_name() }) {}

			static const std::string COMMAND;
			static const std::string UNUSED;
		};

		const std::string user_request::COMMAND("USER");
		const std::string user_request::UNUSED("*");
	}
}

#endif