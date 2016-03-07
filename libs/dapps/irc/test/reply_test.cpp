#include <string>
#include <regex>
#include <iostream>
#include <exception>
#include <boost/asio.hpp>

#include "dapps/irc/replies/reply.hpp"

int main(int argc, const char * argv [])
{
	try
	{
		dapps::irc::reply rpl1(":irc.hinoto.dairc.net 461  PASS : Not enough parameters\r\n");
		dapps::irc::reply rpl2("461  PASS : Not enough parameters\r\n");
		dapps::irc::reply rpl3("461  PASS :Not enough parameters\r\n");
		dapps::irc::reply rpl4("461  PASS\r\n");

		std::cin >> std::string();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}