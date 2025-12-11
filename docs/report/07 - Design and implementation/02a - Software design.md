# Software design

## Pc / Tui

### Empty class diagram

The Tui has the following classes

**TUI** the main class that controls most of the flow and action of the program

**Console** handles various console/terminal related functions, such as changing cursor position for printing, text color, and clearing the whole screen. 

**Input** handles detecting and reading input from the user/keyboard.

**Element** is a base class for all the different ui elements that are implemented, it supplies a basic interface for printing.

**TextElement** is the most basic ui element, only containing text to print.

**Button** is a basic multipurpose button that have a variety of functions assigned to perform on a specific input.

**StatefulButton** inherits the functionality of the `Button` class while also keeping track of its own state in a on/off sense.

**HTTPHandler** handles everything related to sending HTTP requests.

**Screen** is a base class that contains any number of ui elements and is used by the TUI's screen stack to present various information to the user.

**MainScreen** is the starting screen the user sees then opening the TUI.

**PopupScreen** is the confirmation dialogue that lets the user verify the route before it gets sent.


![Empty class diagram for TUI](docs/diagrams/out/apModel/PCClasses-Empty.png){width=400px}

\newpage
### Sequence diagram

In order to aid developement we decided to go for a more general framework for making a TUI, this was done so we would not need to hardcode the same button functionality repeatedly and instead could have a general button class that allows for a general "action" to be bound. 

On top of this several different UI elements can be made and easily added to the TUI, such as basic text elements and checkboxes.

The general flow of the program waits for user input and then depending on the input as well as which ui element is currently selected it will do different things.  
For any of the up, down, left or right inputs the "selected" cursor moves to the respective ui element. This has not been represented in the SD since it would not help much with understanding.  
There is a special case for when enter/space is input, since then it will run the associated function stored in the `action_` member of the `Button/StatefulButton`, however since this can be any arbitrary function, even complex lamdas, only the case of the "Confirm" button in the popup is represented in the SD.  

\begin{figure}
\begin{center}
\includegraphics[width=0.6\textwidth]{docs/diagrams/out/apModel/SD UC2 - Create Delivery - PC.png}
\caption{Sequence diagram for the TUI}
\end{center}
\end{figure}

\newpage
### Full class diagram

The class diagram shows all the classes as previously defined, as well as their relations and multiplicity.  
Additionally some helper structs and enums were added mainly as some data abstractions to improve the readability of the code. 

**Direction** is used for determining in which direction to automatically place ui elements in the case a position was not specified, as well as when connecting two elements.

**Color** has the specific flag combinataions required when setting the text color of the console/terminal.

**Key** is the different keys the user can input, although it doesn't correlate directly 1:1 with the actual keyboard keys, e.g both "W" and up arrow correspond to UP.

**Vec2** is a simple way of storing a 2D coordinate, used for positioning elements and the cursor for printing.

**Route** is the struct that actually gets converted to json and sent to the server, the member fields are identical to the struct of the same name in the car.

However since the structs and enums are used across many classes they do not have their arrows drawn as it would unnecessarily clutter the diagram.

![Full class diagram for the TUI](docs/diagrams/out/apModel/PCClasses.png)


\newpage
## Server

### Empty class diagram

**RouteHandler** decides which handler should handle the incoming request.

**LogHandler** stores the data given from RouteHandler and also returns the data that is asked for in RouteHandler. 



![empty class diagram for server](docs/diagrams/out/apModel/server_class_empty/ServerClasses.png)

### Sequence diagram

The "server" is a very basic HTTP server. It supports handling incoming "request" and should store them in a local log file as persistent storage. It has two routes "/new_route" and "get_route" the first handles incoming orders from the pc, while the latter handles sending the order to the car when requested.
![Sequence diagram for server](docs/diagrams/out/apModel/server_sd/server_sd.png)

### Full class diagram
**RouteHandler**
Sees incoming request and decides which handler should take the request.

**LogHandler**
Does all the functionallity of either GET or POST, by storing data inside a queue and then also taking all the elements inside queue and give it to the log file. 
  
![Full class diagram for server](docs/diagrams/out/apModel/server_classes/ServerClasses.png)

\newpage
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

![Empty class diagram for the car](docs/diagrams/out/apModel/car_cd_empty/CarClasses.png){width=500px}

\newpage

### Sequence diagram

First all of the classes are initialized. This means all the constructors are called, the frequency and channel for pwm are set and threads for handler the encoders are started. The green LED and the action button is also initialized. To initialize the action button first a function for setting up poll is called. Then a thread is started and set to run the function monitor_act_btn(). 

Then we enter the main loop logic where first we hit a while(true) loop. Inside this loop there is a while loop that does nothing and exits when the action button is pressed. When the button has been pressed the car then sends a request to the server to get the rooms it has to visit. 

If the request fails the green led blinks for 5 seconds. 

If the request was a success the paths to reach all the rooms are then calculated. Then the paths are iterated through and and how to reach every point along the path to the first room is calculated. The car then turns and drives forward based on those calculations. Once the car reaches the first room it stops, the green LED turns on and it waits for a button press. 

When the button is pressed the car then repeats this for the next room until it reaches its home base. Here it waits for a button press to once again request what rooms it needs to visit.

![Sequence diagram for the car](docs/diagrams/out/apModel/car_sd/car_sd.png){width=500px}

\newpage

### Full class diagram

The class diagram shows all the classes from the empty class diagram, and the functions from the sequence diagram. It also shows all the functions that are not on the sequence diagram but classes has. The class diagram also shows the associations between the classes. main is also in the diagram even though its not a class. This is to show what functions are defined in main and its relations to the classes.

![Full class diagram for the car](docs/diagrams/out/apModel/car_cd/CarClasses.png){width=500px}

\newpage