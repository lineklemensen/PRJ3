#pragma once
#include <Vec2.h>
#include "windows.h"

class Console {
public:
    static void setup();
    static void set_cursor_pos(short x, short y);
    static void set_cursor_pos(Vec2 pos);
private:
    static HANDLE stdout_handle_;

};
