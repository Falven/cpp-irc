#ifndef USERNAME_HPP
#define USERNAME_HPP

#include <string>
#include <regex>
#include <stdexcept>

#include "nickname.hpp"
#include "messages/message.hpp"
#include "messages/reply.hpp"
#include "messages/user_request.hpp"

namespace dapps
{
    namespace irc
    {
        class username
        {
        public:
            username(const nickname & nick, const std::string real_name)
				: nickname_(nick),
				real_name_(real_name)
            {}

            const nickname get_nickname() const
            {
                return nickname_;
            }

			const std::string get_real_name() const
			{
				return real_name_;
			}

        private:
            const nickname nickname_;
            const std::string real_name_;
        };
    }
}

#endif