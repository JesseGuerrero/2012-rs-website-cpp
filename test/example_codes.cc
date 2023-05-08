#include <iostream>
#include "HTTPRequest.hpp"
#include "json.hpp"
#include <iostream>
#include <iomanip>

//https://stackoverflow.com/questions/58258694/how-to-create-http-put-requests-in-c-in-vs2019
int main(int argc, const char* argv[])
{
    try
    {
        std::string method = "GET";
        http::Request request{"http://localhost:8443/v1/temporal?daysBack=1", http::InternetProtocol::V4};

        const auto response = request.send(method, "", {
                {"Content-Type", "application/x-www-form-urlencoded"},
                {"User-Agent", "runscope/0.1"},
                {"Accept", "*/*"}
        }, std::chrono::seconds(2));

        std::cout << response.status.reason << '\n';
        if (response.status.code == http::Status::Ok)
        {
            std::string s = std::string{response.body.begin(), response.body.end()};
            nlohmann::json json;
            json = nlohmann::json::parse(s);
            std::cout << json.dump() << '\n';
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}