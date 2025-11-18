#pragma once
#include <string>
#include <functional>
#include "Element.h"

class Button : public Element {
public:
    explicit Button(const std::string& text, const std::function<void()>& action = nullptr);
    explicit Button(const std::string& text, Direction dir = VERTICAL, const std::function<void()>& action = nullptr);
    explicit Button(const std::string& text, Vec2 pos = {0, 0}, const std::function<void()>& action = nullptr);
    void print() override;
    virtual void action();

private:
    using ButtonAction = std::function<void()>;
    ButtonAction action_;
};
