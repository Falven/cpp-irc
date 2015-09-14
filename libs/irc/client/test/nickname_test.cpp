#include <iostream>
#include <string>
#include <cassert>

#include "dapps/irc/client/irc_nickname.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char * argv[])
{
    string name("!falven2000");
    assert(!irc_nickname::is_valid(name));
    irc_nickname nick("falven2000");
	return 0;
}