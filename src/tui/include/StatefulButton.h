#pragma once
#include "Button.h"


class StatefulButton : public Button {
public:
    StatefulButton(const std::string& text, const std::function<void()>& action);
    StatefulButton(const std::string& text, Direction dir, const std::function<void()>& action);
    void action() override;
    void print() override;
    void print(Vec2 pos);
    void set_state(bool new_state);
    bool get_state() const;

private:
    bool state_;
};
