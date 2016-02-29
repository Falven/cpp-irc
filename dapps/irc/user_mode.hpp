#ifndef USER_MODE_H
#define USER_MODE_H

namespace dapps
{
	namespace irc
	{
		class user_mode
		{
		public:
			user_mode(const bool & receives_wallops, const bool & is_invisible)
				: receives_wallops_(receives_wallops), is_invisible_(is_invisible)
			{
			}
			
			const unsigned int get_mask() const
			{
				//0010 = w
				//0001 = i
				unsigned int mask = 0;
				if (receives_wallops_)
				{
					mask += 4;
				}
				if (is_invisible_)
				{
					mask += 8;
				}
				return mask;
			}

		private:
			bool is_invisible_;
			bool receives_wallops_;
		};
	}
}

#endif