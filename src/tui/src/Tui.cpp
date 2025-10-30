//
// Created by danie on 9/1/2025.
//

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
    elements_.push_back(new TextElement("Please select up to 3 rooms", {1, 0}));
    elements_.push_back(new TextElement("Navigate using WASD, Enter to select", {1, 1}));
    for(short i = 2; i < 8; ++i) {
        auto action = [i] {
            std::cout << std::format("\033[{}m", 31 + i);
        };
        const auto b = new StatefulButton("Option " + std::to_string(i), {1, i}, action);

        elements_.push_back(b);
    }

    const auto close_button = new Button("Close UI", {1, 8}, [&] { exit(0); });
    const auto cancel_button = new Button("Cancel", {1, 11}, [&] {
        for(const auto& element : elements_) {
            // If dynamic cast fails it'll return null pointer
            if(auto* b = dynamic_cast<StatefulButton*>(element))
                b->set_state(false);
        }
    });
    const auto finish_button = new Button("Finish", {12, 11}, [&] { });

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
    close_button->connect(finish_button);
    close_button->connect(cancel_button);

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
    switch(Input::get_input()) {
        case Key::UP: {
            if(selected_->up_)
                selected_ = selected_->up_;
            break;
        }
        case Key::DOWN: {
            if(selected_->down_)
                selected_ = selected_->down_;
            break;
        }
        case Key::LEFT: {
            if(selected_->left_)
                selected_ = selected_->left_;
            break;
        }
        case Key::RIGHT: {
            if(selected_->right_)
                selected_ = selected_->right_;
            break;
        }
        case Key::ENTER: {
            selected_->action();
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
