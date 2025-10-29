#pragma once

#include "Element.h"
#include "Vec2.h"

class TextElement : public Element {
public:
    explicit TextElement(const std::string& text, Vec2 pos);
    void print() override;

};
