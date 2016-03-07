#include <iostream>
#include <exception>
#include <regex>
#include <cassert>

#include "dapps/irc/regex_definitions.hpp"

int main(int argc, const char * argv [])
{
	try
	{
		const std::regex special(dapps::regex::special);
		assert(std::regex_match("[", special));
		assert(std::regex_match("]", special));
		assert(std::regex_match("\\", special));
		assert(std::regex_match("`", special));
		assert(std::regex_match("_", special));
		assert(std::regex_match("^", special));
		assert(std::regex_match("{", special));
		assert(std::regex_match("|", special));
		assert(std::regex_match("}", special));
		assert(!std::regex_match("a", special));

		const std::regex digit(dapps::regex::digit);
		assert(std::regex_match("0", digit));
		assert(std::regex_match("1", digit));
		assert(std::regex_match("2", digit));
		assert(std::regex_match("3", digit));
		assert(std::regex_match("4", digit));
		assert(std::regex_match("5", digit));
		assert(std::regex_match("6", digit));
		assert(std::regex_match("7", digit));
		assert(std::regex_match("8", digit));
		assert(std::regex_match("9", digit));
		assert(!std::regex_match("10", digit));

		const std::regex hexdigit(dapps::regex::hexdigit);
		assert(std::regex_match("0", hexdigit));
		assert(std::regex_match("1", hexdigit));
		assert(std::regex_match("2", hexdigit));
		assert(std::regex_match("3", hexdigit));
		assert(std::regex_match("4", hexdigit));
		assert(std::regex_match("5", hexdigit));
		assert(std::regex_match("6", hexdigit));
		assert(std::regex_match("7", hexdigit));
		assert(std::regex_match("8", hexdigit));
		assert(std::regex_match("9", hexdigit));
		assert(std::regex_match("A", hexdigit));
		assert(std::regex_match("B", hexdigit));
		assert(std::regex_match("C", hexdigit));
		assert(std::regex_match("D", hexdigit));
		assert(std::regex_match("E", hexdigit));
		assert(std::regex_match("F", hexdigit));
		assert(!std::regex_match("10", hexdigit));

		const std::regex letter(dapps::regex::letter);
		assert(std::regex_match("a", letter));
		assert(std::regex_match("b", letter));
		assert(std::regex_match("c", letter));
		assert(std::regex_match("d", letter));
		assert(std::regex_match("e", letter));
		assert(std::regex_match("f", letter));
		assert(std::regex_match("g", letter));
		assert(std::regex_match("h", letter));
		assert(std::regex_match("i", letter));
		assert(std::regex_match("j", letter));
		assert(std::regex_match("k", letter));
		assert(std::regex_match("l", letter));
		assert(std::regex_match("m", letter));
		assert(std::regex_match("n", letter));
		assert(std::regex_match("o", letter));
		assert(std::regex_match("p", letter));
		assert(std::regex_match("q", letter));
		assert(std::regex_match("r", letter));
		assert(std::regex_match("s", letter));
		assert(std::regex_match("t", letter));
		assert(std::regex_match("u", letter));
		assert(std::regex_match("v", letter));
		assert(std::regex_match("w", letter));
		assert(std::regex_match("x", letter));
		assert(std::regex_match("y", letter));
		assert(std::regex_match("z", letter));
		assert(std::regex_match("A", letter));
		assert(std::regex_match("B", letter));
		assert(std::regex_match("C", letter));
		assert(std::regex_match("D", letter));
		assert(std::regex_match("E", letter));
		assert(std::regex_match("F", letter));
		assert(std::regex_match("G", letter));
		assert(std::regex_match("H", letter));
		assert(std::regex_match("I", letter));
		assert(std::regex_match("J", letter));
		assert(std::regex_match("K", letter));
		assert(std::regex_match("L", letter));
		assert(std::regex_match("M", letter));
		assert(std::regex_match("N", letter));
		assert(std::regex_match("O", letter));
		assert(std::regex_match("P", letter));
		assert(std::regex_match("Q", letter));
		assert(std::regex_match("R", letter));
		assert(std::regex_match("S", letter));
		assert(std::regex_match("T", letter));
		assert(std::regex_match("U", letter));
		assert(std::regex_match("V", letter));
		assert(std::regex_match("W", letter));
		assert(std::regex_match("X", letter));
		assert(std::regex_match("Y", letter));
		assert(std::regex_match("Z", letter));
		assert(!std::regex_match("0", letter));

		const std::regex key(dapps::regex::key);
		assert(!std::regex_match(" ", key));
		assert(!std::regex_match("\t", key));

		const std::regex user(dapps::regex::user);
		assert(!std::regex_match(" ", user));
		assert(!std::regex_match("@", user));

		const std::regex channelid(dapps::regex::channelid);
		assert(std::regex_match("ABCDE", channelid));
		assert(std::regex_match("12345", channelid));

		const std::regex chanstring(dapps::regex::chanstring);
		assert(!std::regex_match(" ", chanstring));
		assert(!std::regex_match(",", chanstring));
		assert(!std::regex_match(":", chanstring));

		//const std::regex targetmask(dapps::regex::targetmask);

		const std::regex nickname(dapps::regex::nickname);
		assert(!std::regex_match("falven2000", nickname));
		assert(!std::regex_match("!falven", nickname));
		assert(std::regex_match("falven", nickname));

		const std::regex ip4addr(dapps::regex::ip4addr);
		assert(std::regex_match("192.168.1.254", ip4addr));
		assert(std::regex_match("0.0.0.0", ip4addr));
		assert(!std::regex_match("9999.999.99.9", ip4addr));

		const std::regex ip6addr(dapps::regex::ip6addr);
		assert(std::regex_match("2001:0DB8:0A0B:12F0:0000:0000:0000:0001", ip6addr));
		assert(!std::regex_match("2001:0DB8:0A0B:12F0:0000:0000:0000", ip6addr));

		const std::regex hostaddr(dapps::regex::hostaddr);
		assert(std::regex_match("2001:0DB8:0A0B:12F0:0000:0000:0000:0001", hostaddr));
		assert(!std::regex_match("2001:0DB8:0A0B:12F0:0000:0000:0000", hostaddr));
		assert(std::regex_match("192.168.1.254", hostaddr));
		assert(!std::regex_match("9999.999.99.9", hostaddr));

		const std::regex shortname(dapps::regex::shortname);
		assert(std::regex_match("irc", shortname));
		assert(std::regex_match("hinoto", shortname));
		assert(std::regex_match("dairc", shortname));
		assert(!std::regex_match("dairc.net", shortname));

		const std::regex hostname(dapps::regex::hostname);
		assert(std::regex_match("irc.hinoto.dairc.net", hostname));
		assert(std::regex_match("hinoto.dairc.net", hostname));

		const std::regex host(dapps::regex::host);
		assert(std::regex_match("irc.hinoto.dairc.net", host));
		assert(std::regex_match("hinoto.dairc.net", host));
		assert(std::regex_match("192.168.1.254", host));
		assert(std::regex_match("2001:0DB8:0A0B:12F0:0000:0000:0000:0001", host));
		
		const std::regex servername(dapps::regex::servername);
		assert(std::regex_match("irc.hinoto.dairc.net", servername));
		assert(std::regex_match("hinoto.dairc.net", servername));
		assert(std::regex_match("192.168.1.254", servername));
		assert(std::regex_match("2001:0DB8:0A0B:12F0:0000:0000:0000:0001", servername));

		const std::regex channel(dapps::regex::channel);
		assert(std::regex_match("#channelname", channel));

		const std::regex SPACE(dapps::regex::SPACE);
		assert(std::regex_match(" ", SPACE));
		assert(!std::regex_match("\t", SPACE));

		const std::regex crlf(dapps::regex::crlf);
		assert(std::regex_match("\r\n", crlf));
		assert(!std::regex_match("\r\t", crlf));

		const std::regex nospcrlfcl(dapps::regex::nospcrlfcl);
		assert(!std::regex_match(" ", nospcrlfcl));
		assert(!std::regex_match(":", nospcrlfcl));





		std::cin >> std::string();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}