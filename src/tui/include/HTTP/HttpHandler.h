#pragma once
#include <thread>
#include <future>
#include "Route.h"
#define WIN32_LEAN_AND_MEAN
#include <httplib.h>

class HttpHandler {
public:
    static void send_route(Route r, std::promise<httplib::Result>&& res);

private:
    //static constexpr std::string URL = "localhost";
    static std::string URL;
    static std::string ROUTE;
    static int PORT;
};
