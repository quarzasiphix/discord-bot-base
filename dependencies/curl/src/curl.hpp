#pragma once
#define CURL_STATICLIB
#include <core.h>
#include <iostream>
//#include <curl/curl.h>
#include <httplib.h>

class ENGINE_API curl {
public:
	bool req(const char* url);
};