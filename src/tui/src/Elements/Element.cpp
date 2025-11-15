#include <Element.h>
#include <Key.h>

size_t Element::Size() const
{
    return text_.size();
}

Vec2 Element::getNextAvailablePos(const Element* element, const Direction dir)
{
    static Vec2 next_available_pos = {2, 0};
    switch(dir) {
        case Direction::VERTICAL: {
            next_available_pos.y += 1;
            next_available_pos.x = 2;
            break;
        }
        case Direction::HORIZONTAL: {
            next_available_pos.x += element->Size() + 6;
            break;
        }
    }
    return next_available_pos;
}

void Element::connect(Element* button, const Direction dir)
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

void Element::add_keybind(const Key key, Element* button)
{
    keyMap_.try_emplace(key, button);
}

Element* Element::get_button(const Key key)
{
    if(!keyMap_.contains(key))
        return nullptr;

    return keyMap_[key];
}
