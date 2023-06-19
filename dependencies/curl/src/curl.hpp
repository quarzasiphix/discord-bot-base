#pragma once
#define CURL_STATICLIB
#define CPPHTTPLIB_OPENSSL_SUPPORT
//#include <httplib.h>
//#define _WINSOCK2API_
//#define _WINSOCKAPI_
#include <core.h>
//#include <curl/curl.h>

class ENGINE_API curl {
public:
	bool req(const char* url);
};