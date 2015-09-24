#ifndef REPLY_H
#define REPLY_H

#include <string>

namespace dapps
{
    namespace irc
    {
        enum rpl_id
        {
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

        ///////////////////////////////////////////////////////////////////////////////
        /// <summary>   Base class of all IRC replies. </summary>
        ///
        /// <remarks>   Francisco, 5/8/2015. </remarks>
        ///////////////////////////////////////////////////////////////////////////////
        class reply
        {
        public:
            
            reply()
            : reply_id(rpl_id()),
              ptr_msg("")
            {
            }

            explicit reply(rpl_id id, const char * message = "Unknown")
            : reply_id(id),
              ptr_msg(message)
            {
            }

            virtual const char * message() const
            {
                return (ptr_msg != nullptr ? ptr_msg : "Unknown reply.");
            }

        protected:

            const rpl_id reply_id;

            const char * ptr_msg;
        };
    }
}

#endif