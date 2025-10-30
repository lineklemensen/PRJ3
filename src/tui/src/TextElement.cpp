#include "TextElement.h"

#include <Console.h>
#include <iostream>

TextElement::TextElement(const std::string& text, const Vec2 pos)
{
    text_ = text;
    pos_ = pos;
}

void TextElement::print()
{
    Console::set_cursor_pos(pos_);
    std::cout << text_;
}
