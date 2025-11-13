#include "Input.h"
#ifdef _WIN64
#include <conio.h>
#endif
#ifdef __linux__
#include <curses.h>
#endif


Key Input::key_ = IGNORED;

Key Input::get_input()
{
    return key_;
}

void Input::update_input()
{
    key_ = Key::IGNORED;

    //Key codes https://learn.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-6.0/aa299374(v=vs.60)
    int c = read_input();

    switch(c) {
        case 119: //W
        {
            key_ = Key::UP;
            return;
        }
        case 97: //A
        {
            key_ = Key::LEFT;
            return;
        }
        case 115: //S
        {
            key_ = Key::DOWN;
            return;
        }
        case 100: //D
        {
            key_ = Key::RIGHT;
            return;
        }

        case 32: //space
        case 13: //enter
        {
            key_ = Key::ENTER;
            return;
        }
        default: break;
    }

    // If a key code of 224 is read it signifies a special key (such as arrow keys),
    // and we have to check if we need to read a second time to get the actual keycode of the real key
    if(c != 224)
        return;

    c = read_input();
    switch(c) {
        case 72: {
            key_ = Key::UP;
            return;
        }
        case 80: {
            key_ = Key::DOWN;
            return;
        }
        case 75: {
            key_ = Key::LEFT;
            return;
        }
        case 77: {
            key_ = Key::RIGHT;
            return;
        }
        default: break;
    }
}

int Input::read_input()
{
#ifdef _WIN64
    //From conio.h
    return _getch();
#endif
#ifdef __linux__
    //Missing linux check
    //probably curses.h
#endif
}
