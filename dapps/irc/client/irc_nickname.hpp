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
/// protocol. https://tools.ietf.org/html/rfc2812 TODO support unicode.
/// </summary>
///
/// <remarks>   Francisco, 4/20/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_nickname
{
public:

    ///////////////////////////////////////////////////////////////////////////
    /// <summary>
    /// Maximum number of characters that comprises a nickname. Note: this is not
    /// enforced by an irc_nickname as the limit varies by server implementation.
    /// https://tools.ietf.org/html/rfc2812#section-1.2.1.
    /// </summary>
    ///////////////////////////////////////////////////////////////////////////
    static const unsigned int MAX_LENGTH = 9u;

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

private:

    /// <summary> Regex used to validate proper nickname input. </summary> 
    static const std::regex nickname_regex_;

    /// <summary> The nickname string. </summary>
    const std::string nickname_;
};

#endif IRC_NICKNAME_H