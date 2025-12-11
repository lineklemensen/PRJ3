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
    //https://learn.microsoft.com/en-us/windows/console/setconsoletextattribute
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
    //https://learn.microsoft.com/en-us/windows/console/getconsolescreenbufferinfo
    //https://learn.microsoft.com/en-us/windows/console/fillconsoleoutputcharacter
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle_, &info);
    DWORD w;
    FillConsoleOutputCharacterA(handle_, ' ', static_cast<DWORD>(info.dwSize.X * info.dwSize.Y), {0, 0}, &w);
}

void Console::setup()
{
    clear_screen();
    set_cursor_pos({0, 0});
    hide_cursor();
}
