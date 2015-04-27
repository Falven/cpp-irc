#include <string>
#include <boost/spirit/include/classic.hpp>
#include <boost/spirit/include/classic_push_back_actor.hpp>

#include "dapps/irc/client/irc_nickname.hpp"

using std::string;
using boost::spirit::classic::parser;
using boost::spirit::classic::parse;
using boost::spirit::classic::real_p;
using boost::spirit::classic::space_p;

irc_nickname::irc_nickname()
{
	bool b = parse("", real_p >> *(',' >> real_p), space_p).full;
}


irc_nickname::~irc_nickname()
{
}