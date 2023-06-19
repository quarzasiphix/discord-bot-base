#pragma once
#include <common.hpp>
namespace discord {
	class ENGINE_API discord;
}
class ENGINE_API app {
public:
	bool run() {
		printf("running\n");
		discord::discord disc();
		//if(dis)
		while (true) {
		}
	}
};
app* createApp();

