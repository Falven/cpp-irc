namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: LIST
		/// Parameters: [<channel> *("," <channel>)[<target>]]
		///
		/// The list command is used to list channels and their topics.If the
		/// <channel> parameter is used, only the status of that channel is
		/// displayed.
		///
		/// If the <target> parameter is specified, the request is forwarded to
		/// that server which will generate the reply.
		///
		/// Wildcards are allowed in the <target> parameter.
		///
		/// Numeric Replies:
		/// ERR_TOOMANYMATCHES  ERR_NOSUCHSERVER
		/// RPL_LIST            RPL_LISTEND
		///
		/// Examples:
		/// LIST
		/// ; Command to list all channels.
		///
		/// LIST #twilight_zone, #42
		/// ; Command to list channels #twilight_zone and #42
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class list_request
		{

		};
	}
}