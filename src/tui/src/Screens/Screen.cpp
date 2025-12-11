#include <iostream>
#include <TextElement.h>

#include "Screen.h"

#include <Button.h>
#include <Input.h>

void Screen::add_new_element(Element* element)
{
    elements_.push_back(element);
}

void Screen::update_selection()
{
    switch(const auto key = Input::get_input()) {
        case ENTER: {
            if(const auto e = dynamic_cast<Button*>(selected_))
                e->action();
            break;
        }
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT: {
            if(const auto b = selected_->get_button(key)) {
                selected_->print();
                std::cout << "  ";
                selected_ = b;
                selected_->print();
                std::cout << "<-";
            }
            break;
        }
        default: break;
    }
}

void Screen::print()
{
    //TODO make this dynamic with element width
    const auto edge = new TextElement("x-------------------------------------------x", {0, 0});
    const auto spacer = new TextElement("|                                           |", {0, 0});
    edge->print(pos_);
    for(size_t i = 1; i < elements_.size() + 1; ++i)
        spacer->print({pos_.x, static_cast<int>(pos_.y + i)});
    edge->print({pos_.x, static_cast<int>(pos_.y + elements_.size() + 1)});
}