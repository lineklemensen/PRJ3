#pragma once

#include "Element.h"
#include "Vec2.h"

class TextElement : public Element {
public:
    explicit TextElement(const std::string& text);
    explicit TextElement(const std::string& text, Direction dir);
    void print() override;
};
