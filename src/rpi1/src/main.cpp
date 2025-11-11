#include "MotorController.h"
#include <iostream>
#include <gpiod.h>
#include "Encoder.h"

int main()
{
    try
    {
        // Example: use GPIOs 17 and 27 on gpiochip0
        // Adjust to match your actual wiring
        Encoder encoder("/dev/gpiochip0", 1, 17, 27);

        // Start background monitoring
        encoder.start_thread();

        // Read the encoder position periodically for 10 seconds
        for (int i = 0; i < 10; ++i)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));

            int pos = encoder.get_position();
            std::cout << "[MAIN] Encoder position after " << i + 1 << "s: " << pos << std::endl;
        }

        // Stop monitoring
        encoder.stop_thread();

        std::cout << "Final encoder position: " << encoder.get_position() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/*
    MotorController motor(2, 1000, 3, 1000); // Use GPIO channel 2 with 1kHz frequency
    motor.set_direction(1, 0, 1, 0); // Set the left motor to forward and right motor to brake
    motor.drive(25, 75); // Set speed to 50% for the left motor and 0% for the right motor
    getchar(); // Wait for user input
*/