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

        private:

            /// <summary>   The nickname. </summary> 
            nickname nickname_;
        };
    }
}

#endif