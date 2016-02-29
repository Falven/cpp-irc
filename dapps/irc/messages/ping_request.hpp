#ifndef PING_REQUEST_HPP
#define PING_REQUEST_HPP

#include <string>
#include "request.hpp"

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: PING
		/// Parameters: <server1>[<server2>]
		///
		/// The PING command is used to test the presence of an active client or
		/// server at the other end of the connection.Servers send a PING
		/// message at regular intervals if no other activity detected coming
		/// from a connection.If a connection fails to respond to a PING
		/// message within a set amount of time, that connection is closed.A
		/// PING message MAY be sent even if the connection is active.
		///
		/// When a PING message is received, the appropriate PONG message MUST be
		/// sent as reply to <server1>(server which sent the PING message out)
		/// as soon as possible.If the <server2> parameter is specified, it
		/// represents the target of the ping, and the message gets forwarded
		/// there.
		///
		/// Numeric Replies:
		/// ERR_NOORIGIN    ERR_NOSUCHSERVER
		///
		/// Examples:
		/// PING tolsun.oulu.fi
		/// ; Command to send a PING message to server
		///
		/// PING WiZ tolsun.oulu.fi
		/// ; Command from WiZ to send a PING message to server "tolsun.oulu.fi"
		///
		/// PING :irc.funet.fi
		/// ; Ping message sent by server "irc.funet.fi"
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class ping_request : public request
		{
		public:
			static const std::string COMMAND;

			ping_request(const std::initializer_list<std::string> && servers)
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

		const std::string ping_request::COMMAND("PING");
	}
}

#endif