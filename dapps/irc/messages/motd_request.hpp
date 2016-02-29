namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: MOTD
		/// Parameters: [<target>]
		///
		/// The MOTD command is used to get the "Message Of The Day" of the given
		/// server, or current server if <target> is omitted.
		///
		/// Wildcards are allowed in the <target> parameter.
		///
		/// Numeric Replies:
		/// RPL_MOTDSTART   RPL_MOTD
		/// RPL_ENDOFMOTD   ERR_NOMOTD
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class motd_request
		{

		};
	}
}