#ifndef REPLY_H
#define REPLY_H

#include <string>
#include <iostream>
#include <sstream>
#include <ostream>

#include "message.hpp"

namespace dapps
{
    namespace irc
    {
        enum rpl_id
        {
            RPL_UNKNOWN = 0,
            RPL_WELCOME = 1,
            RPL_YOURHOST = 2,
            RPL_CREATED = 3,
            RPL_MYINFO = 4,
            RPL_BOUNCE = 5,
            RPL_TRACELINK = 200,
            RPL_TRACECONNECTING = 201,
            RPL_TRACEHANDSHAKE = 202,
            RPL_TRACEUNKNOWN = 203,
            RPL_TRACEOPERATOR = 204,
            RPL_TRACEUSER = 205,
            RPL_TRACESERVER = 206,
            RPL_TRACESERVICE = 207,
            RPL_TRACENEWTYPE = 208,
            RPL_TRACECLASS = 209,
            RPL_TRACERECONNECT = 210,
            RPL_STATSLINKINFO = 211,
            RPL_STATSCOMMANDS = 212,
            RPL_ENDOFSTATS = 219,
            RPL_UMODEIS = 221,
            RPL_SERVLIST = 234,
            RPL_SERVLISTEND = 235,
            RPL_STATSUPTIME = 242,
            RPL_STATSOLINE = 243,
            RPL_LUSERCLIENT = 251,
            RPL_LUSEROP = 252,
            RPL_LUSERUNKNOWN = 253,
            RPL_LUSERCHANNELS = 254,
            RPL_LUSERME = 255,
            RPL_ADMINME = 256,
            RPL_ADMINLOC1 = 257,
            RPL_ADMINLOC2 = 258,
            RPL_ADMINEMAIL = 259,
            RPL_TRACELOG = 261,
            RPL_TRACEEND = 262,
            RPL_TRYAGAIN = 263,
            RPL_AWAY = 301,
            RPL_USERHOST = 302,
            RPL_ISON = 303,
            RPL_UNAWAY = 305,
            RPL_NOWAWAY = 306,
            RPL_WHOISUSER = 311,
            RPL_WHOISSERVER = 312,
            RPL_WHOISOPERATOR = 313,
            RPL_WHOWASUSER = 314,
            RPL_ENDOFWHO = 315,
            RPL_WHOISIDLE = 317,
            RPL_ENDOFWHOIS = 318,
            RPL_WHOISCHANNELS = 319,
            RPL_LISTSTART = 321,
            RPL_LIST = 322,
            RPL_LISTEND = 323,
            RPL_CHANNELMODEIS = 324,
            RPL_UNIQOPIS = 325,
            RPL_NOTOPIC = 331,
            RPL_TOPIC = 332,
            RPL_INVITING = 341,
            RPL_SUMMONING = 342,
            RPL_INVITELIST = 346,
            RPL_ENDOFINVITELIST = 347,
            RPL_EXCEPTLIST = 348,
            RPL_ENDOFEXCEPTLIST = 349,
            RPL_VERSION = 351,
            RPL_WHOREPLY = 352,
            RPL_NAMREPLY = 353,
            RPL_LINKS = 364,
            RPL_ENDOFLINKS = 365,
            RPL_ENDOFNAMES = 366,
            RPL_BANLIST = 367,
            RPL_ENDOFBANLIST = 368,
            RPL_ENDOFWHOWAS = 369,
            RPL_INFO = 371,
            RPL_MOTD = 372,
            RPL_ENDOFINFO = 374,
            RPL_MOTDSTART = 375,
            RPL_ENDOFMOTD = 376,
            RPL_YOUREOPER = 381,
            RPL_REHASHING = 382,
            RPL_YOURESERVICE = 383,
            RPL_TIME = 391,
            RPL_USERSSTART = 392,
            RPL_USERS = 393,
            RPL_ENDOFUSERS = 394,
            RPL_NOUSERS = 395
        };

