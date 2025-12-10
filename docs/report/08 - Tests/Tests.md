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

The Pid class is responsible for controlling motor acceleration and accurately driving the system toward a target position. To validate the controller independently from the hardware, the class was tested using a software-simulated encoder, allowing repeatable and deterministic testing.

\textbf{Parameter Accessors}  
The class provides setter and getter functions for all tuning parameters (e.g., kp, ki, kd, dt, output limits, and ramp limits). These accessors were verified by setting each parameter and immediately reading it back:

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

\textbf{Auxiliary Functions}  
Besides the accessors, the class includes:

reset() — clears all internal state variables used by the update loop (integral term, previous error, etc.).

squash() — clamps the controller output to the configured min_output and max_output values to protect the motor driver.

These were validated indirectly by observing changes in the controller behavior during runtime.

\textbf{Update-Loop Testing}  
The core of the testing focused on the update() function. A closed-loop simulation was created where the PID output controls a virtual motor encoder. Each iteration computes a new PWM command, updates the simulated position, and logs the results:

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
The resulting CSV file was analyzed using a Python script that loads the data via pandas and visualizes the controller response using matplotlib. These plots allowed evaluation of settling time, overshoot, stability, and convergence behavior.