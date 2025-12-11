# Tests
## Hardware
Before spending time physically making the hardware multisim was used to check if the hardware would work in a simulation. After simulating it and that not working, one of the workers in Elab was contacted to hear their advise on what to do. A conclusion that the simulation was not working was then reached. Then once it had been soldered a multimeter was used to check the regulator was working as intended.   

There was used a Analog Discovery to test the signals for controlling the motors. The transistors was tested by using signals sent through the pins on the RPi5, to see if it would open and close the transistors, which would in turn turn on or off the LED's. Then the button was tested by connecting its pin to the RPi5, and checking if we could read the signal from a button press, and if we held the button if that could be read as high and as low when not, which both worked. After the full implementation we could test the drive with the full weight of all parts. 

\newpage

## Module tests

### Calculate route
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

\newpage

### PID regulating

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

reset() - clears all internal state variables used by the update loop (integral term, previous error, etc.).

squash() - clamps the controller output to the configured min_output and max_output values to protect the motor driver.

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

\newpage
### MotorController & PID Tuning

The MotorController class is responsible for driving the car. The class uses a function, drive(), to set the speed and direction for both motors.

The functionality of this was tested by calling the function at intervals, with increasing duty cycles and altering directions, and observing if the speed of the wheels increased as expected.

```cpp
// Initialize MotorController
    MotorController motors;
    usleep(100000); // wait for initialization
    motors.drive(30, 30); // 30% speed
    usleep(1000000); // wait 1 second
    motors.drive(50, 50); // 50% speed
    usleep(1000000); // wait 1 secong
    motors.drive(-30, 30); // 30% speed, different directions
    
```

At the same time, the Encoder class was also verified to function properly, by simply observing whether or not the encoder positions would change in accordance to the movement of the motors

The logic for handling acceleration/deceleration and distance, takes place in drive_distance(), and turn(). Initially the function would simply keep updating the duty cycle of the PWM signal, using the PID class, and passing these values off to drive(), stopping when both encoders were within 10 encodes pulses of the target.

```cpp
if (left_error < 10 && right_error < 10)
        {
            std::cout << "Left Error: " << left_error << ", Left PWM: " << left_pwm << std::endl;
            std::cout << "Right Error: " << right_error << ", Right PWM: " << right_pwm << std::endl;
            break;
        }
```

This solidified the core functionality of the function, but the motors were very unprecise, as we hadn't performed any tuning of the PID regulation yet. The PID tuning was done by first slowly increasing the KP value, until the motor would start, rather violently, oscilating once it came close enough to its target, trying to zero in on a specific value, but accelerating too fast to hit within our accepted error margin. Once this behaviour was achieved, we cut the KP value in half, and started increasing the KD value, which largely affects the deceleration, as the motor would overshoot in its current state. We kept slowly increasing KD, until the motor would undershoot the target by ~20-30 encoder pulses. At this point, we started increasing the KI value very slowly, to smooth out the last errors, leading to the motor landing within ~5 pulses of the target consistently, which was well within our error range. This process was then repeated for the second motor. Throughout the tuning process, the python script used for testing the PID regulation, was also used, to gain a visual understanding of the behaviour of the system.

![Example of graph from PID tuning](docs/diagrams/out/Tests/pidTuningExample.png){ width=60% }

During this process, it became apparent that the motors would not drive if they received a PWM signal with a duty cycle < 31, so a clamp was added to drive(), ensuring the motors would always drive when they were supposed to.

```cpp
// Clamp PWM duty cycle, as motors won't run at at duty cycle < 35
    if (left_duty < 31 && left_duty != 0 && left_duty > 0)
    {
        left_duty = 31;
    }

    if (right_duty < 31 && right_duty != 0 && right_duty > 0)
    {
        right_duty = 31;
    }
```

However, even with this clamp, we still encounter situations where one of the motors would end slightly outside of our target range, and wouldn't go further, so another break condition was added. If the duty cycle of the PWM signal is < 20, for a sufficient amount of time, the car would be considered to be at its target. This sacrifised some precision, but eliminated the chance of the car getting stuck, trying to drive the last ~5 pulses. 

```cpp
if (std::abs(left_pwm) < 20 && std::abs(right_pwm) < 20)
        {
            ++m;
            if (m > 100)
            {
                std::cout << "Left Error: " << left_error << ", Left PWM: " << left_pwm << std::endl;
                std::cout << "Right Error: " << right_error << ", Right PWM: " << right_pwm << std::endl;
                break;
            }
        }
```

