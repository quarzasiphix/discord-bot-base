#include <bot.h>

class sandbox : public app {
public:
	sandbox() {
		printf("intialised log!!\n");
		printf("hellooo\n");

		//PushLayer(new ExampleLayer());
	}

	~sandbox() {

	}
};

app* createApp() {
	return new sandbox();
}