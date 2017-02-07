#include <iostream>
#include <exception>
#include <thread>
#include <boost/asio.hpp>

#include "dapps/irc/connection.hpp"

int main(int argc, const char * argv [])
{
	try
	{
		boost::asio::io_service io_service;
		// Prevent the io service's run loop from ending before async calls.
		boost::asio::io_service::work work(io_service);
		// Run io service event processing loop on another thread.
		std::thread io_thread([&io_service]() { io_service.run(); });

		dapps::irc::connection con(io_service);

		std::string domain("irc.deltaanime.net");
		std::string port("6667");

		std::cout << "Connecting to: " << domain << ":" << port << std::endl;

		con.establish_async(domain, port,
			[&con](const boost::asio::ip::tcp::resolver::iterator & iterator)
		{
			std::cout << "Connected to: " << iterator->host_name() << std::endl;

			auto sent_callback = [](const std::string & message)
			{
				std::cout << "Sent: " << message << std::endl;
			};
			con.write_async("PASS \r\n", sent_callback);
			con.write_async("NICK dapps\r\n", sent_callback);
			con.write_async("USER dapps 8 * :dapps\r\n", sent_callback);

			con.read_async([](const std::string & read)
			{
				std::cout << "Received: " << read << std::endl;
			});
		});

		std::cin >> std::string();

		con.close();
		io_thread.join();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}