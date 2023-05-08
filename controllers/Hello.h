//
// Created by jesse on 005, May 5.
//

#ifndef WEB_HELLO_H
#define WEB_HELLO_H

#endif //WEB_HELLO_H

#include <drogon/drogon.h>
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpSimpleController.h>
#include <iostream>
#include "HTTPRequest.hpp"
#include "Jesse.hpp"

using namespace drogon;
class MyController : public drogon::HttpController<MyController> {
public://below are macros
    METHOD_LIST_BEGIN
    // Define a route for GET requests to /hello
    ADD_METHOD_TO(MyController::hello, "/", Get);
    METHOD_LIST_END

    // Define a handler function for the /hello route
    void hello(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr&)>&& callback) {
        std::unordered_map<std::string, std::string> para = (const std::unordered_map<std::basic_string<char>, std::basic_string<char>> &) req->getParameters();
        HttpViewData data;
        data.insert("title", "Try Paramaters");
        data.insert("parameters", para);


        auto resp = HttpResponse::newHttpViewResponse("ListParameters.csp", data);
        callback(resp);
    }
};
