#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "Encoder.h"
#include "RpiPwm.h"
#include <gpiod.h>
#include <stdexcept>
#include <iostream>


// Chip path and poll timeout
#define CHIP_PATH "/dev/gpiochip0"

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


class MotorController {
public:
    MotorController();
    ~MotorController();

    void drive(int speed_left, int speed_right);
    void set_direction(bool A1, bool B1, bool A2, bool B2);
    void print_encoder_pos();

private:
    const char* chipname_;
    int A1_gpio_, B1_gpio_, A2_gpio_, B2_gpio_;
    
    gpiod_chip* chip_;
    gpiod_line *A1_line_, *B1_line_, *A2_line_, *B2_line_;

    Encoder encoder_left_;
    Encoder encoder_right_;

    RpiPwm pwm_left_;
    RpiPwm pwm_right_;
};

#endif
