#include <iostream>
#include "HTTPRequest.hpp"
#include <cstdlib>
#include <filesystem>
using namespace std;



int main() {
    cout << filesystem::current_path() << endl;
    char* key = getenv("API_KEY");
    if (!key) {
        cout << "Key is invalid, please check your that you have correctly set up your .env file. If you're in an IDE"
                "Be sure to set it in the IDE's environment configurations";
        return 0;
    }
    string email(key);
    std::cout << "Hello, World!" << std::endl;
    for (int i = 1720; i <= 1725; i++) {
        string year = to_string(i);
        try {
            // Create the HTTP request
            http::Request request{
                    "http://musicbrainz.org/ws/2/artist/?query=begin:" + year + "%20AND%20type:%22person%22&fmt=json"};

            // Set up headers
            std::vector<std::pair<std::string, std::string>> headers = {
                    {"User-Agent", "Project3/1.0 ( " + email + " )"}
            };

            // Send a GET request with the headers
            const auto response = request.send("GET", "", headers);

            // Print the result
            cout << "Current Year: " << year << endl;
            std::cout << std::string{response.body.begin(), response.body.end()} << '\n';
        } catch (const std::exception &e) {
            std::cerr << "Request failed, error: " << e.what() << '\n';
        }
    }
    return 0;
}
