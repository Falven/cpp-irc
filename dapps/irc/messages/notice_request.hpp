namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: NOTICE
		/// Parameters: <msgtarget> <text>
		///
		/// The NOTICE command is used similarly to PRIVMSG.The difference
		/// between NOTICE and PRIVMSG is that automatic replies MUST NEVER be
		/// sent in response to a NOTICE message.This rule applies to servers
		/// too - they MUST NOT send any error reply back to the client on
		/// receipt of a notice.The object of this rule is to avoid loops
		/// between clients automatically sending something in response to
		/// something it received.
		///
		/// This command is available to services as well as users.
		///
		/// This is typically used by services, and automatons(clients with
		/// either an AI or other interactive program controlling their actions).
		///
		/// See PRIVMSG for more details on replies and examples.
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class notice_request
		{

		};
	}
}