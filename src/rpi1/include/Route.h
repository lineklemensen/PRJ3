#pragma once
#include <json_dto/pub.hpp>

struct Route {
    bool room1;
    bool room2;
    bool room3;


    template<typename JSON_IO>
    void json_io(JSON_IO& io)
    {
        io
                & json_dto::mandatory("room1", room1)
                & json_dto::mandatory("room2", room2)
                & json_dto::mandatory("room3", room3);
    }
};