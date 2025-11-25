#ifndef PID_H
#define PID_H

#include <cmath>
#include <iostream>

class Pid {
public:
    // Constructors
    Pid();
    Pid(double dt, double max_ctrl_value);

    // Setters
    void set_kp(double kp);
    void set_ki(double ki);
    void set_kd(double kd);
    void set_dt(double dt);
    void set_max_output(double max_val);
    void set_min_output(double min_val);
    void set_ramp_limit(double ramp);

    // Getters
    double get_dt() const;
    double get_kp() const;
    double get_ki() const;
    double get_kd() const;

    // Reset PID state
    void reset();

    // Update PID
    int update(double set_value, double current_value, double *ctrl_value = nullptr, double integration_threshold = 0);

private:
    double dt_;
    double max_ctrl_value_;
    double min_ctrl_value_;
    double kp_;
    double ki_;
    double kd_;
    double error_sum_;
    double previous_error_;
    unsigned long n_;

    // Ramp limiting
    double last_ctrl_;
    double ramp_limit_;

    // Helper
    double squash(double value) const;
};

#endif
