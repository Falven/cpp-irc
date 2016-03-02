#ifndef MODE_STATE_H
#define MODE_STATE_H

#include <sstream>
#include <stdexcept>

namespace dapps
{
	namespace irc
	{
		class mode_state
		{
		public:
			static const char ENABLE = '+';
			static const char DISABLE = '-';
			static const char AWAY = 'a';
			static const char INVISIBLE = 'i';
			static const char WALLOPS = 'w';
			static const char RESTRICTED = 'r';
			static const char OPERATOR = 'o';
			static const char LOCALOP = 'O';
			static const char RECEIPT = 's';

			mode_state(const std::string & mode_str)
			{
				parse_string(mode_str);
			}

			mode_state(const bool & is_away,
				const bool & is_invisible,
				const bool & receives_wallops,
				const bool & restricted_connection,
				const bool & is_operator,
				const bool & is_local_operator,
				const bool & receives_server_notices)
				:
				is_away_(is_away),
				is_invisible_(is_invisible),
				receives_wallops_(receives_wallops),
				restricted_connection_(restricted_connection),
				is_operator_(is_operator),
				is_local_operator_(is_local_operator),
				receives_server_notices_(receives_server_notices)
			{}

			mode_state()
				: mode_state(false, false, false, false, false, false, false)
			{}

			bool get_away()
			{
				return is_away_;
			}

			void set_away(const bool & is_away)
			{
				is_away_ = is_away;
			}

			bool get_invisible()
			{
				return is_invisible_;
			}

			void set_invisible(const bool & is_invisible)
			{
				is_invisible_ = is_invisible;
			}

			bool get_receives_wallops()
			{
				return receives_wallops_;
			}

			void set_receives_wallops(const bool & receives_wallops)
			{
				receives_wallops_ = receives_wallops;
			}

			bool get_restricted_connection()
			{
				return restricted_connection_;
			}

			void set_restricted_connection(const bool & restricted_connection)
			{
				restricted_connection_ = restricted_connection;
			}

			bool get_is_operator()
			{
				return is_operator_;
			}

			void set_is_operator(const bool & is_operator)
			{
				is_operator_ = is_operator;
			}

			bool get_is_local_operator()
			{
				return is_local_operator_;
			}

			void set_is_local_operator(const bool & is_local_operator)
			{
				is_local_operator_ = is_local_operator;
			}

			bool get_receives_server_notices()
			{
				return receives_server_notices_;
			}

			void set_receives_server_notices(const bool & receives_server_notices)
			{
				receives_server_notices_ = receives_server_notices;
			}

			void parse_string(const std::string & mode_str)
			{
				std::string::const_iterator cur = mode_str.begin(), prev = std::prev(cur), end = mode_str.end();
				while (cur != end)
				{
					if (*prev == ENABLE || *prev == DISABLE)
					{
						switch (*cur)
						{
						case 'a':
						{
							set_away(*prev == ENABLE);
							break;
						}
						case 'i':
						{
							set_invisible(*prev == ENABLE);
							break;
						}
						case 'w':
						{
							set_receives_wallops(*prev == ENABLE);
							break;
						}
						case 'r':
						{
							set_restricted_connection(*prev == ENABLE);
							break;
						}
						case 'o':
						{
							set_is_operator(*prev == ENABLE);
							break;
						}
						case 'O':
						{
							set_is_local_operator(*prev == ENABLE);
							break;
						}
						case 's':
						{
							set_receives_server_notices(*prev == ENABLE);
							break;
						}
						default:
						{
							throw std::invalid_argument(std::string("Invalid mode provided: ") + *cur);
							break;
						}
						}
					}
					++cur;
					++prev;
				}
			}

			const std::string str()
			{
				std::ostringstream modes;
				modes << (is_invisible_ ? ENABLE : DISABLE) << INVISIBLE;
				modes << (receives_wallops_ ? ENABLE : DISABLE) << WALLOPS;
				modes << (is_operator_ ? ENABLE : DISABLE) << OPERATOR;
				modes << (is_local_operator_ ? ENABLE : DISABLE) << LOCALOP;
				modes << (receives_server_notices_ ? ENABLE : DISABLE) << RECEIPT;
				return modes.str();
			}

		private:
			bool is_away_;
			bool is_invisible_;
			bool receives_wallops_;
			bool restricted_connection_;
			bool is_operator_;
			bool is_local_operator_;
			bool receives_server_notices_;
		};
	}
}

#endif