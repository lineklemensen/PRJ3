#pragma once
#include <stack>
#include "Screen.h"

class Tui {
public:
    Tui();
    static bool is_running();
    static void stop();
    static void push_screen(Screen* screen);
    static void pop_screen();
    static void update();

private:
    static bool running_;
    static std::stack<Screen*> screen_stack_;

};
