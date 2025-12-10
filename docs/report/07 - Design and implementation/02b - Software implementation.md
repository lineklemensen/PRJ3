# Software implementation

## MotorController
The turn() function is responsible for turning the car. The function takes a double, degrees, which is the amount of degrees the car has to turn. A positive value results in a counter-clockwise turn, and vice versa. As the function is called every time the car reaches a new point, and will sometimes have to keep going straight, the function will return immediately, if the value passed is 0. 

```cpp
if(degrees == 0)
    return;
```

The distance each wheel has to travel is then calculated, using the distance between the wheel, the circumference of the wheels and the value passed in the function. 

```cpp
// Calculate target encoder counts for the turn
    ((M_PI * CAR_DIAMETER) / WHEEL_CIRCUMFERENCE) * ENCODER_PR_ROTATION * (std::abs(degrees) / 360.0);
```

The current encoder positions are noted, and used to determine the target for both motors. Since the motors need to go in different direction, the sign of the target for each motor is set based on whether the value passed to the function is positive or negative, as described earlier.

```cpp
if(degrees > 0) {
        // turn right in place
        left_target = left_pos - dist_counts; // backward
        right_target = right_pos + dist_counts; // forward
    } else {
        // turn left in place
        left_target = left_pos + dist_counts; // forward
        right_target = right_pos - dist_counts; // backward
    }
```

Variables to store the error for each motor, i.e. its distance from target value are initialised, and we are now ready to enter the main loop of the function. 

In the loop, first the encoder positions are updated, as these are used in the PID regulation, which is updated immediately after.
```cpp
    // Current position
        left_pos = encoder_left_.get_position();
        right_pos = encoder_right_.get_position();

    // Update PWM
        int left_pwm = pid_left_.update(left_target, left_pos, &left_ctrl, INTEGRATION_THRESHOLD);
        int right_pwm = pid_right_.update(right_target, right_pos, &right_ctrl, INTEGRATION_THRESHOLD);
```

The errors are updated, and the PWM values from the PID regulation are passed into the drive() function to start driving. We then encounter the two conditions that will break the loop. First we'll look at 
```cpp
if(std::abs(left_error) < 20 && (std::abs(right_error)) < 20) {
            std::cout << "Left Error: " << left_error << ", Left PWM: " << left_pwm << std::endl;
            std::cout << "Right Error: " << right_error << ", Right PWM: " << right_pwm << std::endl;
            break;
        }
```
This if-statement simply checks if both engines are wihtin our margin for error, in this case 20 encoder pulses. If this condition is met, the loop will break, and the program will resume. However, the motors had a tendency of getting within a couple of pulses of the error-margin, and then not driving any further, as the duty cycle of the PWM signal is too low to make the motors turn. Therefore a second if-statement was added as a failsafe.

```cpp
if(std::abs(left_pwm) < 20 && std::abs(right_pwm) < 20) {
            ++m;
            if(m > 100) {
                std::cout << "Left Error: " << left_error << ", Left PWM: " << left_pwm << std::endl;
                std::cout << "Right Error: " << right_error << ", Right PWM: " << right_pwm << std::endl;
                break;
            }
        }
```

This loop checks if the duty cycle of the PWM signals is below 20. If this happens for 100 loops, the loop will break. This does result in the car not always being as precise as it perhaps could be, but removes any issues with the car getting stuck trying to drive a very small distance, never being able to overcome the internal resistance of the motors, which we deemed a worse outcome. 

When the loop breaks, the duty cycles for both motors are set to 0, to reduce the impact of the momentum the wheels/motors might have when exiting the loop, and then returns.

The function drive_distance(), works in very much the same way, except, of course, the wheels driving in different directions.


## PID

The PID class contains a key function called update(), which calculates a control output based on its inputs. The purpose of this function is to generate a control signal that drives the system, in this case a DC motor with encoder toward a desired target position. The function takes the following inputs: the target value the system should reach, the current measured value, a pointer to store the control output, and a threshold that determines when the integral term should be applied.

The first step in the function is to calculate the error, defined as the difference between the target value and the current value. This error represents how far the system is from the desired position and is used as the basis for all subsequent PID calculations. If the error is smaller than the integration threshold, the accumulated error variable is increased. This ensures that the integral term only contributes when the system is close enough to the target, preventing excessive accumulation.

