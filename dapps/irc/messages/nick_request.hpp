#ifndef NICK_REQUEST_HPP
#define NICK_REQUEST_HPP

#include <string>
#include "request.hpp"
#include "../nickname.hpp"

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: NICK
		/// Parameters: <nickname>
		///
		/// NICK command is used to give user a nickname or change the existing one.
		///
		/// Numeric Replies:
		/// ERR_NONICKNAMEGIVEN ERR_ERRONEUSNICKNAME
		/// ERR_NICKNAMEINUSE   ERR_NICKCOLLISION
		/// ERR_UNAVAILRESOURCE ERR_RESTRICTED
		///
		/// Examples:
		/// NICK Wiz
		/// ; Introducing new nick "Wiz" if session is still unregistered,
		/// or user changing his nickname to "Wiz"
		///
		/// :WiZ!jto@tolsun.oulu.fi NICK Kilroy
		/// ; Server telling that WiZ changed his nickname to Kilroy.
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class nick_request : public request
		{
		public:
			nick_request(const nickname & nick)
				: request(COMMAND, { nick.str() }) {}

			static const std::string COMMAND;
		};

		const std::string nick_request::COMMAND("NICK");
	}
}

#endif