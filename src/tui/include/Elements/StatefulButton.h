#pragma once
#include "Button.h"


class StatefulButton : public Button {
public:
    explicit StatefulButton(const std::string& text, const std::function<void()>& action = nullptr);
    explicit StatefulButton(const std::string& text, Direction dir, const std::function<void()>& action = nullptr);
    void action() override;
    void print() override;
    void set_state(bool new_state);
    [[nodiscard]] bool get_state() const;

private:
    bool state_;
};
