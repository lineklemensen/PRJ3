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


\newpage