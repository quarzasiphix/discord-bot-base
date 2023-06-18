#pragma once
#include <common.hpp>
#include <curl.hpp>

#include <boost/asio/ssl.hpp>
#include <boost/function.hpp>

#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/transport/asio/security/tls.hpp>

#include "functional"
#include <boost/random/triangle_distribution.hpp>
#include <nlohmann/json.hpp>

typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

namespace discord {
#define clientpp websocketpp::client<websocketpp::config::asio_tls_client>
    httplib::Headers headers;
    class ENGINE_API discord;
	class ENGINE_API socket {
		discord* disc;
        std::thread threadClient;
        const char* uri = "wss://gateway.discord.gg/?v=9&encoding=json";
        websocketpp::connection_hdl hdl;
        clientpp c;
        bool connected = false;
	public:
		socket(discord* disc) : disc(disc) {
            printf("Starting thread\n");
            threadClient = std::thread([=]() {
                headers.emplace("Authorization", disc->get_token());
                headers.emplace("User-Agent", "Discord");

                c.set_tls_init_handler([this](websocketpp::connection_hdl) {
                    return websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);
                    }
                );

                c.init_asio();
                //c.set_fail_handler   (std::bind(&discord::on_fail,    this, &c, ::_1, this));
                c.set_access_channels(websocketpp::log::alevel::none);
                c.set_message_handler(std::bind(&on_msg, this, &c, ::_1, ::_2)); //set event handlers, on_close and on_error are also possible.
                c.set_open_handler(std::bind(&on_open, this, &c, ::_1));
                c.set_close_handler(std::bind(&on_close, this, &c, ::_1));

                websocketpp::lib::error_code ec;
                clientpp::connection_ptr con = c.get_connection(uri, ec);
                if (ec) {
                    std::cout << "could not create connection because: " << ec.message() << std::endl;
                    return;
                }

                c.connect(con);
                c.run();
            });
		}

        void on_msg(clientpp* c, websocketpp::connection_hdl hdl, message_ptr msg);

        void on_open(clientpp* c, websocketpp::connection_hdl hdl);

        void on_close(clientpp* c, websocketpp::connection_hdl hdl);

        void heartbeat() {
            nlohmann::json hb;
            hb["op"] = 1;
            hb["d"] = 45000;
            while (connected == true) {
                send(hb.dump().c_str());
                Sleep(10000);
            }
        }

        void send(const char* text) {
            c.send(this->hdl, text, websocketpp::frame::opcode::text);
        }

	};
}

