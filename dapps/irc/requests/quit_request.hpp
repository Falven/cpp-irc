namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: QUIT
		/// Parameters: [<Quit Message>]
		///
		/// A client session is terminated with a quit message.The server
		/// acknowledges this by sending an ERROR message to the client.
		///
		/// Numeric Replies:
		/// None.
		///
		/// Examples:
		/// QUIT : Gone to have lunch
		/// ; Preferred message format.
		///
		/// :syrk!kalt@millennium.stealth.net QUIT : Gone to have lunch
		/// ; User syrk has quit IRC to have lunch.
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class quit_request
		{

		};
	}
}