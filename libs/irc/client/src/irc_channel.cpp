#include <regex>

#include "dapps/irc/client/irc_channel.hpp"

// Channels names are strings (beginning with a '&', '#', '+' or '!'
// character) of length up to fifty(50) characters. Apart from the
// requirement that the first character is either '&', '#', '+' or '!',
// the only restriction on a channel name is that it SHALL NOT contain
// any spaces(' '), a control G(^G or ASCII 7), a comma(',').
// 
// channel    = ( "#" / "+" / ( "!" channelid ) / "&" ) chanstring [":" chanstring]
// channelid  = 5( %x41-5A / digit ) ; 5( A-Z / 0-9 )
// digit      = %x30-39 ; 0-9
// chanstring = %x01-07 / %x08-09 / %x0B-0C / %x0E-1F / %x21-2B
// chanstring = / %x2D - 39 / %x3B - FF ; any octet except NUL, BELL, CR, LF, " ", "," and ":"
// 
// TODO Because of IRC's Scandinavian origin, the characters {}|^ are
// considered to be the lower case equivalents of the characters []\~,
// respectively.This is a critical issue when determining the
// equivalence of two nicknames or channel names.
const std::regex irc_channel::name_regex_(R"(^[&#+]^(![A-Za-z0-9]{5})?[^\s\x07,]:?[\x01-\x07\x08-\x09\x0B-\x0C\x0E-\x1F\x21-\x2B]*)");