#include "PopupScreen.h"

#include <Button.h>
#include <Console.h>
#include <future>
#include <iostream>
#include <TextElement.h>
#include "Tui.h"
#include "HttpHandler.h"

PopupScreen::PopupScreen(const Route& route)
{
    pos_ = {0, 4};
    int y_pos = pos_.y + 1;

    add_new_element(new TextElement("These are your selected rooms:", {2, y_pos++}));
    add_new_element(new TextElement("", {2, y_pos++}));
        if(route.room1)
            add_new_element(new TextElement("Room 1", {2, y_pos++}));
        if(route.room2)
            add_new_element(new TextElement("Room 2", {2, y_pos++}));
        if(route.room3)
            add_new_element(new TextElement("Room 3", {2, y_pos++}));
    add_new_element(new TextElement("", {2, y_pos++}));

    const auto confirm_button = new Button("Confirm", {2, y_pos}, [=, this] {
        constexpr char spr[] = {'|', '/', '-', '\\'};
        int i = 0;

        //TODO most of this should be refactored out to a single call
        std::promise<httplib::Result> p;
        std::future<httplib::Result> f = p.get_future();
        auto t = std::thread(HttpHandler::send_route, route, std::move(p));
        std::future_status status;

        //Simple spinner animation while waiting for http
        do {
            selected_->print();
            std::cout << spr[++i % 4];
            status = f.wait_for(std::chrono::milliseconds(125));
        } while(status != std::future_status::ready);

        selected_->print();
        t.join();

        const httplib::Result res = f.get();
        if(!res) {
            auto error = TextElement("Sending route failed...Try again...", {2, y_pos});
            error.print();
            //5s wait to let user read
            std::this_thread::sleep_for(std::chrono::seconds(5));

            Tui::pop_screen();
            return;
        };

        auto success_msg = TextElement("The route has been successfully made...", {2, y_pos});
        success_msg.print();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        Tui::pop_screen();
    });
    const auto deny_button = new Button("Deny", {12, y_pos}, Tui::pop_screen);

    add_new_element(confirm_button);
    add_new_element(deny_button);
    confirm_button->connect(deny_button, HORIZONTAL);

    selected_ = deny_button;
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
