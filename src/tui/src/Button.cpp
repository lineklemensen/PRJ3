#include "Button.h"

#include <Console.h>
#include <format>
#include <iostream>

Button::Button(const std::string& text, const std::function<void()>& action) : Button(text, VERTICAL, action)
{ }

Button::Button(const std::string& text, const Direction dir, const std::function<void()>& action) : action_(action)
{
    text_ = text;
    pos_ = getNextAvailablePos(this, dir);
}

void Button::print()
{
    Console::set_cursor_pos(pos_);
    std::cout << text_;
}

void Button::action()
{
    if(action_)
        action_();
}
