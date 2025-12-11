# System architecture


## Hardware architecture
The following sections will include hardware architecture for the system and the structure for the following sections are: block definition diagram(BDD), block description, internal block diagram(IBD) and signal description ending the hardware architecture section.
   
**Diagrams** these give a visual look into the physical components used along with the relationship between them. They also go in more dept about the signals that are present in the system.
  
**Tables** giving detailed descriptions of the contents in the different diagrams, these tables makes it possible to describe the overall function of blocks or go deeper and describe the function/usage of signals in/between the components. 

### Block Definition Diagram
The following BDD below contains 11 blocks each describing which parts and ports are used. BDD serves as a
skeleton of the system and captures the structure of the different components and their relationships to each other.
This diagram was developed in the early phases to give a basic understanding of how the system is modeled and
structured, it also gives insight into what physical components are present in the system.
![Block definition diagram](docs/diagrams/out/System Architecture/BDD (3).png)

### Block Description
A block description is made to describe each block inside the BDD and its function. Inside the table each block is a indicated by block name, function description, signals and comments.
  
\renewcommand{\arraystretch}{1.3}
\begin{longtable}[h!]{|p{2.5cm}|p{5cm}|p{2.2cm}|p{4.8cm}|}

    \hline
    \textbf{BlockName} & \textbf{Function Description} & \textbf{Signals} & \textbf{Comments} \\
    \hline
    \endfirsthead

    \hline
    \textbf{BlockName} & \textbf{Function Description} & \textbf{Signals} & \textbf{Comments} \\
    \hline
    \endhead

    \hline
    \endfoot

    \endlastfoot

    \hline
    \multirow{3}{5cm}{Power} & \multirow{3}{5cm}{Delivers power to the system} & PiCPower 5V & surplies power to RPi Car \\
    \cline{3-4}
    & & Mpower 6V & surplies power to the DC motors \\ 
    \cline{3-4}
    & & BPower 5V & surplies power to Buttons \\
    \hline 
    \multirow{7}{5cm}{DCMotor} & \multirow{7}{5cm}{DC motors that control the left and right front wheel respectivly} & MPower 6V & surplies power to the DCMotor \\
    \cline{3-4}
    & & MCmd PWM & Controls speed of DC motors \\ 
    \cline{3-4}
    & & EncoderA Bool & Delievers encoder information \\
    \cline{3-4}
    & & EncoderB Bool & Delievers encoder information \\
    \cline{3-4}
    & & DirA & Recieves instructions from RPiCar to either drive forward or reverse \\
    \cline{3-4}
    & & DirB & Recieves instructions from RPiCar to either drive forward or reverse \\
    \cline{3-4}
    & & Torque & The amount of force produced by the motors \\
    \hline
    \multirow{10}{5cm}{Raspberry pi 5} & \multirow{10}{5cm}{The control center of the car, where everything meets and connects} & PiCPower 5V & surplies power to RPi Car \\
    \cline{3-4}
    & & net & net is where the RPiCar connects to the wifi \\ 
    \cline{3-4}
    & & DataTransfer & DataTransfer is the HTTP request sent between the RPiServer and the RPiCar through the wifi \\
    \cline{3-4}
    & & PSignal & PSignal is the signal that goes from the Power button to the RPiCar to either turn it on or off \\
    \cline{3-4}
    & & ASignal & ASignal is the signal that goes from the Action button to the RPiCar, which when pressed activate the next action of the car \\
    \cline{3-4}
    & & LPower & LPower is power surply running from the RPiCar to the two LED's \\
    \cline{3-4}
    & & DirA & Tells the motor to either drive forward or reverse \\
    \cline{3-4}
    & & DirB & Tells the motor to either drive forward or reverse \\
    \cline{3-4}
    & & EncoderA & Recieves information from encoder A \\
    \cline{3-4}
    & & EncoderB & Recieves information from encoder B \\
    \hline
    \multirow{2}{5cm}{Green LED} & \multirow{2}{5cm}{The green LED on the car that lights up and blinks} & LPower & Where the LED recieves power from the RPiCar \\
    \cline{3-4}
    & & GLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar \\
    \hline
    \multirow{2}{5cm}{Red LED} & \multirow{2}{5cm}{The Red LED on the car that lights up and blinks} & LPower & Where the LED recieves power from the RPiCar \\
    \cline{3-4}
    & & RLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar \\
    \hline
    \multirow{3}{5cm}{Power button} & \multirow{3}{5cm}{The button used to turn on and off the car} & BPower & Where the button recieves power from the power surplies \\
    \cline{3-4}
    & & PSignal & The signal sent to the RPiCar to either turn on or off the car \\
    \cline{3-4}
    & & BPress & The signal on the button when it gets pressed \\
    \hline
    \multirow{3}{5cm}{Action button} & \multirow{3}{5cm}{The button used to make the car perform an action} & BPower & Where the button recieves power from the power surplies \\
    \cline{3-4}
    & & ASignal & The signal sent to the RPiCar to make the car perform an action \\
    \cline{3-4}
    & & BPress & The signal on the button when it gets pressed \\
    \hline
    \multirow{1}{5cm}{Computer} & \multirow{1}{5cm}{The computer used to run the UI on} & net & Where the computer connects to the internet \\
    \hline
    \multirow{2}{5cm}{RPiServer} & \multirow{2}{5cm}{The server that communicates between the car and the computer, logging and sending orders} & net & Where the server connects to the internet \\
    \cline{3-4}
    & & DataTransfer & DataTransfer is the HTTP request sent between the RPiServer and the RPiCar through the wifi \\
    \hline
    \multirow{5}{5cm}{Car} & \multirow{5}{5cm}{The car itself that drives a specified path calculated based on data from the server} & GLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar \\
    \cline{3-4}
    & & RLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar \\
    \cline{3-4}
    & & net & Where the car connects to the internet \\
    \cline{3-4}
    & & Torque & The amount of force produced by the motors \\
    \cline{3-4}
    & & BPress & The signal on the button when it gets pressed \\
    \hline
