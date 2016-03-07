#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <thread>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "connection.hpp"

namespace dapps
{
	namespace irc
	{
		class client
		{
		public:
			client(const std::string & host, const std::string & port)
				: io_service_(),
				work_(io_service_),
				io_thread_(std::bind(&client::handle_io_thread, this)),
				con_(io_service_)
			{
				con_.establish_async(host, port,
					[](const boost::asio::ip::tcp::resolver::iterator & iterator)
				{
					std::cout << "Connected to: " << iterator->host_name() << std::endl;
				});
				con_.read_async(boost::bind(&client::handle_read, this, _1));
			}

			void login()
			{
				auto sent_callback = [](const std::string & message)
				{
					std::cout << "Sent: " << message << std::endl;
				};
				con_.write_async("PASS \r\n", sent_callback);
				con_.write_async("NICK dapps\r\n", sent_callback);
				con_.write_async("USER dapps 8 * :dapps\r\n", sent_callback);
			}

			virtual ~client()
			{
				con_.close();
				io_thread_.join();
			}

		private:
			boost::asio::io_service io_service_;
			boost::asio::io_service::work work_;
			std::thread io_thread_;
			connection con_;

			void handle_io_thread()
			{
				boost::system::error_code ec;
				std::size_t handlers_executed = io_service_.run(ec);
			}

			void handle_read(const std::string & read)
			{
				
			}

			void parse_reply(const std::string & reply)
			{

			}

			void parse_message(const std::string & message)
			{

			}
		};
	}
}

#endif