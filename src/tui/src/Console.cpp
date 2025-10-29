#include "Console.h"
#include <format>
#include <Vec2.h>

HANDLE Console::stdout_handle_ = GetStdHandle(STD_OUTPUT_HANDLE);

void Console::set_cursor_pos(short x, short y)
{
    set_cursor_pos({x, y});
}

void Console::set_cursor_pos(const Vec2 pos)
{
    // https://en.wikipedia.org/wiki/ANSI_escape_code
    //const std::string move_cursor_up = std::format("\033[{};{}H", pos.x, pos.y);
    //std::cout << move_cursor_up << std::endl;
    const COORD coord = {pos.x, pos.y};
    SetConsoleCursorPosition(stdout_handle_, coord);
}

void Console::setup()
{
    //const std::string clearScreen = "\033[2J";
    ////const std::string hideCursor = "\033[25L";
    //std:: cout << clearScreen << std::endl;
    system("cls");
    set_cursor_pos({0, 0});
}

