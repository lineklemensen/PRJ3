#include "TextElement.h"

#include <Console.h>
#include <iostream>

TextElement::TextElement(const std::string& text, const Direction dir)
{
    text_ = text;
    pos_ = get_next_available_pos(dir);
}

TextElement::TextElement(const std::string& text, const Vec2 pos)
{
    text_ = text;
    pos_ = pos;
}


void TextElement::print()
{
    print(pos_);
}

void TextElement::print(const Vec2 pos) const
{
    Console::set_cursor_pos(pos);
    std::cout << text_;
}
