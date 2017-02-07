#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>
#include <queue>
#include <functional>
#include <tuple>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "irc_exception.hpp"
#include "message.hpp"

namespace dapps
{
	namespace irc
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// 			Defines methods to manage a full-duplex connection to an irc server.
		/// 			The connection asynchronously loops, checking for messages from the server,
		/// 			and provides a user the ability to asynchronously write messages to such server.
		/// </summary>
		///
		/// <remarks>	Falven, 2/26/2016. </remarks>
		////////////////////////////////////////////////////////////////////////////////////////////////////
		class connection
		{
		public:
			connection(boost::asio::io_service & io_service)
				: io_service_(io_service),
				resolver_(io_service),
				socket_(io_service),
				message_queue_(),
				reply_buffer_(),
				read_handler_(),
				resolved_(false),
				connected_(false)
			{
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Resolves and establishes the connection to the provided endpoint. </summary>
			///
			/// <remarks>	Falven, 3/1/2016. </remarks>
			///
			/// <param name="host">	The host to establish the connecttion to. </param>
			/// <param name="port">	The port to establish the connecttion to. </param>
			/// <param name="handler">	A handler to invoke when the connection has been established. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////
			void establish_async(const std::string & host,
				const std::string & port,
				const std::function<void(const boost::asio::ip::tcp::resolver::iterator & iterator)> & handler = {})
			{
				resolver_.async_resolve({ host, port },
					[this, handler](const boost::system::error_code & error, boost::asio::ip::tcp::resolver::iterator iterator)
				{
					switch (error.value())
					{
						case boost::system::errc::success:
						{
							resolved_ = true;
							do_connect(iterator, handler);
							break;
						}
						default:
						{
							do_error("Resolve attempt failed", error);
						}
					}
				});
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Closes the connection. </summary>
			///
			/// <remarks>	Falven, 3/1/2016. </remarks>
			////////////////////////////////////////////////////////////////////////////////////////////////////
			void close()
			{
				io_service_.post([this]() { socket_.close(); });
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Set a handler to execute when reading asynchronous messages from the server. </summary>
			///
			/// <remarks>	Falven, 3/1/2016. </remarks>
			///
			/// <param name="handler">	The handler to invoke when a message has been read. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////
			void read_async(const std::function<void(const std::string &)> & handler)
			{
				read_handler_ = handler;
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////
			/// <summary>	Asynchronously writes the provided message to the connection. </summary>
			///
			/// <remarks>	Falven, 3/1/2016. </remarks>
			///
			/// <param name="message">	The message to write. </param>
			/// <param name="handler">	A handler to invoke when the message has been written. </param>
			////////////////////////////////////////////////////////////////////////////////////////////////////
			void write_async(const std::string & message,
				const std::function<void(const std::string &)> & handler = {})
			{
				io_service_.post([this, message, handler]()
				{
					bool empty = message_queue_.empty();
					message_queue_.push(std::make_tuple(message, handler));
					if (empty)
					{
						do_write();
					}
				});
			}

		private:
			boost::asio::io_service & io_service_;
			boost::asio::ip::tcp::resolver resolver_;
			boost::asio::ip::tcp::socket socket_;
			std::queue<std::tuple<std::string, std::function<void(const std::string &)>>> message_queue_;
			boost::asio::streambuf reply_buffer_;
			std::function<void(const std::string &)> read_handler_;
			bool resolved_;
			bool connected_;

			void do_error(const std::string & message,
				const boost::system::error_code & error)
			{
				close();
				throw irc_exception(message, error);
			}

			void do_connect(boost::asio::ip::tcp::resolver::iterator endpoint_iterator,
				const std::function<void(const boost::asio::ip::tcp::resolver::iterator & iterator)> & handler = {})
			{
				boost::asio::async_connect(
					socket_,
					endpoint_iterator,
					[this, handler](const boost::system::error_code & error, boost::asio::ip::tcp::resolver::iterator iterator)
				{
					switch (error.value())
					{
						case boost::system::errc::success:
						{
							connected_ = true;

							do_read();

							if (!message_queue_.empty())
							{
								do_write();
							}

							if (handler)
							{
								handler(iterator);
							}
							break;
						}
						default:
						{
							do_error("Connect attempt failed", error);
						}
					}
				});
			}

			void do_read()
			{
				boost::asio::async_read_until(socket_,
					reply_buffer_,
					message::TERMINATION,
					[this](const boost::system::error_code & error, std::size_t)
				{
					switch (error.value())
					{
						case boost::system::errc::success:
						{
							std::string read((std::istreambuf_iterator<char>(&reply_buffer_)),
								std::istreambuf_iterator<char>());
							if (read_handler_)
							{
								read_handler_(read);
							}
							do_read();
							break;
						}
						// In case connection is lost.
	#ifdef _WIN32
							// 10009
						case WSAEBADF:
							// 10057
						case WSAENOTCONN:
	#else
						case boost::system::errc::not_connected:
	#endif
						{
							break;
						}
						default:
						{
							do_error("Receive reply failed", error);
						}
					}
				});
			}

			void do_write()
			{
				if (resolved_ && connected_)
				{
					auto next_msg = std::get<0>(message_queue_.front());
					boost::asio::async_write(socket_,
						boost::asio::buffer(next_msg.c_str(), next_msg.size()),
						[this](const boost::system::error_code & error, std::size_t)
					{
						switch (error.value())
						{
							case boost::system::errc::success:
							{
								auto next = message_queue_.front();
								message_queue_.pop();

								auto next_callback = std::get<1>(next);
								if (next_callback)
								{
									next_callback(std::get<0>(next));
								}

								if (!message_queue_.empty())
								{
									do_write();
								}
								break;
							}
							// In case connection is lost.
#ifdef _WIN32
							// 10009
							case WSAEBADF:
							// 10057
							case WSAENOTCONN:
#else
							case boost::system::errc::not_connected:
#endif
							{
								break;
							}
							default:
							{
								do_error("Send request failed", error);
							}
						}
					});
				}
			}
		};
	}
}

#endif