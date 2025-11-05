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
    auto spawn_popup = [&] {
        std::vector<Button*> rooms;
        for(const auto e : elements_) {
            if(const auto& sb = dynamic_cast<StatefulButton*>(e)) {
                if(sb->get_state()) {
                    rooms.push_back(dynamic_cast<Button*>(e));
                }
            }
        }

        if(rooms.empty())
            return;

        Console::set_text_color(Color::GRAY);
        print_elements();
        Console::set_text_color(Color::WHITE);

        int y_pos = 4;
        const auto edge = new TextElement("x-------------------------------------------x", {0, y_pos++});
        const auto text = new TextElement("| These are your selected rooms:            |", {0, y_pos++});
        const auto spacer = new TextElement("|                                           |");

        edge->print();
        text->print();
        spacer->print({0, y_pos++});

        for(const auto& r : rooms) {
            spacer->print({0, y_pos});
            r->print({2, y_pos++});
        }

        spacer->print({0, y_pos++});
        spacer->print({0, y_pos});
        const auto confirm_button = new Button("Confirm", {2, y_pos}, nullptr);
        const auto deny_button = new Button("Deny", {13, y_pos}, [&] {
            //TODO This is unsafe to element order changes
            selected_ = elements_[3];
            Console::clear_screen();
            print_elements();
        });

        confirm_button->print();
        deny_button->print();
        std::cout << "<-";
        selected_ = deny_button;


        edge->print({0, ++y_pos});

        confirm_button->connect(deny_button, HORIZONTAL);
    };

    add_new_element(new TextElement("Please select up to 3 rooms"));
    add_new_element(new TextElement("Navigate using WASD, Enter to select"));
    add_new_element(new TextElement(""));
    const auto close_button = add_new_element(new Button("Close UI", [&] { running_ = false; }));
    add_new_element(new TextElement(""));
    const auto first_room = add_new_element(new StatefulButton("Room 1"));
    add_new_element(new StatefulButton("Room 2"));
    const auto last_room = add_new_element(new StatefulButton("Room 3"));
    add_new_element(new TextElement(""));
    const auto finish_button = add_new_element(new Button("Finish", spawn_popup));
    const auto clear_button = add_new_element(new Button("Clear", HORIZONTAL, [&] {
        for(const auto& element : elements_) {
            if(auto* b = dynamic_cast<StatefulButton*>(element))
                b->set_state(false);
        }
        print_elements();
    }));

    // Initial button to start on
    selected_ = first_room;

    //Connect all the 'room' buttons together for navigation
    close_button->connect(first_room);
    for(size_t i = 5; i < 7; ++i)
        elements_[i]->connect(elements_[i + 1]);

    // Ordering unfortunately kinda matters here, since this assignment is bidirectional.
    // Since we do cancel after finish hitting down from close it should always jump to cancel
    finish_button->connect(clear_button, HORIZONTAL);
    last_room->add_keybind(DOWN, finish_button);
    finish_button->add_keybind(UP, last_room);
    clear_button->add_keybind(UP, last_room);

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
            selected_->print();
            break;
        }
        case Key::UP:
        case Key::DOWN:
        case Key::LEFT:
        case Key::RIGHT: {
            if(const auto b = selected_->get_button(key)) {
                selected_->print();
                std::cout << "  ";
                selected_ = b;
                selected_->print();
                std::cout << "<-";
            }
            break;
        }
        default: break;
    }
}


void Tui::print_elements() const
{
    const auto edge = new TextElement("x-------------------------------------------x");
    edge->print({0, 0});
    const auto spacer = new TextElement("|                                           |");
    for(size_t i = 1; i < elements_.size() + 1; ++i) {
        spacer->print({0, static_cast<int>(i)});
    }
    edge->print({0, static_cast<int>(elements_.size() + 1)});

    for(const auto e : elements_) {
        const std::string border_l = e == selected_ ? "<-" : "  ";
        e->print();

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
}

bool Tui::is_running()
{
    return running_;
}