        const static std::map<int, std::string> RPL_STR =
        {
            { 0, "RPL_UNKNOWN" },
            { 1, "RPL_WELCOME" },
            { 2, "RPL_YOURHOST" },
            { 3, "RPL_CREATED" },
            { 4, "RPL_MYINFO" },
            { 5, "RPL_BOUNCE" },
            { 200, "RPL_TRACELINK" },
            { 201, "RPL_TRACECONNECTING" },
            { 202, "RPL_TRACEHANDSHAKE" },
            { 203, "RPL_TRACEUNKNOWN" },
            { 204, "RPL_TRACEOPERATOR" },
            { 205, "RPL_TRACEUSER" },
            { 206, "RPL_TRACESERVER" },
            { 207, "RPL_TRACESERVICE" },
            { 208, "RPL_TRACENEWTYPE" },
            { 209, "RPL_TRACECLASS" },
            { 210, "RPL_TRACERECONNECT" },
            { 211, "RPL_STATSLINKINFO" },
            { 212, "RPL_STATSCOMMANDS" },
            { 219, "RPL_ENDOFSTATS" },
            { 221, "RPL_UMODEIS" },
            { 234, "RPL_SERVLIST" },
            { 235, "RPL_SERVLISTEND" },
            { 242, "RPL_STATSUPTIME" },
            { 243, "RPL_STATSOLINE" },
            { 251, "RPL_LUSERCLIENT" },
            { 252, "RPL_LUSEROP" },
            { 253, "RPL_LUSERUNKNOWN" },
            { 254, "RPL_LUSERCHANNELS" },
            { 255, "RPL_LUSERME" },
            { 256, "RPL_ADMINME" },
            { 257, "RPL_ADMINLOC1" },
            { 258, "RPL_ADMINLOC2" },
            { 259, "RPL_ADMINEMAIL" },
            { 261, "RPL_TRACELOG" },
            { 262, "RPL_TRACEEND" },
            { 263, "RPL_TRYAGAIN" },
            { 301, "RPL_AWAY" },
            { 302, "RPL_USERHOST" },
            { 303, "RPL_ISON" },
            { 305, "RPL_UNAWAY" },
            { 306, "RPL_NOWAWAY" },
            { 311, "RPL_WHOISUSER" },
            { 312, "RPL_WHOISSERVER" },
            { 313, "RPL_WHOISOPERATOR" },
            { 314, "RPL_WHOWASUSER" },
            { 315, "RPL_ENDOFWHO" },
            { 317, "RPL_WHOISIDLE" },
            { 318, "RPL_ENDOFWHOIS" },
            { 319, "RPL_WHOISCHANNELS" },
            { 321, "RPL_LISTSTART" },
            { 322, "RPL_LIST" },
            { 323, "RPL_LISTEND" },
            { 324, "RPL_CHANNELMODEIS" },
            { 325, "RPL_UNIQOPIS" },
            { 331, "RPL_NOTOPIC" },
            { 332, "RPL_TOPIC" },
            { 341, "RPL_INVITING" },
            { 342, "RPL_SUMMONING" },
            { 346, "RPL_INVITELIST" },
            { 347, "RPL_ENDOFINVITELIST" },
            { 348, "RPL_EXCEPTLIST" },
            { 349, "RPL_ENDOFEXCEPTLIST" },
            { 351, "RPL_VERSION" },
            { 352, "RPL_WHOREPLY" },
            { 353, "RPL_NAMREPLY" },
            { 364, "RPL_LINKS" },
            { 365, "RPL_ENDOFLINKS" },
            { 366, "RPL_ENDOFNAMES" },
            { 367, "RPL_BANLIST" },
            { 368, "RPL_ENDOFBANLIST" },
            { 369, "RPL_ENDOFWHOWAS" },
            { 371, "RPL_INFO" },
            { 372, "RPL_MOTD" },
            { 374, "RPL_ENDOFINFO" },
            { 375, "RPL_MOTDSTART" },
            { 376, "RPL_ENDOFMOTD" },
            { 381, "RPL_YOUREOPER" },
            { 382, "RPL_REHASHING" },
            { 383, "RPL_YOURESERVICE" },
            { 391, "RPL_TIME" },
            { 392, "RPL_USERSSTART" },
            { 393, "RPL_USERS" },
            { 394, "RPL_ENDOFUSERS" },
            { 395, "RPL_NOUSERS" }
        };

        ///////////////////////////////////////////////////////////////////////////////
        /// <summary>   Base class of all IRC replies. </summary>
        ///
        /// <remarks>   Francisco, 5/8/2015. </remarks>
        ///////////////////////////////////////////////////////////////////////////////
        class reply : public message
        {
        public:
            reply(const char * reply_str)
            : message(reply_str),
              sstm_(reply_str),
              numeric_(parse_numeric()),
              numeric_str_(parse_numeric_str()),
              comment_(parse_comment())
            {}

            reply(const std::string & reply_str)
            : reply(reply_str.c_str())
            {}

            reply(const reply & other)
            : reply(other.str())
            {}

            const rpl_id get_numeric() const
            {
                return numeric_;
            }

            const std::string get_numeric_str() const
            {
                return numeric_str_;
            }

            const std::string get_comment() const
            {
                return comment_;
            }

        private:
            std::istringstream sstm_;
            const rpl_id numeric_;
            const std::string numeric_str_;
            const std::string comment_;

            const rpl_id parse_numeric()
            {
                int numeric;
                sstm_ >> numeric;
                return rpl_id(numeric);
            }

            const std::string parse_numeric_str()
            {
                std::string numeric_str;
                sstm_ >> numeric_str;
                return numeric_str;
            }

            const std::string parse_comment()
            {
                std::string comment;
                std::getline(sstm_, comment);
                return comment;
            }
        };
    }
}

#endif