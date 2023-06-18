#pragma once
#include <common.hpp>

class ENGINE_API app {
public:
	bool run() {
		printf("running\n");
		while (true) {
			curl c;
			c.req("https://google.com");
		}
	}
};
app* createApp();

