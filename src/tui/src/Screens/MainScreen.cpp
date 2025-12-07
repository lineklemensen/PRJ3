#include "MainScreen.h"
#include <Button.h>
#include <iostream>
#include <StatefulButton.h>
#include <TextElement.h>
#include <thread>
#include <tui.h>
#include "PopupScreen.h"
#include "Route.h"

MainScreen::MainScreen()
{
    add_new_element(new TextElement("Navigate using WASD/Arrow keys"));
    add_new_element(new TextElement("Enter/Space to select"));
    add_new_element(new TextElement("Choose the rooms for this route"));
    add_new_element(new TextElement(""));
    const auto close_button = new Button("Close UI", [&] { Tui::stop(); });
    add_new_element(close_button);
    add_new_element(new TextElement(""));
    const auto room1 = new StatefulButton("Room 1");
    const auto room2 = new StatefulButton("Room 2");
    const auto room3 = new StatefulButton("Room 3");
    add_new_element(room1);
    add_new_element(room2);
    add_new_element(room3);
    add_new_element(new TextElement(""));
    const auto finish_button = new Button("Finish", [=] {
        const Route r{room1, room2, room3};
        if(!r.empty())
            Tui::push_screen(new PopupScreen(r));
        else {
            static auto no_room_error = TextElement("Please select at least one room...");
            no_room_error.print();
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    });
    const auto clear_button = new Button("Clear", HORIZONTAL, [&] {
        for(const auto& element : elements_) {
            if(auto* b = dynamic_cast<StatefulButton*>(element))
                b->set_state(false);
        }
        print();
    });
    add_new_element(finish_button);
    add_new_element(clear_button);

    // Initial button to start on
    selected_ = room1;

    //Connect all the 'room' buttons together for navigation
    close_button->connect(room1);
    for(size_t i = 6; i < 8; ++i)
        elements_[i]->connect(elements_[i + 1]);

    // Ordering unfortunately kinda matters here, since this assignment is bidirectional.
    // Since we do cancel after finish hitting down from close it should always jump to cancel
    finish_button->connect(clear_button, HORIZONTAL);
    room3->add_keybind(DOWN, finish_button);
    finish_button->add_keybind(UP, room3);
    clear_button->add_keybind(UP, room3);
}

void MainScreen::print()
{
    Screen::print();

    for(const auto& e : elements_) {
        const std::string border_l = e == selected_ ? "<-" : "  ";
        e->print();
        std::cout << border_l;
    }
}
