#pragma once
#include "keys.h"

class Input {
public:
    static Key get_input();
    static void update_input();

private:
    static int read_input();
    static Key key_;

};
