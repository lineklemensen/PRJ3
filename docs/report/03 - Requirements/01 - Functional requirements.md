# Functional requirements

Use Case 1 Create order (must)
A nurse makes an order by selecting the rooms that need medicine. The system sends a confirmation of success or failure.

Use Case 2 Prepare and send orders (must)
The server processes the order and sends the necessary information to the car. The car indicates it has received a order and found a path. The nurse loads the medicine in the car and presses the start button.

Use Case 3 Deliver order and return (must)
The car drives to the first patients room, here it must stop and notify that it is ready to be unloaded. A nurse takes the medicine and presses the start button. If there are more rooms left in the path the car goes there and the cycle repeats until it has finished its path. Then it returns to the start location.

Use Case 4 Low battery warning (should)
If the car has less than 25% battery left it finishes its path and returns. When it has returned it sends a message to the server that it is running out of battery. It then indicates this to the nurse and the nurse plugs it in to start charging.


\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 1 - Create order \\
    \hline
    \textbf{Goal:} & The user wants to create a order \\
    \hline
    \textbf{Initialization:} & The user opens the UI \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} User\\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The system is running and functional \\
    \hline
    \textbf{Postcondition:} & A order has been created in the system \\
    \hline
    \textbf{Main scenario:} & 1. The user opens the UI \par
    2. A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI \par
    3. The user chooses the rooms they want \par
    \hspace{1cm} [Extension 1a: The user does not choose any rooms] \par
    4. The user clicks finish order \par
    5. A confirmation message saying "This is your chosen rooms" and a list of the rooms chosen appears \par
    6. The user clicks "Confirm" \par
    \hspace{1cm} [Extension 2a: The user clicks "Deny"] \par
    7. The order gets added to the server \par
    \\
    \hline
    \textbf{Extensions/Exceptions:} & [Extension 1: The user does not choose any rooms] \par
    \hspace{1cm} 1. The user clicks finish order \par
    \hspace{1cm} 2. An error message saying "You did not choose any rooms for this \par \hspace{1cm} order" appears \par
    \hspace{1cm} 3. Return to point 2 \par
    [Extension 2: The user clicks "Deny"] \par
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
    \textbf{Name:} & Use case 2 - Prepare and send orders \\
    \hline
    \textbf{Goal:} & The car is loaded with medicine and ready to drive \\
    \hline
    \textbf{Initialization:} & The server has received an order \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Dispensary nurse \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & An order has been made \\
    \hline
    \textbf{Postcondition:} & The car receives the information and gets loaded with medicine by a nurse \\
    \hline
    \textbf{Main scenario:} & 1. Server receives an order with a list of room numbers.
    \par 2. Server looks through the order and sends the list to the car.
    \par 3. The car receives the list of rooms.
    \par \hspace{1cm} [Exception 1: Car does not receive the list]
    \par 4. The car sends a message "Successful: List was received" back to server
    \par 5 Path finding makes the shortest route for the car.
    \par \hspace{1cm} [Exception 2: Path finding fails]
    \par 6. The green LED on the car lights up to signal that the car is ready to drive.
    \par 7. Medicine are loaded onto the car.

    \\
    \hline
    \textbf{Extensions/Exceptions:} & [Exception 1: Car does not receive the list]
    \par \hspace{1cm} 1. A message is send to the server "Failed: List was not received".
    \par \hspace{1cm} 2. The green LED on the car lights up red to signal something is wrong.
    \par \hspace{1cm} 3. The car wont drive if the start button is pressed.
    \par [Exception 2: Path finding fails]
    \par \hspace{1cm} 1. The car sends a message to the server "Path finding failed".
    \par \hspace{1cm} 2. The green LED on the car lights up red to signal something is wrong.
    \par \hspace{1cm} 3. The car wont drive if the start button is pressed.

    \\
    \hline
