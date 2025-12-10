#include "HttpHandler.h"
#include <format>
#include "Route.h"


//std::string HttpHandler::URL = "192.168.43.72"; //Dani rpi
std::string HttpHandler::URL = "192.168.43.242"; //Mikkel rpi
std::string HttpHandler::ROUTE = "/new_route";
int HttpHandler::PORT = 8080;

void HttpHandler::send_route(Route r, std::promise<httplib::Result>&& res)
{
    static httplib::Client cli(URL, PORT);
    const std::string json = json_dto::to_json(r);

    //Fake network delay
    //std::this_thread::sleep_for(std::chrono::seconds(10));

    res.set_value(cli.Post(ROUTE, json, "application/json"));
}
