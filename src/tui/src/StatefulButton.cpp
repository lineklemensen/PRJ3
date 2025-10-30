#include "StatefulButton.h"

#include <Console.h>
#include <iostream>
#include <format>

StatefulButton::StatefulButton(const std::string& text, const Vec2 pos, const std::function<void()>& action = nullptr) : Button(text, pos, action),
    state_(false)
{ }


void StatefulButton::action()
{
    state_ = !state_;
    Button::action();
}

void StatefulButton::print()
{
    Console::set_cursor_pos(pos_);

    char added_state = state_ ? 'x' : ' ';
    std::cout << std::format("{} [{}]", text_, added_state);

    //We intentionally dont call the base function,
    //as we want to have control over the text here
}

void StatefulButton::set_state(bool new_state)
{
    state_ = new_state;
}
