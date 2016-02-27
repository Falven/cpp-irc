#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include <string>
#include <vector>
#include <deque>
#include <thread>
#include <boost/asio.hpp>
#include <sstream>

#include "irc_exception.hpp"
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
		class connection
		{
		public:
			connection(const std::string & server, const std::string & port)
				: io_service_(),
				query_(server, port),
				socket_(io_service_),
				io_thread_([this]() { this->io_service_.run(); }),
				request_queue_(),
				reply_queue_(),
				request_buffer_(),
				reply_buffer_()
			{
			}

			virtual ~connection()
			{
				socket_.close();
				io_service_.stop();
				io_thread_.join();
			}

			///////////////////////////////////////////////////////////////////////////
			/// <summary>
			/// The commands described here are used to register a connection with an IRC
			/// server as a user as well as to correctly disconnect.
			///
			/// A "PASS" command is not required for a client connection to be registered,
			/// but it MUST precede the latter of the NICK / USER combination(for a user
			/// connection) or the SERVICE command(for a service connection).The
			/// RECOMMENDED order for a client to register is as follows :
			///
			///                 1. Pass message
			/// 2. Nick message                 2. Service message
			/// 3. User message
			///
			/// Upon success, the client will receive an RPL_WELCOME(for users) or
			/// RPL_YOURESERVICE(for services) message indicating that the connection is
			/// now registered and known the to the entire IRC network. The reply message
			/// MUST contain the full client identifier upon which it was registered.
			/// </summary>
			///
			/// <remarks>   Francisco, 5/8/2015. </remarks>
			///
			/// <param name="pass"> The pass to connect. Optional. </param>
			///
			/// <returns>   An reply. </returns>
			///////////////////////////////////////////////////////////////////////////
			virtual void connect()
			{
				boost::asio::ip::tcp::resolver resolver(io_service_);
				resolver.async_resolve(query_,
					[this](const boost::system::error_code & ec, boost::asio::ip::tcp::resolver::iterator itr)
				{
					if (ec)
					{
						throw irc_exception("Endpoint resolution failed", ec);
					}
					boost::asio::async_connect(socket_, itr,
						[this](boost::system::error_code ec, boost::asio::ip::tcp::resolver::iterator)
					{
						if (ec)
						{
							throw irc_exception("Connect attempt failed", ec);
						}
					});
				});
			}
		protected:
			std::deque<request> request_queue_;
			std::deque<reply> reply_queue_;

		private:
			std::thread io_thread_;
			boost::asio::io_service io_service_;
			boost::asio::ip::tcp::resolver::query query_;
			boost::asio::ip::tcp::socket socket_;

			boost::asio::streambuf reply_buffer_;
			boost::asio::streambuf request_buffer_;

			void chain_request(const message & msg)
			{

				boost::asio::async_write(socket_, boost::asio::buffer(msg.str(), msg.str().length()),
					[this](const boost::system::error_code & ec, std::size_t)
				{
					if (ec)
					{
						throw irc_exception("Send message failed", ec);
					}
				});
			}

			void chain_reply()
			{
				boost::asio::async_read_until(socket_, reply_buffer_, message::TERMINATION,
					[this](const boost::system::error_code & ec, std::size_t)
				{
					if (ec)
					{
						throw irc_exception("Receive reply failed", ec);
					}
					const std::string repl_str((std::istreambuf_iterator<char>(&reply_buffer_)), std::istreambuf_iterator<char>());
					reply_queue_.push_front(repl_str);
					chain_reply();
				});
			}
		};
	}
}

#endif