#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <stdexcept>
#include <ostream>

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Servers and clients send each other messages, which may or may not
		/// generate a reply.If the message contains a valid command, as described in
		/// later sections, the client should expect a reply as specified but it is
		/// not advised to wait forever for the reply; client to server and server to
		/// server communication is essentially asynchronous by nature.
		/// 
		/// Each IRC message may consist of up to three main parts : the prefix
		/// (OPTIONAL), the command, and the command parameters(maximum of
		/// fifteen(15)).The prefix, command, and all parameters are separated by one
		/// ASCII space character(0x20) each.
		/// 
		/// The presence of a prefix is indicated with a single leading ASCII colon
		/// character(':', 0x3b), which MUST be the first character of the message
		/// itself.There MUST be NO gap(whitespace) between the colon and the
		/// prefix.The prefix is used by servers to indicate the true origin of the
		/// message.If the prefix is missing from the message, it is assumed to have
		/// originated from the connection from which it was received from.Clients
		/// SHOULD NOT use a prefix when sending a message; if they use one, the only
		/// valid prefix is the registered nickname associated with the client.
		/// 
		/// The command MUST either be a valid IRC command or a three(3) digit number
		/// represented in ASCII text.
		/// 
		/// IRC messages are always lines of characters terminated with a CR - LF
		/// (Carriage Return - Line Feed) pair, and these messages SHALL NOT exceed
		/// 512 characters in length, counting all characters including the trailing
		/// CR - LF.Thus, there are 510 characters maximum allowed for the command
		/// and its parameters.There is no provision for continuation of message
		/// lines.See section 6 for more details about current implementations.
		/// </summary>
		///
		/// <remarks>   Francisco, 4/20/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class message
		{
		public:
			// Each IRC message may consist of up to three main parts: the prefix
			// (OPTIONAL), the command, and the command parameters(maximum of 
			// fifteen(15)).The prefix, command, and all parameters are separated
			// by one ASCII space character(0x20) each.
			//
			// The presence of a prefix is indicated with a single leading ASCII
			// colon character(':', 0x3b), which MUST be the first character of the
			// message itself.There MUST be NO gap(whitespace) between the colon
			// and the prefix.The prefix is used by servers to indicate the true
			// origin of the message.If the prefix is missing from the message, it
			// is assumed to have originated from the connection from which it was
			// received from.Clients SHOULD NOT use a prefix when sending a
			// message; if they use one, the only valid prefix is the registered
			// nickname associated with the client.
			//
			// The protocol messages must be extracted from the contiguous stream of
			// octets.The current solution is to designate two characters, CR and
			// LF, as message separators.Empty messages are silently ignored,
			// which permits use of the sequence CR - LF between messages without
			// extra problems.
			//
			// The extracted message is parsed into the components <prefix>,
			// <command> and list of parameters(<params>).
			//
			// The Augmented BNF representation for this is:
			//
			// message = [":" prefix SPACE] command[params] crlf
			// prefix = servername / (nickname[["!" user] "@" host])
			// command = 1 * letter / 3digit
			// params = *14(SPACE middle)[SPACE ":" trailing]
			// = / 14(SPACE middle)[SPACE[":"] trailing]
			//
			// nospcrlfcl = %x01 - 09 / %x0B - 0C / %x0E - 1F / %x21 - 39 / %x3B - FF
			// ; any octet except NUL, CR, LF, " " and ":"
			// middle = nospcrlfcl *(":" / nospcrlfcl)
			// trailing = *(":" / " " / nospcrlfcl)
			//
			// SPACE = %x20; space character
			// crlf = %x0D %x0A; "carriage return" "linefeed"

			///////////////////////////////////////////////////////////////////////////
			/// <summary>
			/// messages SHALL NOT exceed 512 characters in length, counting all
			/// characters including the trailing CR - LF.
			/// </summary>
			///////////////////////////////////////////////////////////////////////////
			static const uint16_t MAX_SIZE = 512u;
			static const char PREFIX = 0x3a;
			static const char DELIMITER = 0x20;
			static const std::string TERMINATION;

			message(const std::string & message_str)
				: message_str_(message_str + TERMINATION),
				sstm(message_str),
				prefix(parse_prefix())
			{
				if (message_str_.length() > message::MAX_SIZE)
				{
					throw std::invalid_argument("The provided message exceeds"
						"the max allowable IRC message size.");
				}
			}

			const std::string str() const
			{
				return message_str_;
			}

		protected:
			std::istringstream sstm;
			const std::string prefix;

		private:
			const std::string message_str_;

			const std::string parse_prefix()
			{
				std::string prefix;
				if (sstm.get() == PREFIX)
				{
					sstm >> prefix;
				}
				else
				{
					sstm.seekg(0);
				}
				return prefix;
			}
		};

		const std::string message::TERMINATION = "\r\n";
	}
}

std::ostream & operator<< (std::ostream & os, const dapps::irc::message & msg)
{
	return (os << msg.str());
}

#endif