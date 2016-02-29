#include <iostream>
#include <exception>
#include <boost/asio.hpp>

#include "dapps/irc/client.hpp"
#include "dapps/irc/nickname.hpp"
#include "dapps/irc/user_mode.hpp"
#include "dapps/irc/messages/pass_request.hpp"
#include "dapps/irc/messages/nick_request.hpp"
#include "dapps/irc/messages/user_request.hpp"
#include "dapps/irc/messages/join_request.hpp"

int main(int argc, const char * argv[])
{
	try
	{
		boost::asio::io_service io_service;

		boost::asio::ip::tcp::resolver resolver(io_service);
		auto endpoint_iterator = resolver.resolve({ "irc.deltaanime.net", "6667" });
		dapps::irc::client client(io_service, endpoint_iterator);

		client.connect();
		client.login("PASS \r\n", "NICK falven2000\r\n", "USER falven2000 8 * :falven2000\r\n");

		std::thread io_thread([&io_service]() { io_service.run(); });

		std::string in;
		std::cin >> in;

		client.close();
		io_thread.join();
	}
	catch (std::exception & e)
	{
	    std::cerr << "Exception: " << e.what() << "\n";
	}

    return 0;
}