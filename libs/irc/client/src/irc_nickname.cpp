#include "dapps/irc/client/irc_nickname.hpp"

// [[A-Za-z][\x5B-\x60\x7B-\x7D]] {0,8}
// nickname   =  ( letter / special ) *8( letter / digit / special / "-" )
// letter     =  %x41-5A / %x61-7A       ; A-Z / a-z
// special    =  %x5B-60 / %x7B-7D; "[", "]", "\", "`", "_", "^", "{", "|", "}"
// digit      =  %x30-39                 ; 0-9
// static members must be defined in one translation unit to fulfil the one definition rule.
// otherwise such members would be defined in each translation unit that includes the header file.
const std::regex irc_nickname::nickname_regex_(R"([A-Za-z\x5B-\x60\x7B-\x7D][A-Za-z\x5B-\x60\x7B-\x7D0-9\-]*)");