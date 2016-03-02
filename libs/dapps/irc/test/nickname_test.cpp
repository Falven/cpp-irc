#include <iostream>
#include <string>
#include <cassert>

#include "dapps/irc/nickname.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int argc, const char * argv [])
{
	string name("!falven2000");
	assert(!dapps::irc::nickname::is_valid(name));
	dapps::irc::nickname nick("falven2000");
	return 0;
}