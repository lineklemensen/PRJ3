#pragma once
#include "StatefulButton.h"
#include <json_dto/pub.hpp>

struct Route {
    bool room1 = false;
    bool room2 = false;
    bool room3 = false;

    Route() = delete;

    Route(const StatefulButton* r1, const StatefulButton* r2, const StatefulButton* r3)
    {
        if(r1->get_state())
            room1 = true;
        if(r2->get_state())
            room2 = true;
        if(r3->get_state())
            room3 = true;
    }

    template<typename JSON_IO>
    void json_io(JSON_IO& io)
    {
        io
                & json_dto::mandatory("room1", room1)
                & json_dto::mandatory("room2", room2)
                & json_dto::mandatory("room3", room3);
    }

    [[nodiscard]] bool empty() const
    {
        return !room1 && !room2 && !room3;
    }
};
