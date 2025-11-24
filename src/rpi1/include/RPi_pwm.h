#ifndef RPI_PWM_H
#define RPI_PWM_H

#include <string>

class RPi_pwm
{
    public:
    RPi_pwm() = default;
    ~RPi_pwm();

    int start(int channel, int frequency, float duty_cycle = 0, int chip = 0);
    void stop() noexcept;
    int set_duty_cycle(float p) const;
}

#endif // RPI_PWM_H