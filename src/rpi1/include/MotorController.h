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
#include <fstream>

// Chip path and poll timeout
#define CHIP_PATH "/dev/gpiochip0"

// Pin definitions left motor
#define PIN_ENCODER_LEFT_A 23
#define PIN_ENCODER_LEFT_B 24
#define PIN_DIRECTION_LEFT_A 17
#define PIN_DIRECTION_LEFT_B 27
#define FREQUENCY_LEFT 1000
#define GPIO_CHANNEL_LEFT 2
// PWM SKAL PÅ 18

// Pin definitions right motor
#define PIN_ENCODER_RIGHT_A 5
#define PIN_ENCODER_RIGHT_B 6
#define PIN_DIRECTION_RIGHT_A 10
#define PIN_DIRECTION_RIGHT_B 9
#define FREQUENCY_RIGHT 1000
#define GPIO_CHANNEL_RIGHT 3
// PWM PÅ 19

// Car sizes
#define WHEEL_CIRCUMFERENCE 14.7
#define CAR_DIAMETER 10
#define ENCODER_PR_ROTATION 1364.8

// Temporary
#define TARGET_DISTANCE 29.4
#define LEFT_RAMP_LIMIT 5

// Loop time (seconds)
#define DT 0.01

// Proportional gain
#define KP_LEFT 0.17
#define KP_RIGHT 0.1325

// Integral gain
#define KI_LEFT 0.0000001
#define KI_RIGHT 0.0000001

// Derivative gain
#define KD_LEFT 0.0115
#define KD_RIGHT 0.01675

// Maximum control output (PWM duty cycle percentage)
#define MAX_PWM_LEFT 70
#define MAX_PWM_RIGHT 70

// Minimum control output (PWM duty cycle percentage)
#define MIN_PWM_LEFT -70
#define MIN_PWM_RIGHT -70

class MotorController
{
public:
    MotorController();
    ~MotorController();

    void drive(int speed_left, int speed_right);
    void set_direction(bool left_forward, bool right_forward);
    void print_encoder_pos();
    void turn(double degrees);
    void drive_distance(double distance);

private:
    const char *chipname_;
    int A1_gpio_, B1_gpio_, A2_gpio_, B2_gpio_;

    gpiod_chip *chip_;
    gpiod_line *A1_line_, *B1_line_, *A2_line_, *B2_line_;

    Encoder encoder_left_;
    Encoder encoder_right_;

    RpiPwm pwm_left_;
    RpiPwm pwm_right_;

    Pid pid_left_;
    Pid pid_right_;
};

#endif
