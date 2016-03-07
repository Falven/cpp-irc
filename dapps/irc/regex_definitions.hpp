#ifndef REGEX_DEFINITIONS_HPP
#define REGEX_DEFINITIONS_HPP

#include <string>

namespace dapps
{
	namespace regex
	{
		// special    =  %x5B-60 / %x7B-7D
		// "(?:[[-`{-}])"
		static const std::string special("(?:[\x5B-\x60\x7B-\x7D])");

		// digit      =  %x30-39                 ; 0-9
		// "(?:[0-9])"
		static const std::string digit("(?:[\x30-\x39])");

		// hexdigit = digit / "A" / "B" / "C" / "D" / "E" / "F"
		// "(?:(?:[0-9])|[ABCDEF])"
		static const std::string hexdigit("(?:" + digit + "|[ABCDEF])");

		// letter     =  %x41-5A / %x61-7A       ; A-Z / a-z
		// "(?:[A-Za-z])"
		static const std::string letter("(?:[\x41-\x5A\x61-\x7A])");

		// key        =  1*23( %x01-05 / %x07-08 / %x0C / %x0E-1F / %x21-7F )
		//                  ; any 7 - bit US_ASCII character,
		//					  ; except NUL, CR, LF, FF, h / v TABs, and " "
		// "(?:[\x1-\x5\a-\b\f\xe-\x1f!-]{1,23})"
		static const std::string key("(?:[\x01-\x05\x07-\x08\x0C\x0E-\x1F\x21-\x7F]{1,23})");

		// user = 1 * (%x01 - 09 / %x0B - 0C / %x0E - 1F / %x21 - 3F / %x41 - FF)
		// ; any octet except NUL, CR, LF, " " and "@"
		// "(?:[\x1-\t\v-\f\xe-\x1f!-?A-ÿ]+)"
		static const std::string user("(?:[\x01-\x09\x0B-\x0C\x0E-\x1F\x21-\x3F\x41-\xFF]+)");

		// channelid  = 5( %x41-5A / digit )   ; 5( A-Z / 0-9 )
		// "(?:(?:[A-Z]|(?:[0-9])){5})"
		static const std::string channelid("(?:(?:[\x41-\x5A]|" + digit + "){5})");

		// chanstring =  %x01-07 / %x08-09 / %x0B-0C / %x0E-1F / %x21-2B
		// chanstring = / %x2D - 39 / %x3B - FF
		// ; any octet except NUL, BELL, CR, LF, " ", "," and ":"
		// "(?:[\x1-\a\b-\t\v-\f\xe-\x1f!-+--9;-ÿ])"
		static const std::string chanstring("(?:[\x01-\x07\x08-\x09\x0B-\x0C\x0E-\x1F\x21-\x2B\x2D-\x39\x3B-\xFF])");

		// targetmask =  ( "$" / "#" ) mask
		//static const std::string targetmask("(?:[$#]|" + mask + ")");

		// nickname   =  ( letter / special ) *8( letter / digit / special / "-" )
		// "(?:(?:(?:[A-Za-z])|(?:[[-`{-}]))(?:(?:[A-Za-z])|(?:[0-9])|(?:[[-`{-}])|-){0,8})"
		static const std::string nickname("(?:(?:" + letter + "|" + special + ")(?:" + letter + "|" + digit + "|" + special + "|-" + "){0,8})");

		// ip4addr = 1 * 3digit "." 1 * 3digit "." 1 * 3digit "." 1 * 3digit
		// "(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})"
		static const std::string ip4addr("(?:" + digit + "{1,3}." + digit + "{1,3}." + digit + "{1,3}." + digit + "{1,3})");

		// ip6addr = 1 * hexdigit 7(":" 1 * hexdigit)
		// ip6addr = / "0:0:0:0:0:" ("0" / "FFFF") ":" ip4addr
		// "(?:(?:(?:[0-9])|[ABCDEF])+(?::(?:(?:[0-9])|[ABCDEF])+){7}|(?:0:0:0:0:0:(?:0|FFFF):(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})))"
		static const std::string ip6addr("(?:" + hexdigit + "+(?::" + hexdigit + "+){7}|(?:0:0:0:0:0:(?:0|FFFF):" + ip4addr + "))");

		// hostaddr = ip4addr / ip6addr
		// "(?:(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})|(?:(?:(?:[0-9])|[ABCDEF])+(?::(?:(?:[0-9])|[ABCDEF])+){7}|(?:0:0:0:0:0:(?:0|FFFF):(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:...
		static const std::string hostaddr("(?:" + ip4addr + "|" + ip6addr + ")");

		// shortname = (letter / digit) *(letter / digit / "-") *(letter / digit)
		// "(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9])))"
		static const std::string shortname("(?:(?:" + letter + "|" + digit + ")(?:" + letter + "|" + digit + "|-" + ")*(?:" + letter + "|" + digit + ")*)");

		// hostname = shortname *("." shortname)
		// "(?:(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9]))*)(?:.(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9]))*))*)"
		static const std::string hostname("(?:" + shortname + "(?:." + shortname + ")*)");

		// host = hostname / hostaddr
		// "(?:(?:(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9]))*)(?:.(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9]))*))*)|(?:(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})|(?:(?:(?:[0-9])|[ABCDEF])+(?::(?:(?:[0-9])|[ABCDEF])+){7}|(?:0:0:0:0:0:(?:0|FFFF):(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})))))"
		static const std::string host("(?:" + hostname + "|" + hostaddr + ")");

