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
    \textbf{Name:} & Use case 1 - Start\\
    \hline
    \textbf{Goal:} & Turning the car on and initializing the software\\
    \hline
    \textbf{Initialization:} & The power button is pressed\\
    \hline
    \textbf{Actors:} & Dispensary nurse - primary\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is turned off\\
    \hline
    \textbf{Postcondition:} & The car is turned on and initialized\\
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
    \textbf{Main scenario:} & 1. The dispensary nurse opens the UI \par
    1. A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI \par
    2. The dispensary nurse chooses the rooms they want up to a maximum of 3 \par
    [Extension 1: The dispensary nurse does not choose any rooms] \par
    [Extension 2: The dispensary nurse chooses more than 3 rooms] \par
    3. The dispensary nurse clicks finish order \par
    4. A confirmation message saying "This is your chosen rooms" and a list of the rooms chosen appears \par
    5. The dispensary nurse clicks "Confirm" \par
    [Extension 3: The dispensary nurse clicks "Deny"] \par
    6. The order gets sent to the server \par 
    7. The server receives the order \par
    8. The server saves the order in a text file \par
    9.  The server sends the order to the car \par
    10. The car receives the order \par
    11. The car does its pathfinding calculations \par
    12. The cars green LED lights up \par 
    \\
    \hline
    \textbf{Extensions/Exceptions:} & [Extension 1: The dispensary nurse does not choose any rooms] \par
    \hspace{1cm} 1. The dispensary nurse clicks finish order \par
    \hspace{1cm} 2. An error message saying "You did not choose any rooms for this \par \hspace{1cm} order" appears \par
    \hspace{1cm} 3. Return to point 2 \par
    [Extension 2: The dispensary nurse chooses more than 3 rooms] \par
    \hspace{1cm} 1. 
    [Extension 3: The dispensary nurse clicks "Deny"] \par
    \hspace{1cm} 1. Return to point 2
    \\
    \hline
\end{tabularx}
    \caption{Use case 1 - Create order}
    \label{tab:usecase1}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 4 - Deliver and return \\
    \hline
    \textbf{Goal:} & The delivered drove the given route  \\
    \hline
    \textbf{Initialization:} & Press of the start button \\
    \hline
    \textbf{Actors:} & \textbf The dispensary nurse - primary \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The pathfinding has been done \\
    \hline
    \textbf{Postcondition:} & The car have driven the given route and is back at home base \\
    \hline
    \textbf{Main scenario:} &
    1. The dispensary nurse presses the start button. \par
    2. The car waits 1 second. \par
    3. The car begins to drive. \par
    4. The car drives. \par
    5. The car arrives at the first point. \par
    6. The car stops at the first point. \par
    7. The car goes idle. \par
    8. The nurse removes. \par
    9. 


     \\
    \hline
    \textbf{Extensions/Exceptions:} &
    
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