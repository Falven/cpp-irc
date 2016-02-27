namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: SQUIT
		/// Parameters: <server> <comment>
		///
		/// The SQUIT command is available only to operators.It is used to
		/// disconnect server links.Also servers can generate SQUIT messages on
		/// error conditions.A SQUIT message may also target a remote server
		/// connection.In this case, the SQUIT message will simply be sent to
		/// the remote server without affecting the servers in between the
		/// operator and the remote server.
		///
		/// The <comment> SHOULD be supplied by all operators who execute a SQUIT
		/// for a remote server.The server ordered to disconnect its peer
		/// generates a WALLOPS message with <comment> included, so that other
		/// users may be aware of the reason of this action.
		///
		/// Numeric replies:
		///
		/// ERR_NOPRIVILEGES    ERR_NOSUCHSERVER
		/// ERR_NEEDMOREPARAMS
		///
		/// Examples:
		/// SQUIT tolsun.oulu.fi : Bad Link ?
		/// ; Command to uplink of the server tolson.oulu.fi to
		/// terminate its connection with comment "Bad Link".
		///
		/// :Trillian SQUIT cm22.eng.umd.edu : Server out of control
		/// ; Command from Trillian from to disconnect "cm22.eng.umd.edu"
		/// from the net with comment "Server out of control".
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class squit_request
		{

		};
	}
}