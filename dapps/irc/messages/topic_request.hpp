namespace dapps
{
	namespace irc
	{
		///////////////////////////////////////////////////////////////////////////////
		/// <summary>
		/// Command: TOPIC
		/// Parameters: <channel>[<topic>]
		///
		/// The TOPIC command is used to change or view the topic of a channel.
		/// The topic for channel <channel> is returned if there is no <topic>
		/// given.If the <topic> parameter is present, the topic for that
		/// channel will be changed, if this action is allowed for the user
		/// requesting it.If the <topic> parameter is an empty string, the
		/// topic for that channel will be removed.
		/// Numeric Replies:
		///
		/// ERR_NEEDMOREPARAMS      ERR_NOTONCHANNEL
		/// RPL_NOTOPIC             RPL_TOPIC
		/// ERR_CHANOPRIVSNEEDED    ERR_NOCHANMODES
		///
		/// Examples:
		/// : WiZ!jto@tolsun.oulu.fi TOPIC #test :New topic
		/// ; User Wiz setting the topic.
		///
		/// TOPIC #test :another topic
		/// ; Command to set the topic on #test to "another topic".
		///
		/// TOPIC #test :
		/// ; Command to clear the topic on #test.
		///
		/// TOPIC #test
		/// ; Command to check the topic for #test.
		/// </summary>
		///
		/// <remarks>   Francisco, 5/8/2015. </remarks>
		///////////////////////////////////////////////////////////////////////////////
		class topic_request
		{

		};
	}
}