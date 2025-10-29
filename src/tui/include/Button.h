//
// Created by danie on 9/1/2025.
//

#pragma once
#include <string>
#include <functional>
#include "Element.h"
#include "Direction.h"

class Button : public Element {
public:
    explicit Button(const std::string& text, const std::function<void()>& action = nullptr);
    explicit Button(const std::string& text, Vec2 position, const std::function<void()>& action = nullptr);
    void print() override;
    virtual void action();
    void connect(Button* button, Direction dir = VERTICAL);

    //TODO: Dont like this at all
    Button* up_;
    Button* down_;
    Button* left_;
    Button* right_;

private:
    using ButtonAction = std::function<void()>;
    ButtonAction action_;
};
