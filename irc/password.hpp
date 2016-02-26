#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
#include <stdexcept>

namespace dapps
{
	namespace irc
	{
		class password
		{
		public:
			password(const std::string & pass)
				: pass_(pass)
			{}

			const std::string str() const
			{
				return pass_;
			}

		private:
			const std::string pass_;
		};
	}
}

#endif