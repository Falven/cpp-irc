#ifndef IRC_NICKNAME_H
#define IRC_NICKNAME_H

#include <string>
#include <boost/spirit/include/classic.hpp>

///////////////////////////////////////////////////////////////////////////////
/// <summary>
/// An irc nickname. nickname   =  ( letter / special ) *8( letter /digit /
/// special / "-" )
/// letter		=  %x41-5A / %x61-7A; A-Z / a-z
/// special		=  %x5B-60 / %x7B-7D; "[", "]", "\", "`", "_", "^", "{", "|", "}"
/// digit		=  %x30-39; 0-9.
/// </summary>
///
/// <remarks>	Francisco, 4/20/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_nickname
{
public:

	///////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// Maximum number of characters that comprises a nickname.
	/// https://tools.ietf.org/html/rfc2812#section-1.2.1.
	/// </summary>
	///////////////////////////////////////////////////////////////////////////
	/// <summary>	The maximum length. </summary>
	static const unsigned int MAX_LENGTH = 9;

	irc_nickname();
	~irc_nickname();
};

#endif