# Software design

## Pc / Tui

### Empty class diagram

### Sequence diagram

![UC2 SD](docs/diagrams/out/apModel/SD UC2 - Create Delivery - PC.png){width=680px**

In order to aid developement we decided to go for a more general framework for making a TUI, this was done so we wouldn't need to hardcode the same button functionality repeatedly and instead could have a general button class that allows for a general "action" to be bound. 

On top of this several different UI elements can be made and easily added to the TUI, such as basic text elements and checkboxes.

### Full class diagram

## Server

    ### Empty class diagram

### Sequence diagram

The "server" is a very basic HTTP server. It supports handling incoming "orders" and should store them in a local log file as persistent storage. It has two routes "/new_route" and "/get_route" the first handles incoming orders from the pc, while the latter handles sending the order to the car when requested.

### Full class diagram

![UC2 SD](docs/diagrams/out/apModel/SD UC2 - Create Delivery - PC.png){width=680px**

## Car 

### Empty class diagram

The car has the following classes

**MotorController** uses the Encoder, Rpi_pwm and PID classes for controlling a motor. It takes input from the Encoder class and feeds it to the PID class, a PWM signal is then generated based on that. This along with some direction signals are then used for controlling the motors.

**Encoder** reads the rotary encoder on the motor using a thread.

**RPi_pwm** initializes and controls the PWM pins using hardware PWM.

**HttpHandler** handles the communication between the car and the server

**PID** ensures that the car accelerates and decelerates smoothly, and that it is capable of reaching a specific destination.

**Astar** calculates the optimal points for the car to drive through to reach the desired rooms.

**DR** calculates the degrees that needs to be turned and the distance that needs to be driven to reach a specific point. 

**main** is not a class but instead where all the classes are initialized and where the control loop can be found.

![Empty class diagram for the car](docs/diagrams/out/apModel/car_cd_empty/CarClasses.png){width=500px**}

### Sequence diagram

First all of the classes are initialized. This means all the constructors are called, the frequency and channel for pwm are set and threads for handler the encoders are started. The green LED and the action button is also initialized. To initialize the action button first a function for setting up poll is called. Then a thread is started and set to run the function monitor_act_btn(). 

Then we enter the main loop logic where first we hit a while(true) loop. Inside this loop there is a while loop that does nothing and exits when the action button is pressed. When the button has been pressed the car then sends a request to the server to get the rooms it has to visit. 

If the request fails the green led blinks for 5 seconds. 

If the request was a success the paths to reach all the rooms are then calculated. Then the paths are iterated through and and how to reach every point along the path to the first room is calculated. The car then turns and drives forward based on those calculations. Once the car reaches the first room it stops, the green LED turns on and it waits for a button press. 

When the button is pressed the car then repeats this for the next room until it reaches its home base. Here it waits for a button press to once again request what rooms it needs to visit.

![Sequence diagram for the car](docs/diagrams/out/apModel/car_sd/car_sd.png){width=500px**}

### Full class diagram

The class diagram shows all the classes from the empty class diagram, and the functions from the sequence diagram. It also shows all the functions that are not on the sequence diagram but classes has. The class diagram also shows the associations between the classes. main is also in the diagram even though its not a class. This is to show what functions are defined in main and its relations to the classes.

![Full class diagram for the car](docs/diagrams/out/apModel/car_cd/CarClasses.png){width=500px**}

\newpage