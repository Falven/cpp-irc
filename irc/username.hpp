#ifndef USERNAME_H
#define USERNAME_H

#include <string>
#include <regex>
#include <stdexcept>

#include "nickname.hpp"
#include "message.hpp"
#include "reply.hpp"

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

            const std::string str() const
            {
                return "";
            }

        private:
            const nickname nickname_;
            static const char unused_ = '*';
            const std::string real_name_;
        };
    }
}

#endif