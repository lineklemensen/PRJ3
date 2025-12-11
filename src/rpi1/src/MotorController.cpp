#include "MotorController.h"

MotorController::MotorController()

    : chipname_(CHIP_PATH),
      A1_gpio_(PIN_DIRECTION_LEFT_A), B1_gpio_(PIN_DIRECTION_LEFT_B),
      A2_gpio_(PIN_DIRECTION_RIGHT_A), B2_gpio_(PIN_DIRECTION_RIGHT_B)
{
    // Start PWM for motors
    printf("Enabling PWM on channel %d with a frequency of %d.\n", GPIO_CHANNEL_LEFT, FREQUENCY_LEFT);
    printf("Enabling PWM on channel %d with a frequency of %d.\n", GPIO_CHANNEL_RIGHT, FREQUENCY_RIGHT);
    pwm_left_.start(GPIO_CHANNEL_LEFT, 0, FREQUENCY_LEFT);
    pwm_right_.start(GPIO_CHANNEL_RIGHT, 0, FREQUENCY_RIGHT);

    // Initialize encoders
    printf("Initializing left encoder on GPIOs %d and %d.\n", PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B);
    printf("Initializing right encoder on GPIOs %d and %d.\n", PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B);
    encoder_left_.init_encoder(PIN_ENCODER_LEFT_A, PIN_ENCODER_LEFT_B);
    encoder_right_.init_encoder(PIN_ENCODER_RIGHT_A, PIN_ENCODER_RIGHT_B);

    // Start encoder threads
    encoder_left_.start_thread();
    encoder_right_.start_thread();

    // Set values for PID regulation
    pid_left_.set_dt(DT);
    pid_left_.set_kp(KP_LEFT);
    pid_left_.set_ki(KI_LEFT);
    pid_left_.set_kd(KD_LEFT);
    pid_left_.set_ramp_limit(LEFT_RAMP_LIMIT);
    pid_left_.set_max_output(MAX_PWM_LEFT);
    pid_left_.set_min_output(MIN_PWM_LEFT);

    pid_right_.set_dt(DT);
    pid_right_.set_kp(KP_RIGHT);
    pid_right_.set_ki(KI_RIGHT);
    pid_right_.set_kd(KD_RIGHT);
    pid_right_.set_max_output(MAX_PWM_RIGHT);
    pid_right_.set_min_output(MIN_PWM_RIGHT);

    // Open the GPIO chip
    chip_ = gpiod_chip_open(chipname_);
    if(!chip_) {
        throw std::runtime_error("Failed to open GPIO chip");
    }

    // Get GPIO lines for motor control
    A1_line_ = gpiod_chip_get_line(chip_, A1_gpio_);
    A2_line_ = gpiod_chip_get_line(chip_, A2_gpio_);
    B1_line_ = gpiod_chip_get_line(chip_, B1_gpio_);
    B2_line_ = gpiod_chip_get_line(chip_, B2_gpio_);

    if(!A1_line_ || !A2_line_ || !B1_line_ || !B2_line_) {
        gpiod_chip_close(chip_);
        throw std::runtime_error("Error: Failed to get one or more GPIO lines");
    }

    // Request lines as outputs (all LOW initially)
    if(gpiod_line_request_output(A1_line_, "MotorCtrl", 0) < 0 ||
       gpiod_line_request_output(B1_line_, "MotorCtrl", 0) < 0 ||
       gpiod_line_request_output(A2_line_, "MotorCtrl", 0) < 0 ||
       gpiod_line_request_output(B2_line_, "MotorCtrl", 0) < 0) {
        gpiod_chip_close(chip_);
        throw std::runtime_error("Failed to request lines as output");
    }

    printf("MotorController initialized successfully with external encoders.\n");
}

MotorController::~MotorController()
{
    pwm_left_.stop();
    pwm_right_.stop();

    if(chip_) {
        gpiod_chip_close(chip_);
    }

    std::cout << "MotorController destroyed" << std::endl;
}

