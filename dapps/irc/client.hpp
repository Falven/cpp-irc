#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

#include "connection.hpp"
#include "messages/request.hpp"

namespace dapps
{
	namespace irc
	{
		class client : public connection
		{
		public:
			client(const std::string & server, const std::string & port)
				: connection(server, port)
			{
			}

			virtual ~client()
			{
			}

			virtual void send(const request & rq)
			{
				connection::request_queue_.push_back(rq);
			}

		private:
		};
	}
}

#endif