\end{tabularx}
    \caption{Use case 2}
    \label{tab:usecase2}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 3 - Deliver order and return \\
    \hline
    \textbf{Goal:} & The car deliver its packages and returns to homebase \\
    \hline
    \textbf{Initialization:} & The button has been pressed \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Nurse \newline
                        \textbf{Secondary:} Dispensary nurse \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & Use case 2 has been resolved successfully \\
    \hline
    \textbf{Postcondition:} & The car has returned to homebase after delivering all packages \\
    \hline
    \textbf{Main scenario:} & 1. The dispensary nurse presses the button \\
    & \hspace{1cm} [Exception 3b: The car has a hardware malfunction]\\
    & 2. The car follows the path to the first room \\
    & \hspace{1cm} [Extension 1a: The car goes idle]\\
    & \hspace{1cm} [Exception 1b: The car runs out of battery]\\
    & \hspace{1cm} [Exception 2b: The car is physically interrupted]\\
    & \hspace{1cm} [Exception 3b: The car has a hardware malfunction]\\
    & 3. The car waits for a nurse in the room \\
    & 4. A nurse enters the room and takes the patients medicine \\
    & 5. The nurse presses the button \\
    & 6. The car follows the path to the next room and repeat step 3 , 4 and 5 \\
    & \hspace{1cm} [Exception 1b: The car runs out of battery]\\
    & \hspace{1cm} [Exception 2b: The car is physically interrupted]\\
    & \hspace{1cm} [Exception 3b: The car has a hardware malfunction]\\
    & 7. The car drives to homebase if the given room was the last in route \\
    \hline
    \textbf{Extensions/Exceptions:}
    & [Extension 1a: The car goes idle] \\
    & \hspace{1cm} 1. The car stops in the room \\
    & \hspace{1cm} 2. The car goes to idle until button is pressed \\
    & [Exception 1b: The car runs out of battery] \\
    & \hspace{1cm} 1. The car is driving with low battery \\
    & \hspace{1cm} 2. The car runs out of battery \\
    & \hspace{1cm} 3. See use case 4 \\
    & [Exception 2b: The car is physically interrupted]\\
    & \hspace{1cm} 1. The car is driving \\
    & \hspace{1cm} 2. The car gets blocked by something \\
    & \hspace{1cm} 3. Send message to server "Path interrupted"\\
    & [Exception 3b: The cars has a hardware malfunction]\\
    & \hspace{1cm} 1. The cars hardware malfunctions \\
    & \hspace{1cm} 2. send message to server "Hardware failure"\\
    \hline
\end{tabularx}
    \caption{Use case 3}
    \label{tab:usecase3}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 4 - The car is low on battery \\
    \hline
    \textbf{Goal:} & When the cars battery gets below 25\% remaining battery, it finishes and returns to home base and sends a message to the server \\
    \hline
    \textbf{Initialization:} & Battery life drops below 25\% \\
    \hline
    \textbf{Actors:} & \textbf{Primary:} Car \newline
                        \textbf{Secondary:} Server, Nurse \\
    \hline
    \textbf{Concurrent instances:} & 1 \\
    \hline
    \textbf{Precondition:} & The car is en route to its next target with more than 25\% battery remaining. Then the battery life is becoming less that 25\% \\
    \hline
    \textbf{Postcondition:} & The car is back at home base and has notified the system that it needs to be recharged \\
    \hline
    \textbf{Main scenario:} &
    1. The system detects that the cars battery is below 25\% \newline
    Extensions: 1a, 2a, 3a, 4a \newline \newline
    2. The car completes its current route \newline
    Extensions: 1a, 2a, 3a, 4a \newline \newline
    3. After finishing its current route, the car autonomously returns to home base \newline
    Extensions: 1a, 2a, 3a, 4a \newline \newline
    4. The car sends "Low Battery, percentage is : [car \%]" status message to the server \newline
    Extensions: 1a, 2a, 3a \newline \newline
    5. The server receives the message and sends a message to the nurses to go charge the car \newline
    Extensions: 1a, 2a, 3a \newline \newline
    6. The nurse charges the car \newline

    7. The car is charging \\
    \hline
    \textbf{Extensions/Exceptions:} &
     1a: communication fails with the server, the car displays the low battery alert locally with a red led, resumes at main point 6  \newline
     \newline
     2a: if the battery gets to 5\% another message wil be sent to the server "critically low battery" resume at same point as before \newline
     \newline
     3a: if battery gets to 1\% another message will be sent to the server "Battery too low shutting down, location :xx", then a different version of point 5 will be executed, instead of the message of "the car needs charging" its going to be "The car needs charging, i did not make it to home base, its at :xx".
     \newline
     \newline
     4a: If the car calculated it won't be able to return to home base or get to the next room, it will stand still at the current room and send the message to the server "Can't continue driving, standing at :xx". resume at main point 5, with edit to the message: The car needs charging, it cant make it back, it stands in room :xx"
     \newline
     \newline
     1b: The car gets physically blocked or interrupted on its route, sends an obstruction alert to the server
     \newline
     \newline
     2b: The nurse had not started the charging of the car, the car alerts the system again "not charging yet" and system sends reminder to the nurse "remember to charge car" \\
    \hline
\end{tabularx}
    \caption{Use case 4}
    \label{tab:usecase4}
\end{table}

\newpage
