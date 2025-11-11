#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include "Encoder.h"
#include "RpiPwm.h"
#include <gpiod.h>
#include <stdexcept>
#include <iostream>

class MotorController {
public:
    // Constructor with encoder and PWM references
    MotorController(const char* chipname,
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
                    RpiPwm& pwm_right);

    ~MotorController();

    void drive(int speed_left, int speed_right);
    void set_direction(bool A1, bool B1, bool A2, bool B2);

private:
    const char* chipname_;
    int A1_gpio_, B1_gpio_, A2_gpio_, B2_gpio_;
    
    gpiod_chip* chip_;
    gpiod_line *A1_line_, *B1_line_, *A2_line_, *B2_line_;

    Encoder& encoder_left_;
    Encoder& encoder_right_;

    RpiPwm& pwm_left_;
    RpiPwm& pwm_right_;
};

#endif
