#pragma once
#include <Element.h>
#include <vector>


class Screen {
public:
    virtual ~Screen() = default;
    void add_new_element(Element* element);
    void update_selection();
    virtual void print();

protected:
    std::vector<Element*> elements_;
    Element* root_ = nullptr;
    Element* selected_ = nullptr;
    Vec2 pos_ = {0, 0};
};