\caption{Block descriptions}
\end{longtable}

\newpage
### Internal Block Diagram
The IBD is used to dive deeper into the internal hardware of the car, it shows where each signal is going to/from for each component in the the car.
These signals include: voltage, PWM, high/low and etc. This tool makes sure that each signal is considered and how further development should follow. 
  
![Internal block diagram](docs/diagrams/out/System Architecture/IBD (2).png)  


### Signal Description
A signal description is done after the development of IBD, it helps to give an overview of all signals in the system.
The following table describes each signal and each row inside the table has: signal name, function, area, physical ports and comments. 
This table serves to give a structure over signals and communication between each component. 
  
\begin{longtable}[H] {|p{2.5cm}|p{4cm}|p{1.5cm}|p{2.6cm}|p{4cm}| }
\hline
\textbf{Signal name} & \textbf{Function} & \textbf{Area} & \textbf{Physical ports} & \textbf{Comments}\\
\hline
\endfirsthead

\hline
\textbf{Signal name} & \textbf{Function} & \textbf{Area} & \textbf{Physical ports} & \textbf{Comments}\\
\hline
\endhead

\hline
\endfoot

\hline
\endlastfoot

BPower & Gives power to the buttons & 5.0V & 2 GPIO & 2 GPIO pins is collective for the two buttons\\
\hline
MPower & Gives power to the DC motors & 6.0V & 2 GND \par 2 VCC & This is the collective of the 2 motors physical ports\\
\hline
PiCPower & Gives power to RPiCar & 5.0V & USB C & \\
\hline
RLPower & Gives power to the Red LED & 0V - 5.0V & GPIO pins & 0 too 5V since the LED is either turned on or turned off\\ 
\hline
GLPower & Gives power to the Green LED & 0V - 5.0V & GPIO pins & 0 too 5V since the LED is either turned on or turned off\\
\hline
MCMD & Sends PWM Signal to the motors to determine the speed of the car & 5.0V & 2 PWM pins & There is a PWM pin for each MCMD\\
\hline
EncoderA & Sends high or low signal to count encoder signal & 5.0V & 2 GPIO Pins & There is a GPIO pin for each encoder A\\
\hline
EncoderB & Sends high or low signal to count encoder signal & 5.0V & 2 GPIO pins & There is a GPIO pin for each encoder B\\
\hline
DirA & Determins if the motor goes forward, reverse or brakes & 5.0V & 2 GPIO pins & There is a GPIO pin for each DirA\\
\hline
DirB & Determins if the motor goes forward, reverse or brakes & 5.0V & 2 GPIO pins & There is a GPIO pin for each DirB\\
\hline
Torque & The amount of force release & & & \\
\hline
BPress & The press of the buttons & & & The physical press of one of the two buttons\\
\hline
ASignal & The signal given after the action button is pressed & 0V - 5.0V & & 0 too 5V since the button is either pressed or it is not\\
\hline
PSignal & The signal given after the action button is pressed & 0V - 5.0V & & 0 too 5V since the button is either pressed or it is not\\
\hline
RLSignal & RLSignal is the red light that is released into surroundings & & &\\
\hline
GLSignal & GLSignal is the green light that is released into surroundings & & &\\
\hline
DataTransfer & The HTTP data that gets transfered from the server to the car through wifi & & &\\
\hline
Net & The wifi that is used to connect server, car and computer & & Ethernet & \\
\hline
\caption{Signal description}
\end{longtable}


