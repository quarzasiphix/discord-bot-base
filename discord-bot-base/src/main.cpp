#include <bot.h>

class sandbox : public app {
public:
	sandbox() {

	}

	~sandbox() {

	}
};

app* createApp() {
	return new sandbox();
}