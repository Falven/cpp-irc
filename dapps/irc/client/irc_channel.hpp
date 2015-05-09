#ifndef IRC_CHANNEL_H
#define IRC_CHANNEL_H

#include <string>
#include <regex>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////
/// <summary>
/// Channels names are strings (beginning with a '&amp;', '#', '+' or '!'
/// character) of length up to fifty(50) characters.Apart from the
/// requirement that the first character is either '&amp;', '#', '+' or '!',
/// the only restriction on a channel name is that it SHALL NOT contain any
/// spaces(' '), a control G(^G or ASCII 7), a comma(',').Space is used as
/// parameter separator and command is used as a list item separator by the
/// protocol).A colon(':') can also be used as a delimiter for the channel
/// mask.Channel names are case insensitive.
/// </summary>
///
/// <remarks>   Francisco, 4/20/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_channel
{
public:

    typedef std::string::size_type size_type;

    static const size_type MAX_SIZE = 50u;

    irc_channel(const std::string & name)
        : name_(name)
    {
        if (!irc_channel::is_valid(name))
            throw std::invalid_argument("The provided name does not "
            "conform to channel name requirements.");
    };

    static bool is_valid(const std::string & name)
    {
        return name.size() <= MAX_SIZE && std::regex_match(name, name_regex_);
    }

private:

    /// <summary>   The channel name RegEx. </summary>
    static const std::regex name_regex_;

    const std::string name_;
};

#endif IRC_CHANNEL_H