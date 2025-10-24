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

Initializing: The dispensary nurse clicks the Power button on the car.

what to do: car powers on, establish connection to server, sets this current location as home base.

### Use Case 2 Create route

pre: the car is idle

Initializing: The dispensary nurse opens the UI.

What to do: The dispensary nurse creates a route



### Use Case 3 Deliver and return

pre: pathfinding is done

Initializing: button is pressed

what to do: Car drives to the next point on the pathfinding route, stops, checks if it is a room or home base, if home base go idle, if room waits for button press and then loops around to pathfinding route. 


### Use Case 4 Shutdown

pre: the car is powered on

Initializing: the power off button is pressed:

what to do: sends shutdown message to server, power off

lots of expections....


\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 1 - Start \\
    \hline
    \textbf{Goal:} & The car is on and ready to request a route.\\
    \hline
    \textbf{Initialization:} & The dispensary nurse clicks the Power button on the car. \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Dispensary nurse\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is turned off. \\
    \hline
    \textbf{Postcondition:} & The car is turned on, and is connected to the network. \\
    \hline
    \textbf{Main scenario:} & 
    1. The car is positioned on the homebase. \par
    2. The Power button on the car is pressed. \par
    \hspace{0.5cm} [Exception 1: No power on the battery] \par 
    3. The car establishes a connection to the network. \par 
    \hspace{0.5cm} [Exception 2: Connection to network fails] \par
    4. Red LED turns on \\
    \hline
    \textbf{Extensions/Exceptions:} & [Exception 1: No battery power] \par
    \hspace{0.5cm} 1. The red LED does not turn on. \par
    [Exception 2: Connection to network fails] \par
    \hspace{0.5cm} 1. Red LED starts to blink. \\
    \hline
\end{tabularx}
\caption{Use Case 1 - Start}
\label{tab:usecase1}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 2 - Create route \\
    \hline
    \textbf{Goal:} & A route is created. \\
    \hline
    \textbf{Initialization:} & The dispensary nurse opens the UI. \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Dispensary nurse\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The system is running and functional.\\
    \hline
    \textbf{Postcondition:} & A route has been created and sent to the car. \par
    The car has finished pathfinding calculations. \\
    \hline
    \textbf{Main scenario:} & 
    1. The dispensary nurse opens the UI on the computer \par
    2. The screen displays a message: "Choose the rooms for this route". \par  
    A list of 3 rooms appear on the UI. \par 
    The screen displays instructions for selecting rooms. \par
    4. A "Finish" and "Cancel" option appears. \par
    5. The dispensary nurse selects up to 3 rooms \par
    \hspace{0.5cm} [Exception 1: The dispensary nurse selects the "Cancel" option] \par
    \hspace{0.5cm} [Extension 1: Room is already added] \par
    6. "Finish" option is selected.  \par
    \hspace{0.5cm} [Extension 2: No rooms were selected] \par
    7. The screen displays a confirmation message: "These are your chosen rooms:". \par
    A list of selected rooms is displayed. \par
    8. "Confirm" and "Deny" options appear on the screen. \par
    9.  The dispensary nurse selects the "Confirm" option. \par
    \hspace{0.5cm} [Extension 3: The dispensary nurse selects the "Deny" option] \par
    10. The route gets sent to the server. \par 
    11. The server saves the route to a log file. \par
    12. The UI on the screen clears. \par
    13. The screen displays: "The route has been successfully made". \par
    14. The screen display: "Press Enter key to close the UI." \par
    15. Enter key is pressed \par
    16. The UI closes \par
    \\
    \hline
    \textbf{Extensions/Exceptions:} & 
    [Exception 1: The dispensary nurse selects the "Cancel" option] \par
    \hspace{0.5cm} 1. Deselect all rooms. \par
    \hspace{0.5cm} 2. Close UI \par
    [Extension 1: Room is already added] \par
    \hspace{0.5cm} 1. Room is removed from selection \par 
    [Extension 2: No rooms were selected] \par
    \hspace{0.5cm} 1. An error message appears on the screen: "You did not choose \par 
    \hspace{1cm} any rooms for this route". \par
    \hspace{0.5cm} 2. Return to point 2 in the main scenario \par
    [Extension 3: The dispensary nurse selects the "Deny" option] \par
    \hspace{0.5cm} 1. Deselect all rooms. \par
    \hspace{0.5cm} 2. Return to point 2 in the main scenario. \\
    \hline
\end{tabularx}
    \caption{Use Case 2 - Create route}
    \label{tab:usecase2}
\end{table}


\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 3 - Complete delivery route \\
    \hline
    \textbf{Goal:} & The car completes the delivery route  \\
    \hline
    \textbf{Initialization:} & The "Power" button is pressed. \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} The dispensary nurse \par
    \textbf{Secondary:} Nurse \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is idle in the homebase.\\
    \hline
    \textbf{Postcondition:} & The car has completed the route and is back at the homebase.\\
    \hline
    \textbf{Main scenario:} &
    1. The car sends a request to the server to fetch route. \par
    \hspace{0.5cm} [Exception 1: No available routes] \par 
    \hspace{0.5cm} [Exception 2: Network Error] \par 
    2. The server sends the oldest received route to the car. \par
    3. The route is deleted from the server. \par
    4. The car receives the route and performs pathfinding calculations \par
    5. The green LED turns on. \par
    6. The "Action" button is pressed. \par
    7. The green LED turns off. \par
    8. The car waits 5 seconds. \par
    9. The car starts driving. \par
    10. The car arrives at the next location in the route, then stops. \par
    11. The green LED turns on. \par
    12. The car enters idle mode. \par
    13. The "Action" button is pressed. \par
    14. The green LED turns off. \par
    \hspace{0.5cm} [Extension 3: Remaining locations in the route (excl. homebase)] \par
    15. The car waits 5 seconds. \par
    16. The car starts driving. \par
    17. The car arrives and stops at the homebase. \par
    18. The car enters idle mode. \par
     \\
    \hline
    \textbf{Extensions/Exceptions:} &
    [Exception 1: No available routes] \par 
    \hspace{0.5cm} 1. The green LED starts blinking \par
    \hspace{0.5cm} 2. The car waits 5 seconds \par
    \hspace{0.5cm} 3. The green LED stops blinking \par
    \hspace{0.5cm} 4. The car enters idle mode \par

    [Exception 2: Network Error] \par 
    \hspace{0.5cm} 1. Red LED starts to blink \par
    \hspace{0.5cm} 2. The car waits 15 seconds \par
    \hspace{0.5cm} 3. Red LED stops to blink \par    
    \hspace{0.5cm} 4. The car enters idle mode \par

    [Extension 3: Remaining locations in the route (excl. homebase)] \par
    \hspace{0.5cm} 1. Return to point 4 in the main scenario.
     \\
    \hline
\end{tabularx}
    \caption{Use Case 3 - Complete delivery route}
    \label{tab:usecase3}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 4 - Shutdown of car \\
    \hline
    \textbf{Goal:} & The car is shutdown successfully \\
    \hline
    \textbf{Initialization:} & The "Power" button is pressed. \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Dispensary nurse \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is powered on, connected to the network, and is at the homebase \\
    \hline
    \textbf{Postcondition:} & The car is powered off \\
    \hline
    \textbf{Main scenario:} &
    1. The car stops any driving instructions \par
    2. The car powers off safely \par
     \\
    \hline
    \textbf{Extensions/Exceptions:} & \\
    \hline
\end{tabularx}
    \caption{Use Case 4}
    \label{tab:usecase4}
\end{table}
