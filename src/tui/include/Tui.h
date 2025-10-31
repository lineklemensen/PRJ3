#pragma once

#include <vector>
#include "Button.h"

class Tui {
public:
    Tui();
    ~Tui();
    static bool is_running();
    void update();


private:
    void update_selection();
    void print_elements() const;
    Element* add_new_element(Element* element);

    static bool running_;
    std::vector<Element*> elements_;
    Element* selected_;
};
