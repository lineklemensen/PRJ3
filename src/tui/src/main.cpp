#include <Console.h>
#include <thread>
#include "Input.h"
#include "tui.h"


int main()
{
    //TODO: More element types Checkbox, Slider, linked checkboxes?
    //TODO: Move action to base type
    //TODO: Potentially move input to a base class, then do win/lin handling as inherited class
    //TODO: Improve element placement by allowing for coordinate loc (needs size handling to prevent overlap)

    Tui tui{};

    Console::setup();
    while(Tui::running_) {
        tui.update();
    }

    return 0;
}
