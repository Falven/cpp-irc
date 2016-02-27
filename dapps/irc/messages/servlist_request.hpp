namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: SERVLIST
		/// Parameters: [<mask>[<type>]]
		///
		/// The SERVLIST command is used to list services currently connected to
		/// the network and visible to the user issuing the command.The
		/// optional parameters may be used to restrict the result of the query
		/// (to matching services names, and services type).
		///
		/// Numeric Replies:
		/// RPL_SERVLIST    RPL_SERVLISTEND
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class servlist_request
		{

		};
	}
}