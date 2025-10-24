# System architecture

## Hardware architecture

### Block Definition Diagram

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
\end{longtable}

\newpage
### Internal Block Diagram

### Interfaces

## Software architecture

### Domain Model

### System Sequence Diagram

### State Machine Diagram

\newpage