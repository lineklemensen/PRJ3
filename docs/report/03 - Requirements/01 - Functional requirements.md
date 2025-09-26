# Functional requirements

Use Case 1 Create order (must)
A nurse ++makes a order by selecting the rooms that need more medicine. The system sends a confirmation of success or failure.

Use Case 2 Prepare and send orders (must)
The server processes the order and sends the necessary information to the car. The car indicates it has received a order and found a path. The nurse loads the medicine in the car and presses the start button.

Use Case 3 Deliver order and return (must)
The car drives to the first patients room, here it stop and notifies that its ready to be unloaded. A nurse takes the medicine and presses the start button. If there are more room left in the path the car goes there and the cycle repeats until it has finished its path. Then it returns to the start location.

Use Case 4 Low battery warning (should)
If the car has less than 25% battery left it finishes its path and returns. When it has returned it sends a message to the server that its running out of battery. It then indicates this to the nurse and the nurse put it to charge.


\begin{table}[h]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 1 - Create order\\ 
    \hline
    \textbf{Goal:} & The user wants to create a order\\ 
    \hline
    \textbf{Initialization:} & The user opens the UI\\  
    \hline
    \textbf{Actors:} & User - primary\\  
    \hline
    \textbf{Concurrent instances:} & 1\\  
    \hline
    \textbf{Precondition:} & The system is running and functional\\
    \hline
    \textbf{Postcondition:} & A order has been created\\
    \hline
    \textbf{Main scenario:} & 1. The user opens the UI \par
    2. A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI \par
    3. The user chooses the rooms they want \par
    [Exception 1a: The user does not choose any rooms] \par
    4. The user clicks finish order \par
    5. A confirmation message saying "This is your chosen rooms" and a list of the rooms chosen appears \par
    6. The user clicks "Confirm" \par
    [Extension 2a: The user clicks "Deny"] \par
    7. The order gets added to the server \par 
    \\
    \hline
    \textbf{Extensions/Exceptions:} & [Exception 1a: The user does not choose any rooms] \par
    \hspace{1cm} 1. The user clicks finish order \par
    \hspace{1cm} 2. An error message saying "You did not choose any rooms for this \par \hspace{1cm} order" appears \par
    \hspace{1cm} 3. Return to point 2 \par
    [Extension 2a: The user clicks "Deny"] \par
    \hspace{1cm} 1. Return to point 2
    \\
    \hline
\end{tabularx}
    \caption{Use case 1 - Create order}
    \label{tab:usecase1}
\end{table}

\begin{table}[h]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 1 - Create order\\ 
    \hline
    \textbf{Goal:} & The user wants to create a order\\ 
    \hline
    \textbf{Initialization:} & The user opens the UI\\  
    \hline
    \textbf{Actors:} & User - primary\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\  
    \hline
    \textbf{Precondition:} & The system is running and functional\\
    \hline
    \textbf{Postcondition:} & A order has been created\\
    \hline
    \textbf{Main scenario:} & 1. \\
    \hline
    \textbf{Extensions/Exceptions:} & a\\
    \hline
\end{tabularx}
    \caption{Use case 1}
    \label{tab:usecase1}
\end{table}

\begin{table}[h]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 3 - Deliver order and return\\ 
    \hline
    \textbf{Goal:} & The car deliver its packages and returns to homebase\\ 
    \hline
    \textbf{Initialization:} & The button has been pressed\\  
    \hline
    \textbf{Actors:} & Nurse - primary, dispensary nurse\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\  
    \hline
    \textbf{Precondition:} & Use case 2 has been resolved succesfully\\
    \hline
    \textbf{Postcondition:} & The car has returned to homebase after delivering all packages\\
    \hline
    \textbf{Main scenario:} & 1. The dispensary nurse presses the button \\ 
    & \hspace{1cm} [Exception 3b: The car has a hardware malfunction]\\
    & 2. The car follows the path to the first room \\
    & \hspace{1cm} [Exstension 1a: The car goes idle]\\
    & \hspace{1cm} [Exception 1b: The car runs out of battery]\\
    & \hspace{1cm} [Exception 2b: The car is physically interrupted]\\
    & \hspace{1cm} [Exception 3b: The car has a hardware malfunction]\\
    & 3. The car waits for a nurse in the room \\ 
    & 4. A nurse enters the room and takes the patients medicin \\ 
    & 5. The nurse presses the button \\ 
    & 6. The car follows the path to the next room and repeat step 3 , 4 and 5 \\
    & \hspace{1cm} [Exception 1b: The car runs out of battery]\\
    & \hspace{1cm} [Exception 2b: The car is physically interrupted]\\
    & \hspace{1cm} [Exception 3b: The car has a hardware malfunction]\\ 
    & 7. The car drives to homebase if the given room was the last in route\\
    \hline
    \textbf{Extensions/Exceptions:} 
    & [Extension 1a: The car goes idle] \\
    & \hspace{1cm} 1. The car stops in the room\\
    & \hspace{1cm} 2. The car goes to idle untill button is pressed\\ 
    & [Exception 1b: The car runs out of battery] \\
    & \hspace{1cm} 1. The car is driving with low battery\\
    & \hspace{1cm} 2. The car runs out of battery\\
    & \hspace{1cm} 3. See use case 4\\ 
    & [Exception 2b: The car is physically interrupted]\\
    & \hspace{1cm} 1. The car is driving\\
    & \hspace{1cm} 2. The car gets blocked by something\\
    & \hspace{1cm} 3. Send message to server "Path interrupted"\\
    & [Exception 3b: The cars has a hardware malfunction]\\
    & \hspace{1cm} 1. The cars hardware malfunctions\\
    & \hspace{1cm} 2. send message to server "Hardware failure"\\ 
    \hline
\end{tabularx}
    \caption{Use case 1}
    \label{tab:usecase1}
\end{table}

\begin{table}[h]
\begin{tabularx}{\textwidth}{ | p{5.04cm} | X | }
    \hline
    \textbf{Name:} & Use case 1 - Create order\\ 
    \hline
    \textbf{Goal:} & The user wants to create a order\\ 
    \hline
    \textbf{Initialization:} & The user opens the UI\\  
    \hline
    \textbf{Actors:} & User - primary\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\  
    \hline
    \textbf{Precondition:} & The system is running and functional\\
    \hline
    \textbf{Postcondition:} & A order has been created\\
    \hline
    \textbf{Main scenario:} & 1. \\
    \hline
    \textbf{Extensions/Exceptions:} & a\\
    \hline
\end{tabularx}
    \caption{Use case 1}
    \label{tab:usecase1}
\end{table}