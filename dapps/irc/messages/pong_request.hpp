namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: PONG
		/// Parameters: <server>[<server2>]
		///
		/// PONG message is a reply to ping message.If parameter <server2> is
		/// given, this message MUST be forwarded to given target.The <server>
		/// parameter is the name of the entity who has responded to PING message
		/// and generated this message.
		///
		/// Numeric Replies:
		/// ERR_NOORIGIN    ERR_NOSUCHSERVER
		///
		/// Example:
		/// PONG csd.bu.edu tolsun.oulu.fi
		/// ; PONG message from csd.bu.edu to tolsun.oulu.fi
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class pong_request
		{

		};
	}
}