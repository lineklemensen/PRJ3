#pragma once
#include <Vec2.h>

#include "Color.h"
#include "windows.h"

class Console {
public:
    static void setup();
    static void set_cursor_pos(short x, short y);
    static void set_cursor_pos(Vec2 pos);
    static void hide_cursor();
    static void set_text_color(Color color);
    static void clear_screen();

private:
    static HANDLE handle_;

};
