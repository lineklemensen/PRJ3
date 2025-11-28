#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "Encoder.h"
#include "RpiPwm.h"
#include "Pid.h"
#include <gpiod.h>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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

// Car sizes
#define WHEEL_CIRCUMFERENCE 10
#define CAR_DIAMETER 10
#define ENCODER_PR_ROTATION 300

// Loop time (seconds)
#define DT 0.01     // 10 ms update rate for both motors

// Proportional gain
#define KP_LEFT 2.2
#define KP_RIGHT 2.2

// Integral gain
#define KI_LEFT 0.01
#define KI_RIGHT 0.01

// Derivative gain
#define KD_LEFT 0.6
#define KD_RIGHT 0.6

// Maximum control output (PWM duty cycle percentage)
#define MAX_PWM_LEFT 70
#define MAX_PWM_RIGHT 70

// Minimum control output (PWM duty cycle percentage)
#define MIN_PWM_LEFT -70
#define MIN_PWM_RIGHT -70


class MotorController {
public:
    MotorController();
    ~MotorController();

    void drive(int speed_left, int speed_right);
    void set_direction(bool left_forward, bool right_forward);
    void print_encoder_pos();
    void turn(double degrees);
    void drive_to_pos(double degrees, const std::pair<double, double>& target);

private:
    const char* chipname_;
    int A1_gpio_, B1_gpio_, A2_gpio_, B2_gpio_;
    
    gpiod_chip* chip_;
    gpiod_line *A1_line_, *B1_line_, *A2_line_, *B2_line_;

    Encoder encoder_left_;
    Encoder encoder_right_;

    RpiPwm pwm_left_;
    RpiPwm pwm_right_;

    Pid pid_left_;
    Pid pid_right_;
};

#endif
