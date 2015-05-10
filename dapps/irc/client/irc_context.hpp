#ifndef IRC_CONTEXT_H
#define IRC_CONTEXT_H

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <boost/bind.hpp>
//#include <boost/network.hpp>
#include <iostream>

using boost::asio::deadline_timer;
using boost::asio::ip::tcp;

class irc_context
{
public:
private:

    boost::asio::io_service io_service;
    tcp::resolver resolver;

};

#endif IRC_CONTEXT_H