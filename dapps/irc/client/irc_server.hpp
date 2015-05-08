#ifndef IRC_SERVER_H
#define IRC_SERVER_H

#include <string>
#include <regex>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Servers are uniquely identified by their name, which has a maximum
/// length of sixty three(63) characters.See the protocol grammar
/// rules(section 2.3.1) for what may and may not be used in a server
/// name.
/// https://tools.ietf.org/html/rfc2812 TODO support unicode.
/// </summary>
///
/// <remarks>   Francisco, 4/20/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_server
{
public:

    ///////////////////////////////////////////////////////////////////////////
    /// <summary>
    /// Maximum number of characters that comprises a server name. Note: this is not
    /// enforced by an irc_server as the limit varies by implementation.
    /// https://tools.ietf.org/html/rfc2812#section-1.1
    /// </summary>
    ///////////////////////////////////////////////////////////////////////////
    static const unsigned int MAX_LENGTH = 63u;

    irc_server(const std::string & name)
        : servername_(name)
    {
        if (!irc_server::is_valid(name))
            throw std::invalid_argument("The provided name does not "
            "conform to irc server name requirements.");
    };

    static bool is_valid(const std::string & servername)
    {
        return std::regex_match(servername, servername_regex_);
    }

private:

    /// <summary> Regex used to validate proper servername input. </summary> 
    static const std::regex servername_regex_;

    /// <summary> The servername string. </summary>
    const std::string servername_;
};

#endif IRC_SERVER_H