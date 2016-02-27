#include <iostream>
#include <exception>
#include <boost/asio.hpp>

#include "dapps/irc/client.hpp"
#include "dapps/irc/nickname.hpp"
#include "dapps/irc/username.hpp"
#include "dapps/irc/user_mode.hpp"
#include "dapps/irc/messages/pass_request.hpp"
#include "dapps/irc/messages/nick_request.hpp"
#include "dapps/irc/messages/user_request.hpp"

int main(int argc, const char * argv[])
{
	try
	{
		dapps::irc::client client("verne.freenode.net", "6667");
		client.send(dapps::irc::pass_request("oauth:uvger1uozh0lo1ou477kq0wkr067vd"));
		dapps::irc::nickname nick("falven2000");
		client.send(dapps::irc::nick_request(nick));
		client.send(dapps::irc::user_request(dapps::irc::username(nick, "Frank."), dapps::irc::user_mode(false, false)));
		client.connect();
	}
	catch (std::exception & e)
	{
	    std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}