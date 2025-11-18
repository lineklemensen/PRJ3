#include <conio.h>
#include "tui.h"
#include "Input.h"
#include <MainScreen.h>
#include <thread>
#include "Console.h"
#include "Screen.h"

bool Tui::running_ = true;
std::stack<Screen*> Tui::screen_stack_;


Tui::Tui()
{
    screen_stack_.push(new MainScreen());
    screen_stack_.top()->print();
}

void Tui::update()
{
    if(!kbhit()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        return;
    }

    Input::update_input();
    screen_stack_.top()->update_selection();
    screen_stack_.top()->print();
}

bool Tui::is_running()
{
    return running_;
}

void Tui::stop()
{
    running_ = false;
}

void Tui::push_screen(Screen* screen)
{
    Console::set_text_color(GRAY);
    screen_stack_.top()->print();
    Console::set_text_color(WHITE);
    screen->print();

    screen_stack_.push(screen);
}

void Tui::pop_screen()
{
    screen_stack_.pop();
    //TODO clearing the screen doesnt look nice for multiple nested screens (Main -> popup -> popup -> {pop})
    //Console::clear_screen();
    screen_stack_.top()->print();
}
