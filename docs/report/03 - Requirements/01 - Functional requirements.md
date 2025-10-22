# Functional requirements

## Actor-Context Diagram

## Actor Description





\begin{tabularx}{0.8\textwidth}[H] { 
  | >{\raggedright\arraybackslash}X 
  | >{\raggedright\arraybackslash}X | }
 \hline
 \textbf{Actor name} & User \\
 \hline
 \textbf{Alternative reference} & Pharmaceutical Nurse  \\
\hline
\textbf{Actor type} & Primary  \\
 \hline
 \textbf{Description} & Reads what medecin is needed from GUI and packs it into the medecin box on the car and then press a start button \\
\hline
\end{tabularx}

\begin{tabularx}{0.8\textwidth}[H] { 
  | >{\raggedright\arraybackslash}X 
  | >{\raggedright\arraybackslash}X | }
 \hline
 \textbf{Actor name} & Patient nurse \\
 \hline
 \textbf{Alternative reference} & Dispensaries Nurse \\
\hline
\textbf{Actor type} & Secondary  \\
 \hline
 \textbf{Description} & Nurse opens and empties medecin box on the car, once the medecin box is empty the nurse closes the box and presses a return button \\
\hline
\end{tabularx}

\newpage

![Use case diagram](docs\diagrams\out\requirements\usecase diagram.png){width=440}

### Use Case 1 Start
Pre: Car is turned off

what to do: car powers on, establish connection to server, sets this current location as home base.

### Use Case 2 Idle

pre: UC 1 has been completed or UC5

what to do: Car sends a message to the server that it is on/return, puts cpu in standby/waiting mode. Then waits for new order from the system


### Use Case 3 Create order

pre: the car is idle




### Use Case 4 Deliver and return

pre: pathfinding is done

Initializing: button is pressed

what to do: Car drives to the next point on the pathfinding route, stops, checks if it is a room or home base, if home base go idle, if room waits for button press and then loops around to pathfinding route. 


### Use Case 5 Shutdown

pre: the car is powered on

Initializing: the power off button is pressed:

what to do: sends shutdown message to server, power off

lots of expections....


\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case  \\
    \hline
    \textbf{Goal:} & \\
    \hline
    \textbf{Initialization:} & \\
    \hline
    \textbf{Actors:} & \\  
    \hline
    \textbf{Concurrent instances:} & \\
    \hline
    \textbf{Precondition:} & \\
    \hline
    \textbf{Postcondition:} & \\
    \hline
    \textbf{Main scenario:} & 
    \\
    \hline
    \textbf{Extensions/Exceptions:} & 
    \\
    \hline
\end{tabularx}
    \caption{Use Case  - }
    \label{tab:usecase}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 1 - Start \\
    \hline
    \textbf{Goal:} & The car is on and ready \\
    \hline
    \textbf{Initialization:} & Dispensary nurse clicks the on/off button on the car \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Dispensary nurse\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & Car is turned off \\
    \hline
    \textbf{Postcondition:} & Car has connection to the server and a home base location is set \\
    \hline
    \textbf{Main scenario:} & 
    1. Dispensary nurse clicks the on/off button \par
    \hspace{0.5cm} [Exception 1: No power on battary] \par 
    1. Red LED turns on and holds a constant light to signal the car in powered \par
    2. Car establish connection to the server \par 
    \hspace{0.5cm} [Exception 2: Connection to server fails] \par 
    3. Path finding sets the cars current location as home base \par
    \hspace{0.5cm} [Exception 3: Set home base location fails] \\
    \hline
    \textbf{Extensions/Exceptions:} & [Exception 1: No battery power] \par
    \hspace{0.5cm} 1. The red LED does not turn on. \par
    [Exception 2: Connection to the server fails] \par
    \hspace{0.5cm} 1. Red LED starts to blink, to signal that something is wrong. \par
    [Exception 3: Set home base location fails] \par
    \hspace{0.5cm} 1. Red LED starts to blink to signal that something is wrong.
    \\
    \hline
\end{tabularx}
    \caption{Use Case 1 - Start}
    \label{tab:usecase1}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 2 - Create route (rooms to visit) \\
    \hline
    \textbf{Goal:} & The user wants to create an route \\
    \hline
    \textbf{Initialization:} & The user opens the UI \\
    \hline
    \textbf{Actors:} & Dispensary nurse - primary\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The system is running and functional \\
    \hline
    \textbf{Postcondition:} & An route has been created and sent to the car, the car has finished pathfinding calculations. \\
    \hline
    \textbf{Main scenario:} & 
    1. The dispensary nurse opens the UI on the computer \par
    2. On the screen a message saying "Choose the rooms for this route" and a list of all the 3 rooms appear on the UI. Underneath a message saying "Change selection via the Up and Down arrow keys. Hit the Enter key to add highlighted room to route." \par
    3. On the screen a Finish option and Cancel option appears. \par
    4. The dispensary nurse selects rooms (up to 3) via the Up/Down keys and confirms with Enter key on the Finish option.  \par
    \hspace{0.5cm} [Extension 1: The dispensary nurse selects the Cancel option, and hits the Enter key] \par
    \hspace{0.5cm} [Extension 2: No rooms were included in the route] \par
    5. Screen shows confirmation message "These are your chosen rooms:" followed by the rooms chosen. \par
    6. Confirm and Deny options appear on the screen. \par
    7. The dispensary nurse selects the Confirm option and hits Enter key. \par
    \hspace{0.5cm} [Extension 3: The dispensary nurse selects the Deny option, and hits the Enter key] \par
    8.  The route gets sent to the server. \par 
    9.  The server saves the route to a log file. \par
    10. The server receives a notification from a car that it is ready to receive an route. \par
    11. The server sends the oldest received route to the car. \par
    12. The car receives the route and performs its pathfinding calculations \par
    13. The cars' green LED lights up \par 
    14. The UI on the screen clears. \par
    15. A message saying "The route has been succesfully made" is printed on the screen. \par
    16. Wait 5 seconds \par
    17. The UI closes \par
    \\
    \hline
    \textbf{Extensions/Exceptions:} & 
    [Extension 1: The dispensary nurse selects the Cancel option and hits the Enter key] \par
    \hspace{0.5cm} 1. Deselect all rooms \par
    \hspace{0.5cm} 2. Return to point 2 in the main scenario \par
    [Extension 2: No rooms were included in the order] \par
    \hspace{0.5cm} 1. An error message saying "You did not choose any rooms for this \par \hspace{0.5cm} order" appears \par
    \hspace{0.5cm} 2. Return to point 2 \par
    [Extension 3: The dispensary nurse selects the Deny option, and hits the Enter key] \par
    \hspace{0.5cm} 1. Deselect all rooms \par
    \hspace{0.5cm} 2. Return to point 2 in the main scenario \par
    [Extension 4: There is no car available] \par
    \hspace{0.5cm} 1. Wait for car available notification \par
    \hspace{0.5cm} 2. Return to point 9 in main scenario
    \\
    \hline
