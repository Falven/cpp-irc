#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <iostream>

#include "dapps/irc/client.hpp"

int main(int argc, const char * argv[])
{
    try
    {
        boost::asio::io_service io_service;

        boost::asio::ip::tcp::resolver resolver(io_service);
        boost::asio::ip::tcp::resolver::query query("freenode/boost", "irc");
        boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

        // boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
        // ctx.load_verify_file("ca.pem");

        dapps::irc::client client(io_service, iterator);

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}