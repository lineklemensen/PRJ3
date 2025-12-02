# Tests
\newpage

## PID regulating

Pid is a class for controlling the acceleration of the motors and precisely hitting a specific location. This class was tested by creating a simulation of an encoder. This was done to separate the class from hardware. The class contains a bunch of setter and getter functions for all the different tuning parameters. These were all tested by calling the setter function and then calling the getter function and printing the result.

```cpp
Pid pid;
pid.set_dt(0.1);
pid.set_kp(0.6);
pid.set_ki(0.15);
pid.set_kd(0.6);
pid.set_ramp_limit(5.0);
pid.set_max_output(100);
pid.set_min_output(-100);

std::cout << "PID parameters set:\n"
            << "  dt=" << pid.get_dt() << " s\n"
            << "  kp=" << pid.get_kp() << "\n"
            << "  ki=" << pid.get_ki() << "\n"
            << "  kd=" << pid.get_kd() << "\n";
```

Aside from those functions the class also contains a reset function that sets a bunch of values used by the update function to zero. And a squash function that ensures that the pwm value never exceeds the max and min values. These were tested by running the update function and observing the result.

The update function is tested by running a loop that calls the update function repeatedly and simulates the encoder according to the result. Then the pwm value and position is written into a csv file. Using a python script those values are then read with pandas and plotted using matplotlib.

```cpp
for (int i = 0; i < 200; i++)
    {
        double ctrl;
        int pwm = pid.update(target, pos, &ctrl, INTEGRATION_THRESHOLD);

        // Update simulated encoder
        pos = simulate_encoder(pos, pwm);

        double t = i * pid.get_dt();

        // Write to CSV
        data_file << t << "," << pos << "," << ctrl << "," << pwm << "\n";
        data_file.flush();

        // Print to console
        std::cout << "t=" << t
                  << "s  pos=" << pos
                  << "  ctrl=" << ctrl
                  << "  pwm=" << pwm
                  << std::endl;

        // Stop early if close enough
        if (std::abs(target - pos) < 1.0)
        {
            std::cout << "Target reached.\n";
            break;
        }
    }
```