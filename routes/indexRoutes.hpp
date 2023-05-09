#ifndef INDEX_H
#define INDEX_H
#include <drogon/drogon.h>
#include "HTTPRequest.hpp"


using namespace drogon;

using Callback = std::function<void (const HttpResponsePtr &)> ;
void handleRoutes() {
    drogon::app().registerHandler("/", [](const HttpRequestPtr& req, Callback &&callback)
    {
        std::unordered_map<std::string, std::string> para = (const std::unordered_map<std::basic_string<char>, std::basic_string<char>> &) req->getParameters();
        HttpViewData data;
        data.insert("title", "Try Paramaters");
        data.insert("parameters", para);

        auto resp = HttpResponse::newHttpViewResponse("home.csp", data);
        callback(resp);
    });
}
#endif