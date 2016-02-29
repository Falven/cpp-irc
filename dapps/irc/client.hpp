#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <thread>
#include <boost/asio.hpp>
#include <sstream>
#include <functional>

#include "irc_exception.hpp"
#include "messages/message.hpp"
#include "messages/request.hpp"
#include "messages/reply.hpp"

namespace dapps
{
	namespace irc
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>	Defines methods to connect and manage a connection to an irc server. </summary>
		///
		/// <remarks>	Falven, 2/26/2016. </remarks>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		class client
		{
		public:
			client(boost::asio::io_service & io_service, boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
				: io_service_(io_service),
				socket_(io_service),
				request_queue_(),
				reply_queue_(),
				reply_buffer_()
			{
				do_connect(endpoint_iterator);
			}

			void close()
			{
				io_service_.post([this]() { socket_.close(); });
			}

			void send(const request & rq)
			{
				io_service_.post([this, &rq]()
				{
					bool request_in_progress = !request_queue_.empty();
					request_queue_.push(rq);
					if (!request_in_progress)
					{
						do_request();
					}
				});
			}

		private:
			boost::asio::io_service & io_service_;
			boost::asio::ip::tcp::socket socket_;
			boost::asio::streambuf reply_buffer_;
			std::queue<request> request_queue_;
			std::queue<std::string> reply_queue_;

			void do_connect(boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
			{
				boost::asio::async_connect(socket_, endpoint_iterator,
					[this](boost::system::error_code ec, boost::asio::ip::tcp::resolver::iterator)
				{
					if (ec)
					{
						throw irc_exception("Connect attempt failed", ec);
					}
					do_receive();
				});
			}

			void do_receive()
			{
				boost::asio::async_read_until(socket_, reply_buffer_, message::TERMINATION,
					[this](const boost::system::error_code & ec, std::size_t)
				{
					if (ec)
					{
						socket_.close();
						throw irc_exception("Receive reply failed", ec);
					}
					std::string rpl = std::string((std::istreambuf_iterator<char>(&reply_buffer_)),
													std::istreambuf_iterator<char>());
					reply_queue_.push(rpl);
					std::cout << rpl << "\n";
					do_receive();
				});
			}

			void do_request()
			{
				std::string next = static_cast<message>(request_queue_.front()).str();
				boost::asio::async_write(socket_, boost::asio::buffer(next, next.length()),
					[this, &next](boost::system::error_code ec, std::string::size_type)
				{
					if (ec)
					{
						socket_.close();
						throw irc_exception("Send request failed", ec);
					}
					request_queue_.pop();
					if (!request_queue_.empty())
					{
						do_request();
					}
				});
			}
		};
	}
}

#endif