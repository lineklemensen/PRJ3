# System architecture

## Hardware architecture

### Block Definition Diagram

\begin{tabularx}{0.8\textwidth}[H] { | X | X | X | X | }
\hline 
\textbf{BlockName} & \textbf{Function Description} & \textbf {Signals} & \textbf{Comments} \\
\hline
\multirow{4}{4em}{\textbf{Power}}  & \multirow{4}{4em}{\textbf{Delivers power to the system}} & PiCPower 5V & surplies power to RPi Car \\
\cline{3-4}
& & Mpower 6V & surplies power to the DC motors \\ 
\cline{3-4}
& & BPower 5V & surplies power to Buttons \\
\hline
\multirow{4}{4em}{\textbf{DCMotor}}  & \multirow{4}{4em}{\textbf{DC motors that control the left and right front wheel respectivly}} & MPower 6V & surplies power to the DCMotor \\
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
\multirow{4}{4em}{\textbf{Raspberry pi 5}}  & \multirow{4}{4em}{\textbf{The control center of the car, where everything meets and connects}} & PiCPower 5V & surplies power to RPi Car \\
\cline{3-4}
& & net & net is where the RPiCar connects to the wifi \\ 
\cline{3-4}
& & DataTransfer & DataTransfer is the HTTP request sent between the RPiServer and the RPiCar through the wifi \\
\cline{3-4}
& & PSignal & PSignal is the signal that goes from the Power button to the RPiCar to either turn it on or off\\
\cline{3-4}
& & ASignal & ASignal is the signal that goes from the Action button to the RPiCar, which when pressed activate the next action of the car\\
\cline{3-4}
& & LPower & LPower is power surply running from the RPiCar to the two LED's\\
\cline{3-4}
& & DirA & Tells the motor to either drive forward or reverse\\
\cline{3-4}
& & DirB & Tells the motor to either drive forward or reverse\\
\cline{3-4}
& & EncoderA & Recieves information from encoder A\\
\cline{3-4}
& & EncoderB & Recieves information from encoder B\\
\hline
\multirow{4}{4em}{\textbf{Green LED}} & \multirow{4}{4em}{\textbf{The green LED on the car that lights up and blinks}} & LPower & Where the LED recieves power from the RPiCar \\
\cline{3-4}
& & GLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar\\
\hline
\multirow{4}{4em}{\textbf{Red LED}} & \multirow{4}{4em}{\textbf{The Red LED on the car that lights up and blinks}} & LPower & Where the LED recieves power from the RPiCar \\
\cline{3-4}
& & RLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar\\
\hline
\multirow{4}{4em}{\textbf{Power button}} & \multirow{4}{4em}{\textbf{The button used to turn on and off the car}} & BPower & Where the button recieves power from the power surplies\\
\cline{3-4}
& & PSignal & The signal sent to the RPiCar to either turn on or off the car\\
\cline{3-4}
& & BPress & The signal on the button when it gets pressed\\
\hline
\multirow{4}{4em}{\textbf{Action button}} & \multirow{4}{4em}{\textbf{The button used to make the car perform an action}} & BPower & Where the button recieves power from the power surplies\\
\cline{3-4}
& & ASignal & The signal sent to the RPiCar to make the car perform an action\\
\cline{3-4}
& & BPress & The signal on the button when it gets pressed\\
\hline
\multirow{4}{4em}{\textbf{Computer}} & \multirow{4}{4em}{\textbf{The computer used to run the UI on}} & net & Where the computer connects to the internet\\
\hline
\multirow{4}{4em}{\textbf{RPiServer}} & \multirow{4}{4em}{\textbf{The server that communicates between the car and the computer, logging and sending orders}} & net & Where the server connects to the internet\\
\cline{3-4}
& & DataTransfer & DataTransfer is the HTTP request sent between the RPiServer and the RPiCar through the wifi\\
\hline
\multirow{4}{4em}{\textbf{Car}} & \multirow{4}{4em}{\textbf{The car itself that drives a specified path calculated based on data from the server}} & GLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar\\
\cline{3-4}
& & RLSignal & The light that hit the surroundings after the LED recieves power from the RPiCar\\
\cline{3-4}
& & net & Where the car connects to the internet\\
\cline{3-4}
& & Torque & The amount of force produced by the motors\\
\cline{3-4}
& & BPress & The signal on the button when it gets pressed\\
\hline
\end{tabularx}
### Internal Block Diagram
\begin{tabularx}{0.8\textwidth}[H] { | X | X | X | X | X | }
\hline
\textbf{Signal name} & \textbf{Function} & \textbf{Area} & \textbf{Physical ports} & \textbf{Comments}\\
\hline
BPower & Gives power to the buttons & 5.0V & 2 GPIO & 2 GPIO pins is collective for the two buttons\\
\hline
MPower & Gives power to the DC motors & 6.0V & 2 GND, 2 VCC & This is the collective of the 2 motors physical ports\\
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
\end{tabularx}
### Interfaces

## Software architecture

### Domain Model

### System Sequence Diagram

### State Machine Diagram

\newpage