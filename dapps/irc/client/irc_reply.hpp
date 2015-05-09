#ifndef IRC_REPLY_H
#define IRC_REPLY_H

#include <string>

///////////////////////////////////////////////////////////////////////////////
/// <summary>   Base class of all IRC replies. </summary>
///
/// <remarks>   Francisco, 5/8/2015. </remarks>
///////////////////////////////////////////////////////////////////////////////
class irc_reply
{
public:
    typedef unsigned int id_type;

    explicit irc_reply(id_type id, const char * message = "Unknown") : reply_id(id), ptr_msg(message) {}

    virtual const char * message() const
    {
        return (ptr_msg != nullptr ? ptr_msg : "Unknown reply.");
    }

protected:

    const id_type reply_id;

    const char * ptr_msg;
};

#endif IRC_REPLY_H