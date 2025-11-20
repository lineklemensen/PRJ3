#pragma once
#include "StatefulButton.h"

struct Route {
    int rooms[3] = {0, 0, 0};

    Route() = delete;
    Route(const StatefulButton* r1, const StatefulButton* r2, const StatefulButton* r3)
    {
        if(r1->get_state())
            rooms[0] = 1;
        if(r2->get_state())
            rooms[1] = 1;
        if(r3->get_state())
            rooms[2] = 1;
    }

    [[nodiscard]] bool empty() const
    {
        return rooms[0] == 0 && rooms[1] == 0 && rooms[2] == 0;
    }
};
