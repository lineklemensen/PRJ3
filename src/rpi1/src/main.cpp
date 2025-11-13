#include "MotorController.h"
#include "Encoder.h"
#include "RpiPwm.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// Chip path and poll timeout
#define CHIP_PATH "/dev/gpiochip0"
#define POLL_TIMEOUT_MS 1

// Pin definitions left motor
#define PIN_ENCODER_LEFT_A 23
#define PIN_ENCODER_LEFT_B 24
#define PIN_DIRECTION_LEFT_A 17
#define PIN_DIRECTION_LEFT_B 27
#define FREQUENCY_LEFT 1000
#define GPIO_CHANNEL_LEFT 2

// Pin definitions right motor
#define PIN_ENCODER_RIGHT_A 5
#define PIN_ENCODER_RIGHT_B 6
#define PIN_DIRECTION_RIGHT_A 10
#define PIN_DIRECTION_RIGHT_B 9
#define FREQUENCY_RIGHT 1000
#define GPIO_CHANNEL_RIGHT 3

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
    // Initialize PWM
    RpiPwm pwm_left;
    RpiPwm pwm_right;

    // Initialize Encoders
    Encoder encoder_left(CHIP_PATH, POLL_TIMEOUT_MS, PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B);
    Encoder encoder_right(CHIP_PATH, POLL_TIMEOUT_MS, PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B);

    // Start encoder threads
    encoder_left.start_thread();
    encoder_right.start_thread();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "Left encoder start position: " << encoder_left.get_position() << std::endl;
    std::cout << "Right encoder start position: " << encoder_right.get_position() << std::endl;

    // Initialize MotorController
    MotorController motors(CHIP_PATH,
                           GPIO_CHANNEL_LEFT,
                           FREQUENCY_LEFT,
                           GPIO_CHANNEL_RIGHT,
                           FREQUENCY_RIGHT,
                           PIN_DIRECTION_LEFT_A,
                           PIN_DIRECTION_LEFT_B,
                           PIN_DIRECTION_RIGHT_A,
                           PIN_DIRECTION_RIGHT_B,
                           encoder_left,
                           encoder_right,
                           pwm_left,
                            pwm_right);

    // Example: set left motor forward
    motors.set_direction(1, 0, 1, 0);
    motors.drive(30, 30); // 30% speed

    // Set stdin non-blocking for key press detection
    set_nonblocking(true);

    std::cout << "Monitoring encoder positions. Press any key to exit..." << std::endl;

    while (true) {
        // Print encoder positions
        std::cout << "Left: " << encoder_left.get_position()
                  << "  Right: " << encoder_right.get_position() << "\r" << std::flush;

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