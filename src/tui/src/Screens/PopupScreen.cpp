#include "PopupScreen.h"

#include <Button.h>
#include <Console.h>
#include <iostream>
#include <TextElement.h>

#include "Tui.h"

PopupScreen::PopupScreen(const Route& route)
{
    if(route.empty())
        return;

    pos_ = {0, 4};
    int y_pos = pos_.y + 1;
    add_new_element(new TextElement("These are your selected rooms:", {2, y_pos++}));
    add_new_element(new TextElement("", {2, y_pos++}));
    for(int i = 0; i < 3; ++i) {
        if(route.rooms[i] == 1)
            add_new_element(new TextElement("Room " + std::to_string(i + 1), {2, y_pos++}));
    }
    add_new_element(new TextElement("", {2, y_pos++}));

    const auto confirm_button = new Button("Confirm", {2, y_pos}, [&] {
        /*HTTP POST*/
    });
    const auto deny_button = new Button("Deny", {12, y_pos}, Tui::pop_screen);
    add_new_element(confirm_button);
    add_new_element(deny_button);

    selected_ = deny_button;

    confirm_button->connect(deny_button, HORIZONTAL);
}

void PopupScreen::print()
{
    // Print the bounding box
    Screen::print();

    for(const auto& e : elements_) {
        const std::string border_l = e == selected_ ? "<-" : "  ";
        e->print();
        std::cout << border_l;
    }
}