\end{tabularx}
    \caption{Use Case 2 - Create order}
    \label{tab:usecase2}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 3 - Complete delivery route \\
    \hline
    \textbf{Goal:} & The car completes the delivery route  \\
    \hline
    \textbf{Initialization:} & Press of the start button \\
    \hline
    \textbf{Actors:} & The dispensary nurse - primary \par
    Nurse - secondary\\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is idle in the homebase\\
    \hline
    \textbf{Postcondition:} & The car has driven the given route and is back at homebase \\
    \hline
    \textbf{Main scenario:} &
    \hspace{0.5cm} [Extension 1: Pathfinding has not been completed] \par
    1. The green LED is turned on indicating that pathfinding has been completed \par
    2. The dispensary nurse presses the start button \par
    3. The green LED turns off \par
    4. The car waits 5 seconds \par
    5. The car starts driving \par
    6. The car arrives at the next location and stops \par
    7. The green LED lights up \par
    8. The car enters idle mode \par
    9. The nurse presses the button \par
    10. The green LED turns off \par
    11. The car checks that there are no more locations other than homebase left \par
    \hspace{0.5cm} [Extension 2: There are more locations remaining other than homebase] \par
    12. The car waits 5 seconds \par
    13. The car starts driving \par
    14. The car arrives and stops at the homebase \par
    15. The car sends the server a notification that it has arrived at the homebase \par
    16. The car enters idle mode \par
     \\
    \hline
    \textbf{Extensions/Exceptions:} &
    [Extension 1: Pathfinding has not been completed] \par
    \hspace{0.5cm} 1. The green LED is not turned  \par
    \hspace{0.5cm} 2. The dispensary nurse presses the start button \par
    \hspace{0.5cm} 3. End the Use Case \par
    [Extension 2: There are more locations remaining other than homebase] \par
    \hspace{0.5cm} 1. Return to point 4 in main scenario
     \\
    \hline
\end{tabularx}
    \caption{Use Case 3}
    \label{tab:usecase3}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 4 - Shutdown of car \\
    \hline
    \textbf{Goal:} & The car is shutdown successfully \\
    \hline
    \textbf{Initialization:} & The dispensary nurse presses the power button on the car \\
    \hline
    \textbf{Actors:} & \textbf The dispensary nurse - primary \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is powered on, connected to the server and at home base \\
    \hline
    \textbf{Postcondition:} & The car is powered off, the server is updated with the shutdown status of the car, the car is rinsed of pathfinding routes. \\
    \hline
    \textbf{Main scenario:} &
    1. The dispensary nurse presses the power button \par
    2. The car sends a shutdown message to the server \par
    \hspace{0.5cm}  [Extension 1: The server is unreachable] \par
    3. The server acknowledges and updates the car status to "inactive" \par
    \hspace{0.5cm}  [Extension 2: The car is mid-delivery] \par
    4. The car stops any driving instructions \par
    5. The car powers off safely \par
    \hspace{0.5cm} [Extension 4: Emergency stop or power failure]
     \\
    \hline
    \textbf{Extensions/Exceptions:} &
    [Extension 1: The server is unreachable] \par
    \hspace{0.5cm} 1. The car tries to send a message again.  \par
    \hspace{0.5cm} 2. Then the car shuts off. \par
    \hspace{0.5cm} 3. Use Case ends \par
    [Extension 2: The car is mid-delivery] \par
    \hspace{0.5cm} 1. The car stops \par
    \hspace{0.5cm} 2. The red LED lights up \par
    \hspace{0.5cm} 3. If the button is pressed again, the shuts off and does point 2.
    \hspace{0.5cm} 4. If not confirmed, shutdown is canceled \par
    [Extension 3: Emergency stop or power failure] \par
    \hspace{0.5cm} 1. The car immediately cuts motor power \par
    \hspace{0.5cm} 2. Sends message to server if possible \par
    \hspace{0.5cm} 3. Use Case ends \\
    \hline
\end{tabularx}
    \caption{Use Case 4}
    \label{tab:usecase4}
\end{table}
