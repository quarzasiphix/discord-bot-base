#include "curl.hpp"

// Callback function to receive the response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

bool curl::req(const char* url) {

    CURL* curl;
    CURLcode res;
    std::string response;

    // Initialize the curl session
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Set the URL to perform the GET request
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set the callback function to receive the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the GET request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "Failed to perform the request: " << curl_easy_strerror(res) << std::endl;
            return false;
        }
        else {
            // Print the response
            std::cout << "Response:\n" << response << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    // Clean up global curl resources
    curl_global_cleanup();

    return true;
}
