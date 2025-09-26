# Functional requirements

Use Case 1 Create order (must)
A nurse makes a order by selecting the rooms that need more medicine. The system sends a confirmation of success or failure.

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
    \textbf{Main scenario:} & 1. The dispensary nurse presses the button \\ & 2. The car follows the path to the first room and waits \\ & 3. A nurse takes the given patients medicin, closes the box and presses the button \\ & 4. The car drives to the next room and repeats step 2 and 3 untill it reaches the last room\\ & 5. The car drives back to homebase after having had the button pressed in the last room\\
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