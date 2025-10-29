#include "Button.h"

#include <Console.h>
#include <format>
#include <iostream>

Button::Button(const std::string& text, const std::function<void()>& action) : up_(nullptr), down_(nullptr), left_(nullptr),
                                                                            right_(nullptr), action_(action)
{
    text_ = text;
}

Button::Button(const std::string& text, const Vec2 position, const std::function<void()>& action) : up_(nullptr), down_(nullptr), left_(nullptr),
                                                                            right_(nullptr), action_(action)
{
    text_ = text;
    pos_ = position;
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

void Button::connect(Button* button, const Direction dir)
{
    switch(dir) {
        case VERTICAL: {
            down_ = button;
            button->up_ = this;
            break;
        }
        case HORIZONTAL: {
            right_ = button;
            button->left_ = this;
            break;
        }
    }
}
