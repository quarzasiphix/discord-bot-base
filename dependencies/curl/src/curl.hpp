#pragma once
#define CURL_STATICLIB
#include <core.h>
#include <iostream>
#include <curl/curl.h>

class ENGINE_API curl {
public:
	bool req(const char* url);
};