\newpage

### Raspberry Pi Setup (rpi1)

The Rpi controlling the car required a bit of setup as well. Firstly the PWM chip had to be enabled, as otherwise we wouldn't be able to generate a PWM signal to control the car. This was done by adding the following line to config.txt.
```bash
dtoverlay=pwm-2chan
```
To generate the PWM signal, we used the class RPi_pwm, which is based on public a wrapper, found at https://github.com/berndporr/rpi_pwm. The functionality was verified using an oscilloscope, which clearly showed a PWM signal to the specifications of our code.

Another line was also added to config.txt, that enables safe shutdown of the Raspberry Pi, when clicking its dedicated power button. This was achieved as shown below.
```bash
dtoverlay=rpi-power-button
```
This functionality was verified by simply turning the Pi off as described, which prints a message, indicating a safe shutdown. 

We also needed to set a couple of GPIO pins to output/input, which controlled the LEDs and button, as well as a gate to enable power to the Motor Driver. These pins were also set through the config.txt file. The functionality of the was verified through visual observation, as the LEDs turned on as expected, and the LED on the Motor Driver also lit up.
```bash
gpio=25=op,dh
gpio=8=op,dl
gpio=7=op,dh
gpio=1=ip
```
Lastly, a service was created to run on startup, which ultimately was supposed to run our program, after the Pi had established an internet connection. At first, this service ran a dummy script, that simply created a text file, to test if the service worked as expected.

```bash
[Unit]
Description=Run script on startup
Wants=network-online.target
After=network-online.target

[Service]
Type=oneshot
User=au769402
ExecStart=/home/au769402/projekt/startUpScript.sh

[Install]
WantedBy=multi-user.target
```

When the time came to have it run the program itself, we encountered issues with the Pi not booting. At first we suspected that the service type was wrong, and that was causing the issue, so we changed it from oneshot to simple, since we thought oneshot type may have gotten 'unhappy' from getting stuck in the program, as it runs indefintely. However, this had no effect, and the Pi would still not boot, so eventually we decided to ditch this functionality, and simply run the program through a remote SSH connection.

\newpage

### Astar

The Astar class is responsible for calculating the optimal path between the points given on the grid-based map, whilst taking into account for obstacles and the car's movement constraints. The routing system is important to ensure the car always receives valid and drivable waypoint sequences, the astar implementation was tested thoroughly using a series of controlled grid layouts.
\newline
In order to validate its correctness, a hardcoded 2D map was made with the same dimensions and obstacles used for field test of the car. The tests consisted of a pair of start and end coordiantes, which always was the same, along with an expected path lenght (measured in number of grid steps). The goal during tesint was to confirm the following. \newline

Astar returns a path whenever a valid route exists. \newline
\newline
The returned paths always avoid the obstacles. \newline
\newline
The algorithm correctly identifies when no valid route exists. \newline
\newline
The path found is the optimal, shortest, path for the given configuration. \newline
\newline


**Basic functionality tests**

Firstly, its nice to see that it can calculate the steps given in the four cardinal directions. These act as sanity checks to ensure the algorithm handles the simplest cases correctly.

| Start | Goal  | Expected path length | Actual path length |
| :---: | :---: | :------------------: | :----------------: |
| (0,0) | (5,0) |          6           |         6          |
| (2,2) | (2,7) |          6           |         6          |
| (0,0) | (5,5) |          10          |         10         |

All the tests matched the expected lengths, confirming that the Manhattan-distance heuristic aligned correctly with the grid movement model. \newline

**Obstacle avoidance tests**

The batch of tests is placing static obstacles in the map and check if the astar correctly routed around them. These tests are essential to validate the cost of calculations and neighbor evaluation logic.

| Start | Goal  |      Map description      |          Expected result           |            Actual result             |
| :---: | :---: | :-----------------------: | :--------------------------------: | :----------------------------------: |
| (0,0) | (5,0) |   Wall blocking x=2...4   | Valid path bending around obstacle | Path returned, detouring as expected |
| (1,1) | (7,1) | Multiple staggered blocks |    Shortest valid zig-zag path     |   Path returned, identical length    |
| (3,0) | (3,5) |    Solid vertical wall    |        Solid vertical wall         |            no valid route            | Correctly returned "no path" |

These tests confirmed that the algorithm checks neighbors correctly, avoids illegal tiles, and terminates when no solution exists.