void MotorController::drive(int left_pwm, int right_pwm)
{
    // Determine motor directions
    bool left_forward = left_pwm <= 0;
    bool right_forward = right_pwm <= 0;

    set_direction(left_forward, right_forward);

    // Allow motors to stop if PID output is small
    int left_duty = std::abs(left_pwm);
    int right_duty = std::abs(right_pwm);

    if(left_duty < 35 && left_duty != 0 && left_duty > 0) {
        left_duty = 35;
    }

    if(right_duty < 35 && right_duty != 0 && right_duty > 0) {
        right_duty = 35;
    }

    pwm_left_.set_duty_cycle(left_duty);
    pwm_right_.set_duty_cycle(right_duty);

    // std::cout << "Duty cycle left: " << left_duty << "%, right: " << right_duty << "%\n";
}

// true  = forward
// false = backward
void MotorController::set_direction(bool left_forward, bool right_forward)
{
    // Map logical forward/backward to GPIO outputs
    gpiod_line_set_value(A1_line_, left_forward ? 1 : 0);
    gpiod_line_set_value(B1_line_, left_forward ? 0 : 1);

    gpiod_line_set_value(A2_line_, right_forward ? 1 : 0);
    gpiod_line_set_value(B2_line_, right_forward ? 0 : 1);

    // std::cout << "Left motor: " << (left_forward ? "forward" : "backward") << ", Right motor: " << (right_forward ? "forward" : "backward") << std::endl;
}

void MotorController::print_encoder_pos()
{
    std::cout << "Left: " << encoder_left_.get_position() << "  Right: " << encoder_right_.get_position() << "\r" <<
            std::flush;
}

void MotorController::turn(double degrees)
{
    if(degrees == 0)
        return;

    int n = 0;
    int m = 0;
    // Calculate target encoder counts for the turn
    double dist_counts = ((M_PI * CAR_DIAMETER) / WHEEL_CIRCUMFERENCE) * ENCODER_PR_ROTATION * (std::abs(degrees) / 360.0);

    // Reset PID controllers
    pid_left_.reset();
    pid_right_.reset();

    // Starting position
    int left_pos = encoder_left_.get_position();
    int right_pos = encoder_right_.get_position();

    double left_target, right_target;

    if(degrees > 0) {
        // turn right in place
        left_target = left_pos - dist_counts; // backward
        right_target = right_pos + dist_counts; // forward
    } else {
        // turn left in place
        left_target = left_pos + dist_counts; // forward
        right_target = right_pos - dist_counts; // backward
    }

    // Errors
    int left_error = std::abs(left_target - left_pos);
    int right_error = std::abs(right_target - right_pos);

    // Extra variables
    double left_ctrl, right_ctrl;
    constexpr double INTEGRATION_THRESHOLD = 5.0; // prevent integral windup

    std::cout << "Starting turn of " << degrees << " degrees.\n";
    std::cout << "Target positions: Left=" << left_target << ", Right=" << (right_target + 80) << "\n";

    std::ofstream data_file("pid_test.csv", std::ios::out | std::ios::trunc);

    if(!data_file.is_open()) {
        std::cerr << "Failed to open pid_test.csv for writing!\n";
        return;
    }
    data_file << "time,pos,ctrl,pwm\n"; // CSV header

    while(true) {
        ++n;

        // Current positiom
        left_pos = encoder_left_.get_position();
        right_pos = encoder_right_.get_position();

        // Update PWM
        int left_pwm = pid_left_.update(left_target, left_pos, &left_ctrl, INTEGRATION_THRESHOLD);
        int right_pwm = pid_right_.update(right_target, right_pos, &right_ctrl, INTEGRATION_THRESHOLD);

        // Calculate errors
        left_error = std::abs(left_target - left_pos);
        right_error = std::abs(right_target - right_pos);

        double t = n * pid_left_.get_dt();

        // Write to CSV
        //data_file << t << "," << left_pos << "," << left_ctrl << "," << left_pwm << "\n";
        //data_file.flush();

        drive(left_pwm, right_pwm);

        if(std::abs(left_pwm) < 20 && std::abs(right_pwm) < 20) {
            ++m;
            if(m > 100) {
                std::cout << "M Left Error: " << left_error << ", M Left PWM: " << left_pwm << std::endl;
                std::cout << "M Right Error: " << right_error << ", M Right PWM: " << right_pwm << std::endl;
                break;
            }
        }

        if(std::abs(left_error) < 20 && (std::abs(right_error) - 80) < 20) {
            std::cout << "E Left Error: " << left_error << ", E Left PWM: " << left_pwm << std::endl;
            std::cout << "E Right Error: " << right_error << ", E Right PWM: " << right_pwm << std::endl;
            break;
        }

        usleep(DT * 1000000);
    }
    data_file.close();
    drive(0, 0); // stop motors
    std::cout << "\nTurn completed.\n";
}

