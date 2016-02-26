#include <boost\asio.hpp>
#include <iostream>

#include "irc\client.hpp"
#include "irc\nickname.hpp"
#include "irc\username.hpp"
#include "irc\modes.hpp"

int main(int argc, const char * argv[])
{
	try
	{
	    boost::asio::io_service io_service;
	    boost::asio::ip::tcp::resolver resolver(io_service);
	    boost::asio::ip::tcp::resolver::query query("irc.twitch.tv", "6667");
	    boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

	    dapps::irc::username user(dapps::irc::nickname("ddtMaximilian"), "");
		dapps::irc::client client(io_service, iterator, "oauth:uwsugc3p0du632si3rmk4jcof0eh5e", user);

	    io_service.run();
	}
	catch (std::exception & e)
	{
	    std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}