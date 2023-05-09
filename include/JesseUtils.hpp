//should never be included in a csp file
#include "HTTPRequest.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <drogon/drogon.h>

std::string getHTTP(std::string url) {
    try
    {
        std::string method = "GET";
        http::Request request{url, http::InternetProtocol::V4};

        const auto response = request.send(method, "", {
                {"Content-Type", "application/x-www-form-urlencoded"},
                {"User-Agent", "runscope/0.1"},
                {"Accept", "*/*"}
        }, std::chrono::seconds(2));

        if (response.status.code == http::Status::Ok)
            return std::string{response.body.begin(), response.body.end()};
        else
            std::cout << response.status.reason << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';;
    }
}