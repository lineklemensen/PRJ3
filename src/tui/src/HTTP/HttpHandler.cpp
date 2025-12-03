#include "HttpHandler.h"
#include <format>
#include "Route.h"

void HttpHandler::send_route(Route r, std::promise<cpr::Response>&& res)
{
    // "visit room 1 and room 3
    //E.g
    //const std::string json = "{" + std::format("\"rooms\":[{},{},{}]", r.rooms[0], r.rooms[1], r.rooms[2]) + "}";
    const std::string json = json_dto::to_json(r);

    //Fake network delay
    //std::this_thread::sleep_for(std::chrono::seconds(10));

    res.set_value(cpr::Post(cpr::Url{"http://" + URL + ":" + PORT + ROUTE},
                            cpr::Body{json},
                            cpr::Header{{"Content-Type", "application/json"}}));
}
