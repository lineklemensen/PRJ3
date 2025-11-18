#pragma once
#include <Direction.h>
#include <Key.h>
#include <map>
#include <string>
#include "Vec2.h"

class Element {
public:
    virtual ~Element() = default;
    virtual void print() = 0;
    [[nodiscard]] size_t Size() const;
    [[nodiscard]] const Vec2& get_next_available_pos(Direction dir = VERTICAL) const;
    void connect(Element* element, Direction dir = VERTICAL);
    void add_keybind(Key key, Element* element);
    Element* get_button(Key key);

protected:
    std::string text_;
    Vec2 pos_ = {};
    std::map<Key, Element*> keyMap_;
};
