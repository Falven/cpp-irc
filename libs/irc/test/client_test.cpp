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
		dapps::irc::nickname nick("ddtMaximilian");
	    dapps::irc::username user(nick, "");
		dapps::irc::client client("irc.twitch.tv", "6667");

		client.message_password("somepass");
		client.message_nickname(dapps::irc::nickname("ddtMaximilian"));
		client.message_user(user);
		client.connect();
	}
	catch (std::exception & e)
	{
	    std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}