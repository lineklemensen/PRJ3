#pragma once

#include "Element.h"
#include "Vec2.h"

class TextElement : public Element {
public:
    explicit TextElement(const std::string& text, Direction dir = VERTICAL);
    explicit TextElement(const std::string& text, Vec2 pos);
    void print() override;
    void print(Vec2 pos) const;
};
