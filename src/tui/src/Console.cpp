#include "Console.h"

#include <cassert>
#include <format>
#include <TextElement.h>
#include <Vec2.h>

HANDLE Console::stdout_handle_ = GetStdHandle(STD_OUTPUT_HANDLE);

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
    SetConsoleCursorPosition(stdout_handle_, coord);
}

void Console::hide_cursor()
{
    //https://learn.microsoft.com/en-us/windows/console/setconsolecursorinfo
    constexpr CONSOLE_CURSOR_INFO cursor_info{1, FALSE};
    SetConsoleCursorInfo(stdout_handle_, &cursor_info);
}

void Console::setup()
{
    system("cls");
    set_cursor_pos({0, 0});
    hide_cursor();
}
