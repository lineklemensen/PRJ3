#pragma once
#include <thread>
#include "Route.h"
#include <cpr/cpr.h>

class HttpHandler {
public:
    static void send_route(Route r, std::promise<cpr::Response>&& res);

private:
    static constexpr std::string URL = "localhost";
    //static constexpr std::string URL = "172.16.15.2";
    static constexpr std::string ROUTE = "/new_route";
    static constexpr std::string PORT = "8080";
};
