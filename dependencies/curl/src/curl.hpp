#pragma once
#define CURL_STATICLIB
#include <core.h>
#include <iostream>
//#include <curl/curl.h>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#define _WINSOCK2API_
#define _WINSOCKAPI_

class ENGINE_API curl {
public:
	bool req(const char* url);
};