Next, the proportional, integral, and derivative contributions are computed. The proportional term provides a corrective action directly proportional to the current error. When the motor is far from the target, this term generates a strong response to reduce the error quickly. As the motor approaches the target, the proportional term naturally decreases, preventing overshoot and unnecessary speed. The proportional value is equal to the current error.

The integral term addresses small, persistent errors that may remain due to friction, mechanical load, or system dead zones. By accumulating the error over time, the integral term ensures that the motor reaches the desired position accurately. It is calculated as the sum of the accumulated error multiplied by the time step.

The derivative term predicts the future trend of the error by measuring how quickly it is changing. If the motor is moving too rapidly toward the target, the derivative term applies a damping effect, reducing the control signal and helping to prevent overshoot or oscillations. The derivative value is computed as the difference between the current error and the previous error, divided by the time step.

After calculating the proportional, integral, and derivative contributions, each is multiplied by its respective tuning parameter. This yields a control value, which may be too large or too small for the hardware. To ensure safety and stability, the value is first squashed to stay within predefined minimum and maximum limits. Additionally, the rate of change of the control signal is limited to prevent abrupt increases or decreases. This ramp limiting helps maintain smooth acceleration and deceleration the motor.

Finally, for monitoring and debugging purposes, the function prints relevant information, including the current value, target value, control output, and error, every 50 iterations. This makes it much easier to observe since the time step is typically small.

```cpp
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
```

## Encoder

The encoder class uses poll() to handle a rotary encoder using event-based triggering. It monitors two GPIO pins corresponding to the A and B channels of the encoder. By detecting the order in which these pins go high and using a quadrature decoding lookup table, the code can determine whether the encoder is rotating forward or backward.

Before entering the main loop, the class sets up a structure containing the file descriptors needed by poll(), along with a lookup table that maps state transitions to position changes. All processing happens inside a loop that continues as long as the running_ flag remains true.

At the start of each loop iteration, poll() is called. This is a blocking call with an infinite timeout, meaning it will wait indefinitely until one of the monitored file descriptors becomes readable. Under normal operation, this happens whenever an edge is detected on one of the encoder’s GPIO pins. However, because the encoder may not always be moving for example, when the vehicle is stationary “wake pipe” is also included in the poll() set. Writing anything to this pipe makes it readable, causing poll() to return. If this wake-up event occurs, the loop exists.

When an event occurs on one of the GPIO pins, the function reads a gpioevent_data structure that indicates which pin triggered and whether the event was a rising or falling edge. Based on this information, the code reconstructs the new logical state of the encoder’s A and B signals. It then combines the previous state and the newly computed state into a 4-bit index. This index is used to access the quadrature decoding table, which determines whether the transition represents a step forward, a step backward, or an invalid transition. The resulting value is added to the encoder’s position counter.

Finally, the new A/B state becomes the stored last_state_, ensuring that the next detected edge will be interpreted correctly. This process repeats for every encoder event until the wake pipe is triggered or running_ is set to false, allowing the thread to shut down cleanly.

```cpp
void Encoder::monitor_events()
{
    struct gpioevent_data event_data;

    // Quadrature decoding lookup table
    const int8_t quad_table[16] = {0, -1, 1, 0,
                                   1, 0, 0, -1,
                                   -1, 0, 0, 1,
                                   0, 1, -1, 0};

    while (running_)
    {
        int ret = poll(poll_fds_, 3, -1);
        if (ret < 0)
            break;

        if (poll_fds_[2].revents & POLLIN) // wake pipe
        {
            char buf[8];
            read(wake_pipe_[0], buf, sizeof(buf));
            break;
        }

        for (int i = 0; i < 2; ++i)
        {
            if (poll_fds_[i].revents & POLLIN)
            {
                ssize_t bytes = read(poll_fds_[i].fd, &event_data, sizeof(event_data));
                if (bytes != sizeof(event_data))
                    continue;

                int a = (i == 0) ? (event_data.id == GPIOEVENT_EVENT_RISING_EDGE) : (last_state_ >> 1) & 1;
                int b = (i == 1) ? (event_data.id == GPIOEVENT_EVENT_RISING_EDGE) : last_state_ & 1;

                int current_state = (a << 1) | b;
                int index = (last_state_ << 2) | current_state;
                encoder_position_ += quad_table[index];
                last_state_ = current_state;
            }
        }
    }
}
```

\newpage