		// servername = hostname
		// "(?:(?:(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9]))*)(?:.(?:(?:(?:[A-Za-z])|(?:[0-9]))(?:(?:[A-Za-z])|(?:[0-9])|-)*(?:(?:[A-Za-z])|(?:[0-9]))*))*)|(?:(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})|(?:(?:(?:[0-9])|[ABCDEF])+(?::(?:(?:[0-9])|[ABCDEF])+){7}|(?:0:0:0:0:0:(?:0|FFFF):(?:(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3}.(?:[0-9]){1,3})))))"
		static const std::string servername(hostname);

		// channel    =  ( "#" / "+" / ( "!" channelid ) / "&" ) chanstring [":" chanstring]
		// "(?:(?:[#+&]|(?:!(?:(?:[A-Z]|(?:[0-9])){5})))(?:[\x1-\a\b-\t\v-\f\xe-\x1f!-+--9;-ÿ])(?::(?:[\x1-\a\b-\t\v-\f\xe-\x1f!-+--9;-ÿ]))?)"
		static const std::string channel("(?:(?:[#+&]|(?:!" + channelid + "))" + chanstring + "(?::" + chanstring + ")?)");

		// msgto =  channel / ( user [ "%" host ] "@" servername )
		// msgto = / (user "%" host) / targetmask
		// msgto = / nickname / (nickname "!" user "@" host)
		static const std::string msgto("");

		// msgtarget  =  msgto *( "," msgto )
		static const std::string msgtarget("");

		// target = nickname / server
		// 
		//static const std::string target("(?:" + nickname + "|" + server + ")");

		// crlf = %x0D %x0A; "carriage return" "linefeed"
		// "(?:\r\n)"
		static const std::string crlf("(?:\x0D\x0A)");

		// SPACE = %x20
		//  "(?:[ ])"
		static const std::string SPACE("(?:[\x20])");

		// nospcrlfcl = %x01 - 09 / %x0B - 0C / %x0E - 1F / %x21 - 39 / %x3B - FF ; any octet except NUL, CR, LF, " " and ":"
		// "(?:[\x1-\t\v-\f\xe-\x1f!-9;-ÿ])"
		static const std::string nospcrlfcl("(?:[\x01-\x09\x0B-\x0C\x0E-\x1F\x21-\x39\x3B-\xFF])");

		// trailing = *(":" / " " / nospcrlfcl)
		// (?::| |(?:\x1-\t\v-\f\xe-\x1f!-9;-ÿ))*
		static const std::string trailing("(?::| |(?:" + nospcrlfcl + "))*");

		// middle = nospcrlfcl *(":" / nospcrlfcl)
		// (?:\x1-\t\v-\f\xe-\x1f!-9;-ÿ)(?:(?::)|(?:\x1-\t\v-\f\xe-\x1f!-9;-ÿ))*
		static const std::string middle("(?:" + nospcrlfcl + ")(?:(?::)|(?:" + nospcrlfcl + "))*");

		// params = *14(SPACE middle)[SPACE ":" trailing] / 14(SPACE middle)[SPACE[":"] trailing]
		// (?:(?:(?: )(?:(?:-	--!-9;-ÿ)(?:(?::)|(?:-	--!-9;-ÿ))*)){0,14}(?:(?: ):(?:(?::| |(?:-	--!-9;-ÿ))*))?)|(?:(?:(?: )(?:(?:-	--!-9;-ÿ)(?:(?::)|(?:-	--!-9;-ÿ))*)){14}(?:(?: ):?(?:(?::| |(?:-	--!-9;-ÿ))*))?
		static const std::string params("(?:(?:(?:" + SPACE + ")(?:" + middle + ")){0,14}(?:(?:" + SPACE + "):(?:" + trailing + "))?)|(?:(?:(?:" + SPACE + ")(?:" + middle + ")){14}(?:(?:" + SPACE + "):?(?:" + trailing + "))?");

		// command = 1 * letter / 3digit
		// [A-Za-z]+|[0-9]{3}
		static const std::string command("[" + letter + "]+|[" + digit + "]{3}");

		// prefix = servername / (nickname[["!" user] "@" host])
		static const std::string prefix("(?:" + servername + ")|(?:" + nickname + "(?:" + "(?:" + "!" + user + ")?" + "@" + host + ")?))");

		// message    =  [ ":" prefix SPACE ] command [ params ] crlf
		// (?::(?:(?:[A-Za-z0-9][A-Za-z0-9-]*[A-Za-z0-9]*(?:.[A-Za-z0-9][A-Za-z0-9-]*[A-Za-z0-9]*)*)|(?:[A-Za-z[-`{-}][A-Za-z0-9[-`{-}-]{0,8}(?:(?:![-	--!-?A-ÿ]+)?@(?:[A-Za-z0-9][A-Za-z0-9-]*[A-Za-z0-9]*(?:.[A-Za-z0-9][A-Za-z0-9-]*[A-Za-z0-9]*)*)|((?:[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3})|(?:[0-9ABCDEF]+(?::[0-9ABCDEF]+){7}))])?)))(?: ))?(:?[A-Za-z]+|[0-9]{3})(?:(?:(?:(?: )(?:(?:-	--!-9;-ÿ)(?:(?::)|(?:-	--!-9;-ÿ))*)){0,14}(?:(?: ):(?:(?::| |(?:-	--!-9;-ÿ))*))?)|(?:(?:(?: )(?:(?:-	--!-9;-ÿ)(?:(?::)|(?:-	--!-9;-ÿ))*)){14}(?:(?: ):?(?:(?::| |(?:-	--!-9;-ÿ))*))?)?(?:
		// )
		static const std::string message("(?::(?:" + prefix + ")(?:" + SPACE + "))?" + "(:?" + command + ")(?:" + params + ")?" + "(?:" + crlf + ")");
	}
}

#endif