**Integration testing with route execution**

The last test made was validating that the output path was compatible with the driving logic. The path was fed directly into the distance/rotation (DR) class to verify the following. \newline

Every step in the astar output produced a valid movement command. \newline
No illegal diagonal or backward steps were generated. \newline
The angle changes between steps always matched the DR class expectations. \newline

The resulting behavior confirmed that astar outputs clean, grid-aligned paths perfectly suitable for real-world execution. 


### Server test
Firstly after the server is running a goggle chrome fan was opened to test if it was possible to access the the URL that the server is hosted on, this was done by looking at the terminal in the server to see if a connection was established which was successful. 
Since connection is possible the request handlers needed to be tested to see if request was handled correct, this was tested with Postman used to do GET and POST request, POST test was successful  with the queue getting elements inside it, and log file also updating along side the queue. GET was also a success since the first element in queue was removed and the log file again updating according to what the queue had in it. 
\newpage

### Tui

Most of the testing for developing the TUI was done iteratively during developement, where any visual errors 

\begin{figure}[H]
\centering
    \begin{subfigure}{.5\textwidth}
        \centering
        \includegraphics[width=0.95\textwidth]{docs/diagrams/out/Tests/Mainscreen.png}
        \caption{Main screen of tui}
    \end{subfigure}%
    \begin{subfigure}{.5\textwidth}
        \centering
        \includegraphics[width=0.95\textwidth]{docs/diagrams/out/Tests/Popupscreen.png}
        \caption{Pop up in tui}
    \end{subfigure}
\caption{Tui screens}
\end{figure}

\newpage

## Integration test

To begin integrating our system, we first equipped the motors and wheels to the car, and running a simple test program that, theoretically, had the car drive in a straight line. We had been aware, since PID tuning, that the two motors were not exactly equal, as their tunings had to be different to achieve the same behaviour, but once the wheels came under load from the weight of the car, it quickly became apparent that this had different effect on the two motors, resulting in the car becoming very unprecise, and getting stuck in many situations. We changed the clamp, to now have the minimum duty cycle be 35, which prevented the car from getting stuck, but it was still unable to drive in a straight line, as one motor would turn more than the other, even with exactly the same PWM signal. To combat this, we started adjusting the PWM signal, based on how far away both motors were from their respective target. If a motor sagged behind, the duty cycle for that motor would be increased, and decreased for the other, based on the ratio of the errors.

```cpp
const double adjust_factor = (std::abs(right_error) / (std::abs(left_error) == 0 ? std::abs(right_error) 
                            : std::abs(left_error))) - 1;

        left_pwm *= 1 - adjust_factor * 4;
        right_pwm *= 1 + adjust_factor * 4;
        // Clamp values [-100, 100] to avoid silly stuff
        left_pwm = std::max(-100, std::min(100, left_pwm));
        right_pwm = std::max(-100, std::min(100, right_pwm));
```

This resulted in the car being able to drive in a straight line again, but turning would continue to be an issue, also in part due to the back wheel getting stuck when we would turn after driving straight, which remains as an issue we have been unable to fix. 

To test the creation of routes and storing of these on the server, we ran the Terminal UI and server on the same network, and created multiple routes. The server was then accessed using a remote SSH connection, and the file "logger.txt" was opened. The file contained all the created routes, indicating a successful integration. 

Lastly, the car itself had to be integrated to work with the server/TUI, which mostly consisted of being able to retrieve routes from the server, and the correct time, and correctly loading the right values into the functions that handle the driving, as well as handling the LEDs and Action button.

All 3 main elements were added to a new main program, that initialises the appropriate objects, and then waits for a press of the Action button, before requesting a route from the server. This was successful, verified through confirmation messages in a terminal with a remote SSH connection to the rpi1. After another press of the Action button, the car starts driving, as specified in our Use Cases. 
Keeping in mind the problems with the motors, our main focus was that the car would follow the "pattern" of the route, even if the car over/undershoot while turning. Observing the car, it was clear that the route had been successfully changed into driving commands, as the would follow the correct pattern of the route, for example, driving straight, turning left, driving straight, turning right, driving straight and then stopping, which was verified by comparing the cars behaviour to the map in our code. Unfortunately, the car would often not end up precisely at the designated end point, due to over/underturning, because of reasons explained earlier.

Afterwards, the behaviour of the LEDs were integrated to our specifications and verified through running the program and observing them.