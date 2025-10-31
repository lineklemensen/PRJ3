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
    elements_.push_back(new TextElement("Please select up to 3 rooms"));
    elements_.push_back(new TextElement("Navigate using WASD, Enter to select"));
    for(short i = 2; i < 8; ++i) {
        auto action = [i] {
            std::cout << std::format("\033[{}m", 31 + i);
        };
        const auto b = new StatefulButton("Option " + std::to_string(i), action);

        elements_.push_back(b);
    }

    const auto close_button = new Button("Close UI", [&] { exit(0); });

    elements_.push_back(new TextElement(""));

    const auto cancel_button = new Button("Cancel", [&] {
        for(const auto& element : elements_) {
            // If dynamic cast fails it'll return null pointer
            if(auto* b = dynamic_cast<StatefulButton*>(element))
                b->set_state(false);
        }
    });
    const auto finish_button = new Button("Finish", HORIZONTAL, [&] { });

    elements_.push_back(close_button);
    elements_.push_back(cancel_button);
    elements_.push_back(finish_button);

    // Initial button to start on
    selected_ = dynamic_cast<Button*>(elements_[2]);

    //Connect all the 'room' buttons together for navigation
    for(size_t i = 2; i < 7; ++i)
        dynamic_cast<Button*>(elements_[i])->connect(dynamic_cast<Button*>(elements_[i + 1]));
    dynamic_cast<Button*>(elements_[7])->connect(close_button);

    // Ordering unfortunately kinda matters here, since this assignment is bi-directional.
    // Since we do cancel after finish hitting down from close it should always jump to cancel
    cancel_button->connect(finish_button, HORIZONTAL);
    close_button->add_keybind(DOWN, cancel_button);
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


void Tui::update()
{
    if(!kbhit()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return;
    }

    Input::update_input();
    Console::set_cursor_pos({1, 0});

    update_selection();
    print_elements();
}
