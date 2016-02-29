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

		std::thread io_thread([&io_service]() { io_service.run(); });

		client.send(dapps::irc::pass_request(""));
		client.send(dapps::irc::nick_request(dapps::irc::nickname("falven2000")));
		client.send(dapps::irc::user_request("falven2000", dapps::irc::user_mode(false, false), "somerealname"));
		client.send(dapps::irc::join_request("#dapps"));

		char line[5];
		std::cin.getline(line, 5);

		client.close();
		io_thread.join();
	}
	catch (std::exception & e)
	{
	    std::cerr << "Exception: " << e.what() << "\n";
	}

    return 0;
}