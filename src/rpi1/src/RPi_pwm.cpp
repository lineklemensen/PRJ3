#include "RPi_pwm.h"

RPi_pwm::RPi_pwm()
    : per(0), chip_path(), pwm_path() {}

RPi_pwm::~RPi_pwm()
{
    disable();
}

int RPi_pwm::start(int channel, int frequency, float duty_cycle, int chip)
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
}

