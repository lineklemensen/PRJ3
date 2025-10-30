#include "Button.h"

#include <Console.h>
#include <format>
#include <iostream>

Button::Button(const std::string& text, const std::function<void()>& action) : action_(action)
{
    text_ = text;
}

Button::Button(const std::string& text, const Vec2 position, const std::function<void()>& action) : action_(action)
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
            this->add_keybind(DOWN, button);
            button->add_keybind(UP, this);
            break;
        }
        case HORIZONTAL: {
            this->add_keybind(RIGHT, button);
            button->add_keybind(LEFT, this);
            break;
        }
    }
}

void Button::add_keybind(const Key key, Button* button)
{
    keyMap_.try_emplace(key, button);
}

Button* Button::get_button(const Key key)
{
    if(!keyMap_.contains(key))
        return nullptr;

    return keyMap_[key];
}
