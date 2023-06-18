#include "socket.hpp"

namespace discord {
    bool contains(std::string soos, std::string saas) {
        if (soos.find(saas) != std::string::npos) return true;
        else return false;
    }

	void socket::on_msg(clientpp* c, websocketpp::connection_hdl hdl, message_ptr msg) {
		nlohmann::json t = nlohmann::json::parse(msg->get_payload());
		std::cout << "socket message: \n" << t << std::endl;
        if (contains(t["t"].dump(), "READY")) {
            std::thread([=]() {heartbeat(); }).detach();
            if (t["op"].get<int>() == 0 && t["t"].get<std::string>() == "READY") {
                disc->cli.id = t["d"]["user"]["id"].get<std::string>();
                disc->cli.discriminator = t["d"]["user"]["discriminator"].get<std::string>();
                disc->cli.username = t["d"]["user"]["username"].get<std::string>();
                if (!t["d"]["guild_id"].is_null())
                    for (int i = 0; i < t["d"]["guilds"].size(); i++)
                        disc->cli.guilds.push_back(t["d"]["guilds"][i]["id"].get<std::string>());
                //if (on_login) on_login(cli);
            }
            disc->cli.initialised = true;
            disc->logged = true;
            printf("Initialised user\n");
        }
	}

	void socket::on_open(clientpp* c, websocketpp::connection_hdl hdl) {
		printf("socket opened\n");
		send(std::string("{\"op\":2,\"d\":{\"token\":\"" + std::string(disc->get_token()) + "\",\"capabilities\":253,\"properties\":{\"os\":\"Windows\",\"browser\":\"Chrome\",\"device\":\"\",\"system_locale\":\"en-US\",\"browser_user_agent\":\"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.45 Safari/537.36\",\"browser_version\":\"96.0.4664.45\",\"os_version\":\"10\",\"referrer\":\"\",\"referring_domain\":\"\",\"referrer_current\":\"\",\"referring_domain_current\":\"\",\"release_channel\":\"stable\",\"client_build_number\":108924,\"client_event_source\":null},\"compress\":false,\"client_state\":{\"guild_hashes\":{},\"highest_lastmessage_id\":\"0\",\"read_state_version\":0,\"user_guild_settings_version\":-1,\"user_settings_version\":-1}}}").c_str());
	}

	void socket::on_close(clientpp* c, websocketpp::connection_hdl hdl) {
		printf("socket closed\n");
	}
}