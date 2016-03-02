#ifndef REPLY_H
#define REPLY_H

#include <string>
#include <iostream>
#include <sstream>
#include <ostream>
#include <map>

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
			RPL_NOUSERS = 395,
			ERR_NOSUCHNICK = 401,
			ERR_NOSUCHSERVER = 402,
			ERR_NOSUCHCHANNEL = 403,
			ERR_CANNOTSENDTOCHAN = 404,
			ERR_TOOMANYCHANNELS = 405,
			ERR_WASNOSUCHNICK = 406,
			ERR_TOOMANYTARGETS = 407,
			ERR_NOORIGIN = 409,
			ERR_NORECIPIENT = 411,
			ERR_NOTEXTTOSEND = 412,
			ERR_NOTOPLEVEL = 413,
			ERR_WILDTOPLEVEL = 414,
			ERR_UNKNOWNCOMMAND = 421,
			ERR_NOMOTD = 422,
			ERR_NOADMININFO = 423,
			ERR_FILEERROR = 424,
			ERR_NONICKNAMEGIVEN = 431,
			ERR_ERRONEUSNICKNAME = 432,
			ERR_NICKNAMEINUSE = 433,
			ERR_NICKCOLLISION = 436,
			ERR_USERNOTINCHANNEL = 441,
			ERR_NOTONCHANNEL = 442,
			ERR_USERONCHANNEL = 443,
			ERR_NOLOGIN = 444,
			ERR_SUMMONDISABLED = 445,
			ERR_USERSDISABLED = 446,
			ERR_NOTREGISTERED = 451,
			ERR_NEEDMOREPARAMS = 461,
			ERR_ALREADYREGISTRED = 462,
			ERR_NOPERMFORHOST = 463,
			ERR_PASSWDMISMATCH = 464,
			ERR_YOUREBANNEDCREEP = 465,
			ERR_KEYSET = 467,
			ERR_CHANNELISFULL = 471,
			ERR_UNKNOWNMODE = 472,
			ERR_INVITEONLYCHAN = 473,
			ERR_BANNEDFROMCHAN = 474,
			ERR_BADCHANNELKEY = 475,
			ERR_NOPRIVILEGES = 481,
			ERR_CHANOPRIVSNEEDED = 482,
			ERR_CANTKILLSERVER = 483,
			ERR_NOOPERHOST = 491,
			ERR_UMODEUNKNOWNFLAG = 501,
			ERR_USERSDONTMATCH = 502
		};

		///////////////////////////////////////////////////////////////////////////////
		/// <summary>   Base class of all IRC replies. </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class reply
		{
		public:
			static const char PREFIX = 0x3a;

			reply(const std::string & reply_str)
				:rpl_(reply_str),
				sstm_(reply_str),
				prefix_(parse_prefix()),
				numeric_(parse_numeric()),
				numeric_str_(parse_numeric_str()),
				comment_(parse_comment())
			{
			}

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

			const std::string str() const
			{
				return rpl_;
			}

		private:
			const std::string rpl_;
			std::istringstream sstm_;
			const std::string prefix_;
			const rpl_id numeric_;
			const std::string numeric_str_;
			const std::string comment_;

			const std::string parse_prefix()
			{
				std::string prefix;
				if (sstm_.get() == PREFIX)
				{
					sstm_ >> prefix;
				}
				else
				{
					sstm_.seekg(0);
				}
				return prefix;
			}

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