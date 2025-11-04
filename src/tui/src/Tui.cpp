#include <cassert>
#include <conio.h>
#include "tui.h"
#include "keys.h"
#include "Input.h"
#include "TextElement.h"
#include "StatefulButton.h"
#include <format>
#include <iostream>
#include <thread>
#include "Console.h"

bool Tui::running_ = true;

Tui::Tui()
{
    add_new_element(new TextElement("Please select up to 3 rooms"));
    add_new_element(new TextElement("Navigate using WASD, Enter to select"));

    add_new_element(new StatefulButton("Room 1", nullptr));
    add_new_element(new StatefulButton("Room 2", nullptr));
    add_new_element(new StatefulButton("Room 3", nullptr));

    const auto close_button = add_new_element(new Button("Close UI", [&] { exit(0); }));

    add_new_element(new TextElement(""));

    const auto finish_button = add_new_element(new Button("Finish", [&] { }));
    const auto cancel_button = add_new_element(new Button("Cancel", HORIZONTAL, [&] {
        for(const auto& element : elements_) {
            // If dynamic cast fails it'll return null pointer
            if(auto* b = dynamic_cast<StatefulButton*>(element))
                b->set_state(false);
        }
    }));

    // Initial button to start on
    selected_ = elements_[2];

    //Connect all the 'room' buttons together for navigation
    for(size_t i = 2; i < 4; ++i)
        elements_[i]->connect(elements_[i + 1]);
    elements_[4]->connect(close_button);

    // Ordering unfortunately kinda matters here, since this assignment is bi-directional.
    // Since we do cancel after finish hitting down from close it should always jump to cancel
    finish_button->connect(cancel_button, HORIZONTAL);
    close_button->add_keybind(DOWN, finish_button);
    cancel_button->add_keybind(UP, close_button);
    finish_button->add_keybind(UP, close_button);

    print_elements();
}

Tui::~Tui()
{
    for(const auto e : elements_) {
        delete e;
    }
}


void Tui::update_selection()
{
    switch(const auto key = Input::get_input()) {
        case Key::ENTER: {
            if(const auto e = dynamic_cast<Button*>(selected_))
                e->action();
            break;
        }
        case Key::UP:
        case Key::DOWN:
        case Key::LEFT:
        case Key::RIGHT: {
            if(const auto b = selected_->get_button(key))
                selected_ = b;
            break;
        }
        default: break;
    }
}


void Tui::print_elements() const
{
    for(const auto e : elements_) {
        e->print();

        const char border_l = e == selected_ ? '<' : ' ';
        std::cout << border_l;
    }
}

Element* Tui::add_new_element(Element* element)
{
    elements_.push_back(element);
    return element;
}


void Tui::update()
{
    if(!kbhit()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return;
    }

    Input::update_input();
    update_selection();
    print_elements();
}

bool Tui::is_running()
{
    return running_;
}