void MotorController::drive_distance(double distance)
{
    int n = 0;
    int m = 0;

    // Encoder pulses needed to reach target
    double encoder_pulses = distance / WHEEL_CIRCUMFERENCE * ENCODER_PR_ROTATION;

    // Starting position
    double left_pos = encoder_left_.get_position();
    double right_pos = encoder_right_.get_position();

    // Targets
    double left_target = left_pos + encoder_pulses;
    double right_target = right_pos + encoder_pulses;

    // Errors
    double left_error = std::abs(left_target - left_pos);
    double right_error = std::abs(right_target - right_pos);

    // Reset PID controllers
    pid_left_.reset();
    pid_right_.reset();

    // Extra variables
    double left_ctrl, right_ctrl;
    constexpr double INTEGRATION_THRESHOLD = 5.0; // prevent integral windup

    // std::cout << "Stopping at left " << left_target << "and right " << right_target << std::endl;

    // Prepare CSV file
    std::ofstream data_file("pid_test.csv", std::ios::out | std::ios::trunc);

    if(!data_file.is_open()) {
        std::cerr << "Failed to open pid_test.csv for writing!\n";
        return;
    }
    data_file << "time,pos,ctrl,pwm\n"; // CSV header

    while(true) {
        ++n;

        // Track current position
        left_pos = encoder_left_.get_position();
        right_pos = encoder_right_.get_position();

        //right_pos = encoder_right_.get_position();

        // Update PWM
        int left_pwm = pid_left_.update(left_target, left_pos, &left_ctrl, INTEGRATION_THRESHOLD);
        int right_pwm = pid_right_.update(right_target, right_pos, &right_ctrl, INTEGRATION_THRESHOLD);

        // Calculate erros
        left_error = left_target - left_pos;
        right_error = right_target - right_pos;

        double t = n * pid_left_.get_dt();

        // Write to CSV
        //data_file << t << "," << right_pos << "," << right_ctrl << "," << right_pwm << "\n";
        //data_file.flush();

        //During testing we found that one motor was consistently stronger that the other,
        //so we apply a band-aid adjustment factor that shifts the pwm of both sides to compensate

        const double adjust_factor = (std::abs(right_error) / (std::abs(left_error) == 0 ? std::abs(right_error) : std::abs(left_error))) - 1;
        //std::cout << "Adjustment factor: " << adjust_factor << "Old: [" << left_pwm << ',' << right_pwm << "]\t";
        left_pwm *= 1 - adjust_factor * 4;
        right_pwm *= 1 + adjust_factor * 4;
        //Clamp values [0, 1] to avoid silly stuff
        left_pwm = std::max(-100, std::min(100, left_pwm));
        right_pwm = std::max(-100, std::min(100, right_pwm));
        //std::cout << "new: [" << left_pwm << ',' << right_pwm << "]\n";

        // Drive
        drive(left_pwm, right_pwm);

        if(std::abs(left_pwm) < 20 && std::abs(right_pwm) < 20) {
            ++m;
            if(m > 100) {
                std::cout << "M Left Error: " << left_error << ", M Left PWM: " << left_pwm << std::endl;
                std::cout << "M Right Error: " << right_error << ", M Right PWM: " << right_pwm << std::endl;
                break;
            }
        }

        if(left_error < 2 && right_error < 2) {
            std::cout << "E Left Error: " << left_error << ", E Left PWM: " << left_pwm << std::endl;
            std::cout << "E Right Error: " << right_error << ", E Right PWM: " << right_pwm << std::endl;
            break;
        }

        usleep(DT * 1000000);
    }

    data_file.close();

    std::cout << "Stopped at left " << encoder_left_.get_position() << " and right " << encoder_right_.get_position() <<
            std::endl;

    drive(0, 0);
}
