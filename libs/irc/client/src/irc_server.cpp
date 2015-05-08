#include "dapps/irc/client/irc_server.hpp"

// servername =  hostname
// hostname   =  shortname *( "." shortname )
// shortname  =  ( letter / digit ) *( letter / digit / "-" ) *(letter / digit)
// letter     =  %x41-5A / %x61-7A       ; A-Z / a-z
// digit      =  %x30-39                 ; 0-9
// static members must be defined in one translation unit to fulfil the one definition rule.
// otherwise such members would be defined in each translation unit that includes the header file.
const std::regex irc_server::servername_regex_(R"([A-Za-z\x5B-\x60\x7B-\x7D][A-Za-z\x5B-\x60\x7B-\x7D0-9\-]*)");