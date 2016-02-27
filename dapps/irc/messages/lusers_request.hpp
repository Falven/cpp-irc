namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: LUSERS
		/// Parameters: [<mask>[<target>]]
		///
		/// The LUSERS command is used to get statistics about the size of the
		/// IRC network.If no parameter is given, the reply will be about the
		/// whole net.If a <mask> is specified, then the reply will only
		/// concern the part of the network formed by the servers matching the
		/// mask.Finally, if the <target> parameter is specified, the request
		/// is forwarded to that server which will generate the reply.
		///
		/// Wildcards are allowed in the <target> parameter.
		///
		/// Numeric Replies:
		/// RPL_LUSERCLIENT RPL_LUSEROP
		/// RPL_LUSERUNKOWN RPL_LUSERCHANNELS
		/// RPL_LUSERME     ERR_NOSUCHSERVER
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class lusers_request
		{

		};
	}
}