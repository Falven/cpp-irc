#ifndef NICKNAME_HPP
#define NICKNAME_HPP

#include <string>
#include <regex>
#include <stdexcept>

#include "regex_definitions.hpp"

namespace dapps
{
	namespace irc
	{
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
		class nickname
		{
		public:
			///////////////////////////////////////////////////////////////////////////
			/// <summary>
			/// Maximum number of characters that comprises a nickname. Note: this is not
			/// enforced by an irc_nickname as the limit varies by server implementation.
			/// https://tools.ietf.org/html/rfc2812#section-1.2.1.
			/// </summary>
			///////////////////////////////////////////////////////////////////////////
			static const std::string::size_type MAX_LENGTH = 9u;

			nickname(const std::string & name)
				: nickname_str_(name)
			{
				if (!nickname::is_valid(name))
					throw std::invalid_argument("The provided name does not "
						"conform to irc nickname requirements.");
			};

			static bool is_valid(const std::string & nickname)
			{
				return std::regex_match(nickname, regex_);
			}

			const std::string str() const
			{
				return nickname_str_;
			}

		private:
			/// <summary> The nickname string. </summary>
			const std::string nickname_str_;
			/// <summary> Regex used to validate proper nickname input. </summary>
			static const std::regex regex_;
		};

		// TODO Because of IRC's Scandinavian origin, the characters {}|^ are
		// considered to be the lower case equivalents of the characters []\~,
		// respectively.This is a critical issue when determining the
		// equivalence of two nicknames or channel names.
		const std::regex nickname::regex_(dapps::regex::nickname);
	}
}

#endif
