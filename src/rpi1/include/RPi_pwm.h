#ifndef RPI_PWM_H
#define RPI_PWM_H

#include <string>

class RPi_pwm
{
public:
    RPi_pwm();
    ~RPi_pwm();

    int start(int channel, int chip, int frequency);
    void stop() noexcept;
    int set_duty_cycle(float p) const;

private:
    int per;

    std::string chip_path;
    std::string pwm_path;

    void set_period(int ns) const;
    int set_duty_cycle_ns(int ns) const;
    void enable() const;
    void disable() const;

    int write_sys(std::string filename, int value) const;
};

#endif // RPI_PWM_H