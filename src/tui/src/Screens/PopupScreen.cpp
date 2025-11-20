#include "PopupScreen.h"

#include <Button.h>
#include <Console.h>
#include <iostream>
#include <TextElement.h>
#include "Tui.h"
#include "HttpHandler.h"

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

    const auto confirm_button = new Button("Confirm", {2, y_pos}, [=, this] {
        constexpr char spr[] = {'|', '/', '-', '\\'};
        int i = 0;

        //TODO most of this should be refactored out to a single call
        std::promise<cpr::Response> p;
        std::future<cpr::Response> f = p.get_future();
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

        const cpr::Response res = f.get();
        if(res.status_code != cpr::status::HTTP_OK) {
            auto error = TextElement("Sending route failed...Try again...", {2, y_pos});
            error.print();
            //5s wait to let user read
            std::this_thread::sleep_for(std::chrono::seconds(5));

            Tui::pop_screen();
        };
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
