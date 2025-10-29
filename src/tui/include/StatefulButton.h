#pragma once
#include "Button.h"


class StatefulButton : public Button {
public:
    StatefulButton(const std::string& text, Vec2 pos, const std::function<void()>& action);
    void action() override;
    void print() override;
    StatefulButton(const std::string& text, const std::function<void()>& action);
private:
    bool added_;
};
