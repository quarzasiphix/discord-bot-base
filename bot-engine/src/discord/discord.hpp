#pragma once
#include <common.hpp>
#include "socket/socket.hpp"
#include "client/client.hpp"

namespace discord {
	struct ENGINE_API client;
	class ENGINE_API socket;
	class ENGINE_API discord {
		socket* sock;
		const char* token;
	public:
		client cli;
		bool logged = false;
		discord(const char* token) : token(token) {
			sock = new socket(this);
		}

		const char* get_token() { return token; }
	};
}

