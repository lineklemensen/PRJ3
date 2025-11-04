#pragma once
#include <string>
#include <functional>
#include "Element.h"

class Button : public Element {
public:
    explicit Button(const std::string& text, const std::function<void()>& action = nullptr);
    explicit Button(const std::string& text, Direction dir, const std::function<void()>& action = nullptr);
    Button(const std::string& text, Vec2 pos, const std::function<void()>& action);
    void print() override;
    void print(Vec2 pos) const;
    virtual void action();

private:
    using ButtonAction = std::function<void()>;
    ButtonAction action_;
};
