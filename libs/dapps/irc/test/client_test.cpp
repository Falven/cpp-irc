#include <iostream>
#include <exception>
#include <boost/asio.hpp>

#include "dapps/irc/client.hpp"

int main(int argc, const char * argv [])
{
	try
	{
		dapps::irc::client client("irc.deltaanime.net", "6667");

		client.login();

		std::cin >> std::string();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}