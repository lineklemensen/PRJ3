#pragma once

#include <httplib.h>

class HttpHandler
{
public:
    static void get_route(httplib::Result *res);
};