#pragma once
#include <string>
#include "Vec2.h"

class Element {
public:
    virtual void print() = 0;
    virtual ~Element() = default;

protected:
    std::string text_;
    Vec2 pos_ = {};
};
