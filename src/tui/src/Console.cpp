#include "Console.h"
#include <cassert>
#include <format>
#include <iostream>
#include <Vec2.h>

HANDLE Console::handle_ = GetStdHandle(STD_OUTPUT_HANDLE);

void Console::set_cursor_pos(const short x, const short y)
{
    set_cursor_pos({x, y});
}

void Console::set_cursor_pos(const Vec2 pos)
{
    //https://learn.microsoft.com/en-us/windows/console/setconsolecursorposition
    assert(pos.x < std::numeric_limits<short>::max());
    assert(pos.y < std::numeric_limits<short>::max());
    assert(pos.x > std::numeric_limits<short>::min());
    assert(pos.y > std::numeric_limits<short>::min());

    const COORD coord = {static_cast<short>(pos.x), static_cast<short>(pos.y)};
    SetConsoleCursorPosition(handle_, coord);
}

void Console::hide_cursor()
{
    //https://learn.microsoft.com/en-us/windows/console/setconsolecursorinfo
    constexpr CONSOLE_CURSOR_INFO cursor_info{1, FALSE};
    SetConsoleCursorInfo(handle_, &cursor_info);
}

void Console::set_text_color(const Color color)
{
    //https://en.wikipedia.org/wiki/ANSI_escape_code
    switch(color) {
        case WHITE: {
            SetConsoleTextAttribute(handle_, WHITE);
            break;
        }
        case GRAY: {
            SetConsoleTextAttribute(handle_, GRAY);
            break;
        }
        default: return;
    }
}

void Console::clear_screen()
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle_, &info);
    DWORD w;
    FillConsoleOutputCharacter(handle_, ' ', static_cast<DWORD>(info.dwSize.X * info.dwSize.Y), {0, 0}, &w);
}

void Console::setup()
{
    clear_screen();
    set_cursor_pos({0, 0});
    hide_cursor();
}
