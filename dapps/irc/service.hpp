#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <regex>
#include <stdexcept>

#include "nickname.hpp"

namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Each service is distinguished from other services by a service name
		/// composed of a nickname and a server name. As for users, the nickname has a
		/// maximum length of nine(9) characters. See the protocol grammar
		/// rules(section 2.3.1) for what may and may not be used in a nickname.
		/// </summary>
		///
		/// <remarks>   Francisco, 4/20/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class service
		{
		public:

		private:

			/// <summary>   Name of the service. </summary>
			std::string service_name_;

			/// <summary>   The nickname. </summary>
			nickname nickname_;

			/// <summary>   The servername. </summary>
			const std::string servername_;
		};
	}
}

#endif