#ifndef PREFIX_HPP
#define PREFIX_HPP

#include <regex>

namespace dapps
{
	namespace irc
	{
		class prefix
		{
		public:
			static const char DELIMETER = 0x3a;
			static const std::regex REGEX;

		private:
			const std::regex prefix::REGEX;

		};
	}
}

#endif