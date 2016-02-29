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
#include "messages/ping_request.hpp"

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
				endpoint_iterator_(endpoint_iterator),
				message_queue_(),
				reply_queue_(),
				reply_buffer_()
			{
				std::cout << "Socket initialized." << std::endl;
			}

			void close()
			{
				io_service_.post([this]() { socket_.close(); });
			}

			void connect()
			{
				do_connect(endpoint_iterator_);
			}

			void login(const std::string & password, const std::string & nick, const std::string & user)
			{
				send(password);
				send(nick);
				send(user);
			}

			void send(const std::string & message)
			{
				io_service_.post([this, message]()
				{
					bool messages_queued = !message_queue_.empty();
					message_queue_.push(message);
					if (!messages_queued)
					{
						do_send();
					}
				});
			}

		private:
			boost::asio::io_service & io_service_;
			boost::asio::ip::tcp::socket socket_;
			boost::asio::ip::tcp::resolver::iterator endpoint_iterator_;
			std::queue<std::string> message_queue_;
			std::queue<std::string> reply_queue_;
			boost::asio::streambuf reply_buffer_;

			void do_error(const std::string & message, const boost::system::error_code & error)
			{
				socket_.close();
				throw irc_exception(message, error);
			}

			void do_connect(boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
			{
				boost::asio::async_connect(socket_, endpoint_iterator,
					[this](const boost::system::error_code & error, boost::asio::ip::tcp::resolver::iterator iterator)
				{
					switch (error.value())
					{
						case boost::system::errc::success:
						{
							std::cout << "Connected to: " << iterator->host_name() << std::endl;
							do_receive();
							do_send();
							break;
						}
						default:
						{
							do_error("Connect attempt failed", error);
						}
					}
				});
			}

			void do_receive()
			{
				boost::asio::async_read_until(socket_, reply_buffer_, message::TERMINATION,
					[this](const boost::system::error_code & error, std::size_t bytes_transferred)
				{
					switch (error.value())
					{
						case boost::system::errc::success:
						{
							std::string read((std::istreambuf_iterator<char>(&reply_buffer_)), std::istreambuf_iterator<char>());
							std::cout << "Received: " << read << std::endl;
							reply_queue_.push(read);
							do_receive();
							break;
						}
						case 10057:
						{
							return;
						}
						default:
						{
							do_error("Receive reply failed", error);
						}
					}
				});
			}

			void do_send()
			{
				std::string next = message_queue_.front();
				boost::asio::async_write(socket_, boost::asio::buffer(next.c_str(), next.size()),
					[this](const boost::system::error_code & error, std::size_t bytes_transferred)
				{
					switch (error.value())
					{
						case boost::system::errc::success:
						{
							std::cout << "Sent: " << message_queue_.front() << std::endl;
							message_queue_.pop();
							if (!message_queue_.empty())
							{
								do_send();
							}
							break;
						}
						case 10057:
						{
							return;
						}
						default:
						{
							do_error("Send request failed", error);
						}
					}
				});
			}
		};
	}
}

#endif