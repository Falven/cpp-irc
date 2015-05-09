#ifndef IRC_USER_H
#define IRC_USER_H

#include <string>
#include <regex>
#include <stdexcept>

#include "irc_nickname.hpp"
#include "irc_message.hpp"
#include "irc_reply.hpp"

class irc_user
{
public:

    ///////////////////////////////////////////////////////////////////////////
    /// <summary>
    /// The commands described here are used to register a connection with an IRC
    /// server as a user as well as to correctly disconnect.
    /// 
    /// A "PASS" command is not required for a client connection to be registered,
    /// but it MUST precede the latter of the NICK / USER combination(for a user
    /// connection) or the SERVICE command(for a service connection).The
    /// RECOMMENDED order for a client to register is as follows :
    /// 
    ///                 1. Pass message  
    /// 2. Nick message                 2. Service message  
    /// 3. User message
    /// 
    /// Upon success, the client will receive an RPL_WELCOME(for users) or
    /// RPL_YOURESERVICE(for services) message indicating that the connection is
    /// now registered and known the to the entire IRC network. The reply message
    /// MUST contain the full client identifier upon which it was registered.
    /// </summary>
    ///
    /// <remarks>   Francisco, 5/8/2015. </remarks>
    ///
    /// <param name="pass"> The pass to connect. Optional. </param>
    ///
    /// <returns>   An irc_reply. </returns>
    ///////////////////////////////////////////////////////////////////////////
    irc_reply connect(const std::string & pass = "")
    {

    }

private:

    /// <summary>   The nickname. </summary> 
    irc_nickname nickname_;

    irc_reply send_message(irc_message message)
    {

    }
};

#endif IRC_USER_H