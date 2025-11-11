#include "MotorController.h"
#include <stdio.h>
#include <stdlib.h>
#include <gpiod.h>
#include <iostream>

MotorController::MotorController(const char* chipname,   
                                 int channel_left, 
                                 int frequency_left,
                                 int channel_right, 
                                 int frequency_right,
                                 int A1_gpio, 
                                 int B1_gpio,
                                 int A2_gpio, 
                                 int B2_gpio,
                                 Encoder& encoder_left,
                                 Encoder& encoder_right,
                                 RpiPwm& pwm_left,
                                 RpiPwm& pwm_right)
                                 
    : chipname_(chipname),
      A1_gpio_(A1_gpio), B1_gpio_(B1_gpio),
      A2_gpio_(A2_gpio), B2_gpio_(B2_gpio),
      encoder_left_(encoder_left),
      encoder_right_(encoder_right),
      pwm_left_(pwm_left),
      pwm_right_(pwm_right)
{
    // Start PWM for motors
    printf("Enabling PWM on channel %d with a frequency of %d.\n", channel_left, frequency_left);
    printf("Enabling PWM on channel %d with a frequency of %d.\n", channel_right, frequency_right);
    pwm_left_.start(channel_left, frequency_left);
    pwm_right_.start(channel_right, frequency_right);

    // Open the GPIO chip
    chip_ = gpiod_chip_open(chipname_);
    if (!chip_) {
        throw std::runtime_error("Failed to open GPIO chip");
    }

    // Get GPIO lines for motor control
    A1_line_ = gpiod_chip_get_line(chip_, A1_gpio_);
    A2_line_ = gpiod_chip_get_line(chip_, A2_gpio_);
    B1_line_ = gpiod_chip_get_line(chip_, B1_gpio_);
    B2_line_ = gpiod_chip_get_line(chip_, B2_gpio_);

    if (!A1_line_ || !A2_line_ || !B1_line_ || !B2_line_) {
        gpiod_chip_close(chip_);
        throw std::runtime_error("Error: Failed to get one or more GPIO lines");
    }

    // Request lines as outputs (all LOW initially)
    if (gpiod_line_request_output(A1_line_, "MotorCtrl", 0) < 0 ||
        gpiod_line_request_output(B1_line_, "MotorCtrl", 0) < 0 ||
        gpiod_line_request_output(A2_line_, "MotorCtrl", 0) < 0 ||
        gpiod_line_request_output(B2_line_, "MotorCtrl", 0) < 0)
    {
        gpiod_chip_close(chip_);
        throw std::runtime_error("Failed to request lines as output");
    }

    printf("MotorController initialized successfully with external encoders.\n");
}

MotorController::~MotorController()
{
    pwm_left_.stop();
    pwm_right_.stop();

    if (chip_) {
        gpiod_chip_close(chip_);
    }

    std::cout << "MotorController destroyed" << std::endl;
}

void MotorController::drive(int speed_left, int speed_right)
{
    printf("Duty cycle for left motor at %d%%\n", speed_left);
    printf("Duty cycle for right motor at %d%%\n", speed_right);
    pwm_left_.setDutyCycle(speed_left);
    pwm_right_.setDutyCycle(speed_right);
}

void MotorController::set_direction(bool A1, bool B1, bool A2, bool B2)
{
    std::cout << "Setting GPIO " << A1_gpio_ << " to " << A1 << std::endl;
    std::cout << "Setting GPIO " << B1_gpio_ << " to " << B1 << std::endl;
    std::cout << "Setting GPIO " << A2_gpio_ << " to " << A2 << std::endl;
    std::cout << "Setting GPIO " << B2_gpio_ << " to " << B2 << std::endl;

    gpiod_line_set_value(A1_line_, A1);
    gpiod_line_set_value(B1_line_, B1);
    gpiod_line_set_value(A2_line_, A2);
    gpiod_line_set_value(B2_line_, B2);
}
