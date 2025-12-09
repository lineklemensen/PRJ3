# Tests

## Calculate route
DR is the class used for calculating the length and angle needed to drive from where the car currently is and where it needs to be. Testing this class, I put in every variation of points so that it would have to turn in every 90 degree turn available. This way there was an easy way to keep track of when the turn needed to be negative depending on where the car came from. The unit circle was used in deciding wether the turn was to be negative or positive. 

| Input X | Input Y | Expected output in degrees | Actual result |
| :-----: | :-----: | :------------------------: | :-----------: |
|    4    |    0    |             0              |       0       |
|    4    |    8    |             90             |      90       |
|    6    |    8    |            -90             |      -90      |
|    6    |    2    |            -90             |      -90      |
|    8    |    2    |             90             |      90       |
|    8    |   10    |             90             |      90       |
|    4    |   10    |             90             |      90       |
|    4    |    6    |             90             |      90       |
|    2    |    6    |            -90             |      -90      |
|    2    |    8    |            -90             |      -90      |
|    2    |    4    |            180             |      180      |

The first and last point inputted in the above table, is special cases handled independently in the code, to set the outputted angle to either 0 if the current point is our homebase, or if the angle is zero as it will only be that if we have to turn around.





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