#include "MotorController.h"
#include "Encoder.h"
#include "RpiPwm.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>


// Utility: set stdin to non-blocking mode
void set_nonblocking(bool enable)
{
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    if (enable) {
        ttystate.c_lflag &= ~ICANON; // disable canonical mode
        ttystate.c_lflag &= ~ECHO;   // disable echo
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    } else {
        ttystate.c_lflag |= ICANON; // restore canonical mode
        ttystate.c_lflag |= ECHO;   // restore echo
        fcntl(STDIN_FILENO, F_SETFL, 0);
    }
}

int main()
{
    // Initialize MotorController
    MotorController motors;

    usleep(100000); // wait for initialization

    // Example: set left motor forward and right motor forward
    motors.set_direction(1, 0, 1, 0);
    motors.drive(30, 30); // 30% speed

    // Set stdin non-blocking for key press detection
    set_nonblocking(true);

    std::cout << "Monitoring encoder positions. Press any key to exit..." << std::endl;

    while (true) {
        // Print encoder positions
        motors.print_encoder_pos();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Check for key press
        char c;
        if (read(STDIN_FILENO, &c, 1) > 0) {
            break; // exit on key press
        }
    }

    set_nonblocking(false);
    std::cout << "\nExiting program." << std::endl;

    return 0;
}