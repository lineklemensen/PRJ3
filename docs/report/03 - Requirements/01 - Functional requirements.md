# Functional requirements

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
    \textbf{Name:} & Use Case 4 - Deliver order and return \\
    \hline
    \textbf{Goal:} & \\
    \hline
    \textbf{Initialization:} & \\
    \hline
    \textbf{Actors:} & \\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
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
    \caption{Use case 1 - Create order}
    \label{tab:usecase1}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 1 - Start \\
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
    \textbf{Main scenario:} & 1. Dispensary nurse clicks the on/off button \par
    \hspace{1cm} [Exception 1: No power on battary] \par 
    2. Red LED turns on and holds a constant light to signal the car in powered \par
    3. Car establish connection to the server \par 
    \hspace{1cm} [Exception 2: Connection to server fails] \par 
    4. Path finding sets the cars current location as home base \par
    \hspace{1cm} [Exception 3: Set home base location fails] \\
    \hline
    \textbf{Extensions/Exceptions:} & [Exception 1: No battery power] \par
    \hspace{1cm} 1. The red LED does not turn on. \par
    [Exception 2: Connection to the server fails] \par
    \hspace{1cm} 1. Red LED starts to blink, to signal that something is wrong. \par
    [Exception 3: Set home base location fails] \par
    \hspace{1cm} 1. Red LED starts to blink to signal that something is wrong.
    \\
    \hline
\end{tabularx}
    \caption{Use case 1 - Start}
    \label{tab:usecase1}
\end{table}


\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use Case 2 - Idle \\
    \hline
    \textbf{Goal:} & \\
    \hline
    \textbf{Initialization:} & \\
    \hline
    \textbf{Actors:} & \\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
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
    \caption{Use case 1 - Create order}
    \label{tab:usecase1}
\end{table}


\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 3 - Create order \\
    \hline
    \textbf{Goal:} & The user wants to create an order \\
    \hline
    \textbf{Initialization:} & The user opens the UI \\
    \hline
    \textbf{Actors:} & Dispensary nurse - primary\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The system is running and functional \\
    \hline
    \textbf{Postcondition:} & An order has been created and sent to the car, the car has finished pathfinding calculations. \\
    \hline
    \textbf{Main scenario:} & 
    1. The dispensary nurse opens the UI \par
    2. A message saying "Choose the rooms for this order" and a list of all the 3 rooms appear on the UI\par
    3. Finish and cancel options appear \par
    4. The dispensary nurse chooses up to 3 rooms to add to the order \par
    5. The dispensary nurse clicks finish order \par
    [Extension 1: The dispensary nurse selects the cancel option] \par
    [Extension 2: No rooms were selected] \par
    6. A confirmation message saying "This is your chosen rooms" and a list of the rooms chosen appears \par
    7. Confirm and deny options appear \par
    8. The dispensary nurse selects the "Confirm" option \par
    [Extension 3: The dispensary nurse selects the "Deny" option] \par
    9. The order gets sent to the server \par 
    10. The server receives the order \par
    11. The server saves the order in a text file \par
    12.  The server sends the order to the car \par
    [Extension 4: There is no car available] \par
    13. The car receives the order \par
    14. The car does its pathfinding calculations \par
    15. The cars green LED lights up \par 
    16. The UI clears \par
    17. A message saying "A order has been succesfully made" \par
    18. Wait 5 seconds \par
    19. The UI closes \par
    \\
    \hline
    \textbf{Extensions/Exceptions:} & 
    [Extension 1: The dispensary nurse selects the cancel option] \par
    \hspace{1cm} 1. Deselect all rooms \par
    \hspace{1cm} 2. Return to point 2 in the main scenario \par
    [Extension 2: No rooms were selected] \par
    \hspace{1cm} 1. An error message saying "You did not choose any rooms for this \par \hspace{1cm} order" appears \par
    \hspace{1cm} 2. Return to point 2 \par
    [Extension 3: The dispensary nurse selects the "Deny" option] \par
    \hspace{1cm} 1. Deselect all rooms \par
    \hspace{1cm} 2. Return to point 2 in the main scenario \par
    [Extension 4: There is no car available] \par
    \hspace{1cm} 1. Wait for car available notification \par
    \hspace{1cm} 2. Return to point 9 in main scenario
    \\
    \hline
\end{tabularx}
    \caption{Use case 3 - Create order}
    \label{tab:usecase3}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 4 - Deliver and return \\
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
    \textbf{Precondition:} & The pathfinding calculations has been done and the green LED is turned on\\
    \hline
    \textbf{Postcondition:} & The car has driven the given route and is back at homebase \\
    \hline
    \textbf{Main scenario:} &
    1. The dispensary nurse presses the start button \par
    2. The green LED turns off \par
    3. The car waits 1 second \par
    4. The car starts driving \par
    5. The car arrives at the next location and stops \par
    6. The green LED lights up \par
    7. The CPU enters waiting \par
    8. The nurse presses the button \par
    9. The green LED turns off \par
    10. The car checks that there are no more locations other than homebase left \par
    [Extension 1: There are more locations remaining other than homebase] \par
    11. The car waits 1 second \par
    12. The car starts driving \par
    13. The car arrives and stops at the homebase \par
    14. The car sends the server a notification that it has arrived at the homebase \par
    15. The CPU enters waiting \par
     \\
    \hline
    \textbf{Extensions/Exceptions:} &
    [Extension 1: There are more locations remaining other than homebase] \par
    \hspace{1cm} 1. Return to point 2 in main scenario
     \\
    \hline
\end{tabularx}
    \caption{Use case 5}
    \label{tab:usecase5}
\end{table}



\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 5 - Shutdown of car \\
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
    [Extension 1: The server is unreachable] \par
    3. The server acknowledges and updates the car status to "inactive" \par
    [Extension 2: The car is mid-delivery] \par
    4. The car stops any driving instructions \par
    5. The car powers off safely \par
    [Extension 4: Emergency stop or power failure]
     \\
    \hline
    \textbf{Extensions/Exceptions:} &
    [Extension 1: The server is unreachable] \par
    \hspace{1cm} 1. The car tries to send a message again.  \par
    \hspace{1cm} 2. Then the car shuts off. \par
    \hspace{1cm} 3. Use case ends \par
    [Extension 2: The car is mid-delivery] \par
    \hspace{1cm} 1. The car stops \par
    \hspace{1cm} 2. The red LED lights up \par
    \hspace{1cm} 3. If the button is pressed again, the shuts off and does point 2.
    \hspace{1cm} 4. If not confirmed, shutdown is canceled \par
    [Extension 3: Emergency stop or power failure] \par
    \hspace{1cm} 1. The car immediately cuts motor power \par
    \hspace{1cm} 2. Sends message to server if possible \par
    \hspace{1cm} 3. Use case ends \\
    \hline
\end{tabularx}
    \caption{Use case 5}
    \label{tab:usecase5}
\end{table}

\newpage