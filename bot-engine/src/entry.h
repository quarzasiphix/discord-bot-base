#pragma once
#include <bot.h>

#ifdef PLATFORM_WINDOWS
extern app* createApp();

int main(int argc, char** argv) {
	auto app = createApp();
	app->run();
	delete app;
	//catch (const engine::hack::proc::ReadMemoryException& ex) {
	//	EN_WARN("Exception caught: {0}", ex.what());
	//}
}

#endif // PLATFORM_WINDOWS
