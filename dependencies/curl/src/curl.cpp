#include "curl.hpp"

// Callback function to receive the response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

bool curl::req(const char* url) {
    httplib::Client client(url);

    // Send a GET request
    auto res = client.Get("/");

    // Check if the request was successful
    if (res && res->status == 200) {
        // Print the response body
        std::cout << res->body << std::endl;
    }
    else {
        std::cout << "Request failed" << std::endl;
    }

    return true;
}
