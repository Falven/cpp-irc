namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: VERSION
		/// Parameters: [<target>]
		///
		/// The VERSION command is used to query the version of the server
		/// program.An optional parameter <target> is used to query the version
		/// of the server program which a client is not directly connected to.
		///
		/// Wildcards are allowed in the <target> parameter.
		///
		/// Numeric Replies:
		/// ERR_NOSUCHSERVER                RPL_VERSION
		///
		/// Examples:
		/// VERSION tolsun.oulu.fi
		/// ; Command to check the version of server "tolsun.oulu.fi".
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class version_request
		{

		};
	}
}