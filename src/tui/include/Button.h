#pragma once
#include <string>
#include <functional>
#include <keys.h>
#include <map>

#include "Element.h"
#include "Direction.h"

class Button : public Element {
public:
    explicit Button(const std::string& text, const std::function<void()>& action = nullptr);
    explicit Button(const std::string& text, Vec2 position, const std::function<void()>& action = nullptr);
    void print() override;
    virtual void action();

    void connect(Button* button, Direction dir = VERTICAL);
    void add_keybind(Key key, Button* button);
    Button* get_button(Key key);

private:
    using ButtonAction = std::function<void()>;
    std::map<Key, Button*> keyMap_;
    ButtonAction action_;
};
