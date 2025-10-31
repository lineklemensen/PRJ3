#pragma once

#include <vector>
#include "Button.h"

class Tui {
public:
    Tui();
    ~Tui();
    void update();

    static bool running_;

private:
    void update_selection();
    void print_elements() const;

    std::vector<Element*> elements_;
    Element* selected_;
};
