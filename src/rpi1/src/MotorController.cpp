#include "MotorController.h"
#include <stdio.h>
#include <stdlib.h>
#include <gpiod.h>
#include <iostream>


MotorController::MotorController()
                                 
    : chipname_(CHIP_PATH),
      A1_gpio_(PIN_DIRECTION_LEFT_A), B1_gpio_(PIN_DIRECTION_LEFT_B),
      A2_gpio_(PIN_DIRECTION_RIGHT_A), B2_gpio_(PIN_DIRECTION_RIGHT_B)
{
    // Start PWM for motors
    printf("Enabling PWM on channel %d with a frequency of %d.\n", GPIO_CHANNEL_LEFT, FREQUENCY_LEFT);
    printf("Enabling PWM on channel %d with a frequency of %d.\n", GPIO_CHANNEL_RIGHT, FREQUENCY_RIGHT);
    pwm_left_.start(GPIO_CHANNEL_LEFT, FREQUENCY_LEFT);
    pwm_right_.start(GPIO_CHANNEL_RIGHT, FREQUENCY_RIGHT);
    
    // Initialize encoders
    printf("Initializing left encoder on GPIOs %d and %d.\n", PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B);
    printf("Initializing right encoder on GPIOs %d and %d.\n", PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B);
    encoder_left_.init_encoder(PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B);
    encoder_right_.init_encoder(PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B);

    // Start encoder threads
    encoder_left_.start_thread();
    encoder_right_.start_thread();

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
    // Set PWM duty cycles
    printf("Duty cycle for left motor at %d%%\n", speed_left);
    printf("Duty cycle for right motor at %d%%\n", speed_right);
    pwm_left_.setDutyCycle(speed_left);
    pwm_right_.setDutyCycle(speed_right);
}

void MotorController::set_direction(bool A1, bool B1, bool A2, bool B2)
{
    // Set motor direction GPIOs
    std::cout << "Setting GPIO " << A1_gpio_ << " to " << A1 << std::endl;
    std::cout << "Setting GPIO " << B1_gpio_ << " to " << B1 << std::endl;
    std::cout << "Setting GPIO " << A2_gpio_ << " to " << A2 << std::endl;
    std::cout << "Setting GPIO " << B2_gpio_ << " to " << B2 << std::endl;

    gpiod_line_set_value(A1_line_, A1);
    gpiod_line_set_value(B1_line_, B1);
    gpiod_line_set_value(A2_line_, A2);
    gpiod_line_set_value(B2_line_, B2);
}

void MotorController::print_encoder_pos()
{
    std::cout << "Left: " << encoder_left_.get_position() << "  Right: " << encoder_right_.get_position() << "\r" << std::flush;
}