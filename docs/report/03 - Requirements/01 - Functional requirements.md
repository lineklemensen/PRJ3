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
    \textbf{Name:} & Use case 2 - Prepare and send orders\\ 
    \hline
    \textbf{Goal:} & The car is loaded with medicine and ready to drive \\ 
    \hline
    \textbf{Initialization:} & The server has received an order\\  
    \hline
    \textbf{Actors:} & despensary nurse - secondary\\  
    \hline
    \textbf{Concurrent instances:} & 1 \\  
    \hline
    \textbf{Precondition:} & An order has been made\\
    \hline
    \textbf{Postcondition:} & The car receives the infomation and gets loaded with medicine by a nurse \\
    \hline
    \textbf{Main scenario:} & 1. Server receives an order with a list of room numbers.
    \par 2. Server looks through the order and sends the list to the car.
    \par 3. The car receives the list of rooms.
    \par \hspace{1cm} [Exception 1: Car does not receive the list]
    \par 4. The car sends a message "Successful: List was received" back to server
    \par 5 Path finding makes the shortes route for the car.
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