#include "RPi_pwm.h"

#include <cmath>
#include <iostream>
#include <unistd.h>

RPi_pwm::RPi_pwm()
    : per(0), chip_path(), pwm_path() {}

RPi_pwm::~RPi_pwm()
{
    disable();
}

int RPi_pwm::start(int channel, int chip, int frequency)
{
    chip_path = "/sys/class/pwm/pwmchip" + std::to_string(chip);
    pwm_path = chip_path + "/pwm" + std::to_string(channel);

    std::string export_path = chip_path + "/export";
    FILE *const fp = fopen(export_path.c_str(), "w");

    if (NULL == fp)
    {
        fprintf(stderr, "PWM device does not exist. Make sure to add 'dtoverlay=pwm-2chan' to /boot/firmware/config.txt.\n");
        return -1;
    }

    const int write_result = fprintf(fp, "%d", channel);
    fclose(fp);

    if (write_result < 0)
        return write_result;

    usleep(100000);

    per = (int)1E9 / frequency;
    set_period(per);
    set_duty_cycle(0);
    enable();

    return write_result;
}

void RPi_pwm::stop() noexcept
{
    disable();
}

int RPi_pwm::set_duty_cycle(float p) const
{
    const int dc = static_cast<int>(std::round((float)per * (p / 100.0f)));
    const int r = set_duty_cycle_ns(dc);
    return r;
}

void RPi_pwm::set_period(int ns) const
{
    write_sys(pwm_path + "/" + "period", ns);
}

int RPi_pwm::set_duty_cycle_ns(int ns) const
{
    const int r = write_sys(pwm_path + "/" + "duty_cycle", ns);
    return r;
}

void RPi_pwm::enable() const
{
    write_sys(pwm_path + "/" + "enable", 1);
}

void RPi_pwm::disable() const
{
    write_sys(pwm_path + "/" + "enable", 0);
}

int RPi_pwm::write_sys(std::string filename, int value) const
{
    FILE *const fp = fopen(filename.c_str(), "w");

    if (NULL == fp)
    {
        fprintf(stderr, "Failed to open %s for writing.\n", filename.c_str());
        return -1;
    }

    const int r = fprintf(fp, "%d", value);
    fclose(fp);
    return r;
}