#ifndef SECURE_CLIENT_H
#define SECURE_CLIENT_H

#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <vector>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include "reply.hpp"
#include "message.hpp"
#include "irc_exception.hpp"

namespace dapps
{
    namespace irc
    {
        class secure_client : public client_base
        {
        public:
            secure_client(boost::asio::io_service & io_service,
                          boost::asio::ssl::context & context,
                          boost::asio::ip::tcp::resolver::iterator endpoint_iterator)
            : socket_stream_(io_service, context)
            {
                socket_stream_.set_verify_mode(boost::asio::ssl::verify_peer);
                socket_stream_.set_verify_callback(boost::bind(&secure_client::verify_certificate, this, _1, _2));
                boost::asio::async_connect(socket_stream_.lowest_layer(),
                                           endpoint_iterator,
                                           boost::bind(&secure_client::handle_connect, this, boost::asio::placeholders::error));
            }

            bool verify_certificate(bool preverified, boost::asio::ssl::verify_context & ctx)
            {
                // The verify callback can be used to check whether the certificate that is
                // being presented is valid for the peer. For example, RFC 2818 describes
                // the steps involved in doing this for HTTPS. Consult the OpenSSL
                // documentation for more details. Note that the callback is called once
                // for each certificate in the certificate chain, starting from the root
                // certificate authority.

                // In this example we will simply print the certificate's subject name.
                char subject_name[256];
                X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
                X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);
                std::cout << "Verifying " << subject_name << "\n";

                return preverified;
            }
            
            void handle_connect(const boost::system::error_code & error)
            {
                if (error)
                {
                    throw irc_exception("Connect failed: " + error.message());
                }

                socket_stream_.async_handshake(boost::asio::ssl::stream_base::secure_client,
                                        boost::bind(&secure_client::handle_handshake, this, boost::asio::placeholders::error));
            }

            void handle_handshake(const boost::system::error_code & error)
            {
                if (error)
                {
                    throw irc_exception("Handshake failed: " + error.message());
                }

                std::string request;
                std::cout << "Enter message: ";
                std::getline(std::cin, request);

                boost::asio::async_write(socket_stream_,
                                        boost::asio::buffer(request, request.size()),
                                        boost::bind(&secure_client::handle_write,
                                                    this,
                                                    boost::asio::placeholders::error,
                                                    boost::asio::placeholders::bytes_transferred));
            }

            void handle_write(const boost::system::error_code & error, size_t bytes_transferred)
            {
                if (error)
                {
                    throw irc_exception("Write failed: " + error.message());
                }

                boost::asio::async_read(socket_stream_,
                                        boost::asio::buffer(reply_, bytes_transferred),
                                        boost::bind(&secure_client::handle_read,
                                                    this,
                                                    boost::asio::placeholders::error,
                                                    boost::asio::placeholders::bytes_transferred));
            }

            void handle_read(const boost::system::error_code & error, size_t bytes_transferred)
            {
                if (error)
                {
                    throw irc_exception("Read failed: " + error.message());
                }

                std::cout << "Reply: ";
                std::cout.write(reply_.data(), bytes_transferred);
                std::cout << "\n";
            }
            
        private:
            boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_stream_;
            std::vector<char> reply_;
        };
    }
}

#endif