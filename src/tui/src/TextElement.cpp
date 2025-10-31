#include "TextElement.h"

#include <Console.h>
#include <iostream>

TextElement::TextElement(const std::string& text) : TextElement(text, VERTICAL) { }

TextElement::TextElement(const std::string& text, const Direction dir)
{
    text_ = text;
    pos_ = getNextAvailablePos(this, dir);
}


void TextElement::print()
{
    Console::set_cursor_pos(pos_);
    std::cout << text_;
}
