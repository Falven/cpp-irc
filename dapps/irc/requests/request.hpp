#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <vector>
#include <initializer_list>

#include "message.hpp"

namespace dapps
{
	namespace irc
	{
		class request : public message
		{
		public:
			request(const std::string & command, const std::initializer_list<std::string> && parameters)
				: message(parse_message(command, parameters)),
				command_(command),
				parameters_(parameters.begin(), parameters.end())
			{
			}

			const std::string command() const
			{
				return command_;
			}

			const std::vector<std::string> parameters() const
			{
				return parameters_;
			}

		private:
			const std::string command_;
			const std::vector<std::string> parameters_;

			const std::string parse_message(const std::string & command, const std::initializer_list<std::string> & parameters) const
			{
				std::string message;
				message.reserve(message::MAX_SIZE);

				message += command;
				for (auto && param : parameters)
				{
					message += message::DELIMITER;
					message += param;
				}
				message += message::TERMINATION;

				return message;
			}
		};
	}
}

#endif