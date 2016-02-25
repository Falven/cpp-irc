#ifndef MODE_H
#define MODE_H

#include <strstream>
#include <stdexcept>
#include <memory>

namespace dapps
{
	namespace irc
	{
		class mode
		{
		public:
			// +a-i+w-r+o-O+s
			mode(const std::string & mode_str)
			: 
			  //is_away_ptr_(nullptr),
			  //is_invisible_ptr_(nullptr),
			  //receives_wallops_ptr_(nullptr),
			  //restricted_connection_ptr_(nullptr),
			  //is_operator_ptr_(nullptr),
			  //is_local_operator_ptr_(nullptr),
			  //receives_server_notices_ptr_(nullptr)
			{
				std::string::const_iterator cur = mode_str.begin(), prev = std::prev(cur), end = mode_str.end();
				while(cur != end)
				{
					switch(*cur)
					{
						case 'a':
						{
							//set_away(*prev == ENABLE);
							break;
						}
						case 'i':
						{
							//set_invisible(*prev == ENABLE);
							break;
						}
						case 'w':
						{
							//set_receives_wallops(*prev == ENABLE);
							break;
						}
						case 'r':
						{
							//set_restricted_connection(*prev == ENABLE);
							break;
						}
						case 'o':
						{
							//set_is_operator(*prev == ENABLE);
							break;
						}
						case 'O':
						{
							//set_is_local_operator(*prev == ENABLE);
							break;
						}
						case 's':
						{
							//set_receives_server_notices(*prev == ENABLE);
							break;
						}
						case ENABLE:
						case DISABLE:
						{
							continue;
							break;
						}
						default:
						{
							throw std::invalid_argument(std::string("Invalid mode provided: ") + *cur);
							break;
						}
					}
					++cur;
					++prev;
				}
			}

			//std::unique_ptr<bool> get_away()
			//{
			//	return nullptr;
			//}

			//void set_away(bool is_away)
			//{
			//	if(nullptr == is_away_ptr_)
			//	{
			//		is_away_ptr_ = std::make_unique<bool>(is_away);
			//	}
			//	else
			//	{
			//		*is_away_ptr_ = is_away;
			//	}
			//}

			//std::unique_ptr<bool> get_invisible()
			//{
			//	return nullptr;
			//}

			//void set_invisible(bool is_invisible)
			//{
			//}

			//std::unique_ptr<bool> get_receives_wallops()
			//{
			//	return nullptr;
			//}

			//void set_receives_wallops(bool receives_wallops)
			//{
			//}

			//std::unique_ptr<bool> get_restricted_connection()
			//{
			//	return nullptr;
			//}

			//void set_restricted_connection(bool restricted_connection)
			//{
			//}

			//std::unique_ptr<bool> get_is_operator()
			//{
			//	return nullptr;
			//}

			//void set_is_operator(bool is_operator)
			//{
			//}

			//std::unique_ptr<bool> get_is_local_operator()
			//{
			//	return nullptr;
			//}

			//void set_is_local_operator(bool is_local_operator)
			//{
			//}

			//std::unique_ptr<bool> get_receives_server_notices()
			//{
			//	return nullptr;
			//}

			//void set_receives_server_notices(bool receives_server_notices)
			//{
			//}

		private:
			static const char ENABLE = '+';
			static const char DISABLE = '-';

			//std::unique_ptr<bool> is_away_ptr_;
			//std::unique_ptr<bool> is_invisible_ptr_;
			//std::unique_ptr<bool> receives_wallops_ptr_;
			//std::unique_ptr<bool> restricted_connection_ptr_;
			//std::unique_ptr<bool> is_operator_ptr_;
			//std::unique_ptr<bool> is_local_operator_ptr_;
			//std::unique_ptr<bool> receives_server_notices_ptr_;

			void parse_mode_str()
			{

			}
		};
	}
}

#endif