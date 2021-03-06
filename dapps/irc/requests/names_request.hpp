namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: NAMES
		/// Parameters: [<channel> *("," <channel>)[<target>]]
		///
		/// By using the NAMES command, a user can list all nicknames that are
		/// visible to him.For more details on what is visible and what is not,
		/// see "Internet Relay Chat: Channel Management"[IRC - CHAN].The
		/// <channel> parameter specifies which channel(s) to return information
		/// about.There is no error reply for bad channel names.
		///
		/// If no <channel> parameter is given, a list of all channels and their
		/// occupants is returned.At the end of this list, a list of users who
		/// are visible but either not on any channel or not on a visible channel
		/// are listed as being on `channel' "*".
		///
		/// If the <target> parameter is specified, the request is forwarded to
		/// that server which will generate the reply.
		///
		/// Wildcards are allowed in the <target> parameter.
		///
		/// Numerics:
		/// ERR_TOOMANYMATCHES  ERR_NOSUCHSERVER
		/// RPL_NAMREPLY        RPL_ENDOFNAMES
		///
		/// Examples:
		/// NAMES #twilight_zone, #42
		/// ; Command to list visible users on #twilight_zone and #42
		///
		/// NAMES
		/// ; Command to list all visible channels and users
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class names_request
		{

		};
	}
}