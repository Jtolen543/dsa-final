#include <iostream>
#include "HTTPRequest.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    try {
        // Create the HTTP request
        http::Request request{"http://musicbrainz.org/ws/2/artist/?query=begin:1720%20AND%20type:%22person%22&fmt=json"};

        // Set up headers
        std::vector<std::pair<std::string, std::string>> headers = {
                {"User-Agent", "Project3/1.0 ( Jtolen543@gmail.com )"}
        };

        // Send a GET request with the headers
        const auto response = request.send("GET", "", headers);

        // Print the result
        std::cout << std::string{response.body.begin(), response.body.end()} << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Request failed, error: " << e.what() << '\n';
    }
    return 0;
}