### Interfaces

## Software architecture
The following sections will include software architecture for the system and the structure for the following sections are: Domain model, System sequence diagram and System state machine diagram ending the software architecture section.

### Domain Model
A domain model serves to give a complete overview of the system as a whole and serving as a brigde between architecture and design. The domain model is a great way to create a collective understanding of the concepts, rules, limitation, relationship and more in our system.
  
The content of the domain model below shows:
  
**DispensoryNurse(DN)** The DN intereacts with the system through the TUI, ActionButton and PowerButton. DN intereact with the TUI to select which rooms are to be included in the creation of a route. The DN uses PowerButton to turn power on/off and ActionButton to initate the cars driving seqence.
  
**Nurse** The Nurse intereacts with the system through ActionButton to initate the cars driving seqence.
  
**TUI** gives the DN a way to create routes.
  
**HTTPHANDLER** stands for sending request to the Server from TUI.
  
**HTTPHANDLER_Car** stands for sending request to the Server from Car.
  
**PowerButton** turning power on or off to the Car.
  
**ActionButton** used to read input from button press and Car monitors its state. 
  
**Server** saves routes in a logHandler for backup, handles request from HTTPHANDLER and HTTPHANDLER_Car.
  
**LogHandler** creates a log file and stores all routes given to it. 
  
**H_brigde** controls Motor based on intructions given to it from Car.
  
**Car** gives instructions to H_bridge, monitors ActionButton state, tells HTTPHANDLER_Car to request route.
  
**Motor** is being controlled by H_bridge, and then drives in the given direction. 
  
**LED** used to indicate errors or if something is a succes. 
  
**Pathfinding** receives route from Server and uses the route to calculate a path for the Car to drive. 
![Domain model](docs/diagrams/out/Software architecture/domain/domain_model.png)

### System Sequence Diagram

### System State Machine Diagram
A STM is used to represent the condition and behavior of the system, this helps indicating what happens when the system is in a state and also what goes on when the system goes from one state to another. There are 4 states in the system: off, idle, driving and pathfinding. This diagram was make in the early phases of the project serving as an overview of how to handle the systems different states. 
  
![State machine diagram](docs/diagrams/out/Software architecture/System STM.png)

\newpage