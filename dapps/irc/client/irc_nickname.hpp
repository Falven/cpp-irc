#ifndef IRC_NICKNAME_H
#define IRC_NICKNAME_H

#include <string>
#include <regex>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Each user is distinguished from other users by a unique nickname having a
/// maximum length of nine(9) characters. See the protocol grammar
/// rules(section 2.3.1) for what may and may not be used in a nickname.
///
/// While the maximum length is limited to nine characters, clients SHOULD
/// accept longer strings as they may become used in future evolutions of the
/// protocol. https://tools.ietf.org/html/rfc2812 TODO support unicode. TODO
/// channel types https://tools.ietf.org/html/rfc2812#page-5.
/// </summary>
///
/// <remarks>   Francisco, 4/20/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_nickname
{
public:

    typedef std::string::size_type size_type;

    ///////////////////////////////////////////////////////////////////////////
    /// <summary>
    /// Maximum number of characters that comprises a nickname. Note: this is not
    /// enforced by an irc_nickname as the limit varies by server implementation.
    /// https://tools.ietf.org/html/rfc2812#section-1.2.1.
    /// </summary>
    ///////////////////////////////////////////////////////////////////////////
    static const size_type MAX_LENGTH = 9u;

    irc_nickname(const std::string & name)
        : nickname_(name)
    {
        if (!irc_nickname::is_valid(name))
            throw std::invalid_argument("The provided name does not "
            "conform to irc nickname requirements.");
    };

    static bool is_valid(const std::string & nickname)
    {
        return std::regex_match(nickname, nickname_regex_);
    }

    const std::string str() const
    {
        return nickname_;
    }

private:

    /// <summary> Regex used to validate proper nickname input. </summary>
    static const std::regex nickname_regex_;

    /// <summary> The nickname string. </summary>
    const std::string nickname_;
};

// [[A-Za-z][\x5B-\x60\x7B-\x7D]] {0,8}
// nickname   =  ( letter / special ) *8( letter / digit / special / "-" )
// letter     =  %x41-5A / %x61-7A       ; A-Z / a-z
// special    =  %x5B-60 / %x7B-7D; "[", "]", "\", "`", "_", "^", "{", "|", "}"
// digit      =  %x30-39                 ; 0-9
// static members must be defined in one translation unit to fulfil the one definition rule.
// otherwise such members would be defined in each translation unit that includes the header file.
// Each prefix characterizes a different channel type.  The definition
// of the channel types is not relevant to the client - server protocol
// and thus it is beyond the scope of this document.More details can
// be found in "Internet Relay Chat: Channel Management"[IRC - CHAN].
//
// TODO Because of IRC's Scandinavian origin, the characters {}|^ are
// considered to be the lower case equivalents of the characters []\~,
// respectively.This is a critical issue when determining the
// equivalence of two nicknames or channel names.
const std::regex irc_nickname::nickname_regex_(R"([A-Za-z\x5B-\x60\x7B-\x7D][A-Za-z\x5B-\x60\x7B-\x7D0-9\-]*)");

#endif IRC_NICKNAME_H
