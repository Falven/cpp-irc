#ifndef PONG_REQUEST_HPP
#define PONG_REQUEST_HPP

#include <string>
#include "request.hpp"

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: PONG
		/// Parameters: <server>[<server2>]
		///
		/// PONG message is a reply to ping message.If parameter <server2> is
		/// given, this message MUST be forwarded to given target.The <server>
		/// parameter is the name of the entity who has responded to PING message
		/// and generated this message.
		///
		/// Numeric Replies:
		/// ERR_NOORIGIN    ERR_NOSUCHSERVER
		///
		/// Example:
		/// PONG csd.bu.edu tolsun.oulu.fi
		/// ; PONG message from csd.bu.edu to tolsun.oulu.fi
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class pong_request : public request
		{
		public:
			static const std::string COMMAND;

			pong_request(const std::initializer_list<std::string> && servers)
				: request(COMMAND, { parse_servers(servers) })
			{
			}

		private:
			std::string parse_servers(const std::initializer_list<std::string> & servers)
			{
				std::string servers_str;
				auto it = servers.begin();
				servers_str += *it++;
				while (it != servers.end())
				{
					servers_str += "[";
					servers_str += *it++;
					servers_str += "]";
				}
				return servers_str;
			}
		};

		const std::string pong_request::COMMAND("PONG");
	}
}

#endif