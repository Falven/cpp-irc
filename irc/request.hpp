#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <regex>
#include <stdexcept>
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
            : message(parse_request()),
              command_(command),
              parameters_(parameters.begin(), parameters.end())
              
            {}

            const std::string command() const
            {
                return command_;
            }

            const std::vector<const std::string> parameters() const
            {
                return parameters_;
            }

        private:            
            const std::string prefix_;
            const std::string command_;
            const std::vector<const std::string> parameters_;

            const std::string parse_request() const
            {
                std::string message;
                message.reserve(message::MAX_SIZE);

                message += command_;
                for(auto && param : parameters_)
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