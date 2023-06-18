#pragma once
#include <common.hpp>

namespace discord {
	struct ENGINE_API client {
        std::string prefix;
        std::string id;
        std::string username;
        std::string discriminator;
        std::vector<std::string> guilds;

        bool initialised = false;
	};
}

