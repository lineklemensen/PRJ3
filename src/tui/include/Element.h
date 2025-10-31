#pragma once
#include <Direction.h>
#include <keys.h>
#include <map>
#include <string>
#include "Vec2.h"

class Element {
public:
    virtual ~Element() = default;
    virtual void print() = 0;
    size_t Size() const;
    static Vec2 getNextAvailablePos(const Element* element, Direction dir = VERTICAL);

    void connect(Element* button, Direction dir = VERTICAL);
    void add_keybind(Key key, Element* button);
    Element* get_button(Key key);

protected:
    std::string text_;
    Vec2 pos_ = {};
    std::map<Key, Element*> keyMap_;
};
