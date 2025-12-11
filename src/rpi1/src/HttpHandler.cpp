#include <HttpHandler.h>

void HttpHandler::get_route(httplib::Result *res)
{
    httplib::Client cli("192.168.43.72", 8080);
    *res = cli.Get("/get_route");
}

