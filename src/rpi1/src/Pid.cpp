#include "Pid.h"

// Default constructor
Pid::Pid() 
    : dt_(0.01), max_ctrl_value_(100), min_ctrl_value_(-100),
      kp_(0), ki_(0), kd_(0), error_sum_(0), previous_error_(0),
      n_(0), last_ctrl_(0), ramp_limit_(5)
{}

// Parameterized constructor
Pid::Pid(double dt, double max_ctrl_value)
    : dt_(dt), max_ctrl_value_(max_ctrl_value), min_ctrl_value_(-max_ctrl_value),
      kp_(0), ki_(0), kd_(0), error_sum_(0), previous_error_(0),
      n_(0), last_ctrl_(0), ramp_limit_(max_ctrl_value)
{}

// Setters
void Pid::set_kp(double kp) { kp_ = kp; }
void Pid::set_ki(double ki) { ki_ = ki; }
void Pid::set_kd(double kd) { kd_ = kd; }
void Pid::set_dt(double dt) { dt_ = dt; }
void Pid::set_max_output(double max_val) { max_ctrl_value_ = max_val; }
void Pid::set_min_output(double min_val) { min_ctrl_value_ = min_val; }
void Pid::set_ramp_limit(double ramp) { ramp_limit_ = ramp; }

// Getters
double Pid::get_dt() const { return dt_; }
double Pid::get_kp() const { return kp_; }
double Pid::get_ki() const { return ki_; }
double Pid::get_kd() const { return kd_; }

// Squash value to min/max
double Pid::squash(double value) const {
    if (value < min_ctrl_value_) return min_ctrl_value_;
    if (value > max_ctrl_value_) return max_ctrl_value_;
    return value;
}

// Reset PID state
void Pid::reset() {
    error_sum_ = 0;
    previous_error_ = 0;
    last_ctrl_ = 0;
    n_ = 0;
}

// PID update
int Pid::update(double set_value, double current_value, double *ctrl_value, double integration_threshold)
{
    double error_ = set_value - current_value;

    if (std::fabs(error_) < integration_threshold)
        error_sum_ += error_;

    double kp_val = error_;
    double ki_val = error_sum_ * dt_;
    double kd_val = (error_ - previous_error_) / dt_;

    previous_error_ = error_;

    double ctrl = kp_ * kp_val + ki_ * ki_val + kd_ * kd_val;

    // squash to min/max
    double squashed_ctrl = squash(ctrl);

    // ramp limiting
    if (squashed_ctrl > last_ctrl_ + ramp_limit_)
        squashed_ctrl = last_ctrl_ + ramp_limit_;
    else if (squashed_ctrl < last_ctrl_ - ramp_limit_)
        squashed_ctrl = last_ctrl_ - ramp_limit_;

    last_ctrl_ = squashed_ctrl;

    if (ctrl_value)
        *ctrl_value = squashed_ctrl;

    n_++;
    if (n_ % 50 == 0) {
        std::cout << "curr_val: " << current_value
                  << "  set_val: " << set_value
                  << "  ctrl: " << squashed_ctrl
                  << "  error: " << error_ << std::endl;
    }

    return static_cast<int>(std::round(squashed_ctrl));
}
