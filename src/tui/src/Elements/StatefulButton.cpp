#include "StatefulButton.h"

#include <Console.h>
#include <iostream>
#include <format>

StatefulButton::StatefulButton(const std::string& text, const std::function<void()>& action)
    : StatefulButton(text, VERTICAL, action)
{ }

StatefulButton::StatefulButton(const std::string& text, const Direction dir,
                               const std::function<void()>& action) : Button(text, dir, action),
                                                                      state_(false)
{ }


void StatefulButton::action()
{
    state_ = !state_;
    Button::action();
    print();
}

void StatefulButton::print()
{
    Button::print();
    std::cout << " ["<< (state_ ? 'x' : ' ') << ']';

}

void StatefulButton::set_state(const bool new_state)
{
    state_ = new_state;
}

bool StatefulButton::get_state() const
{
    return state_;
}
