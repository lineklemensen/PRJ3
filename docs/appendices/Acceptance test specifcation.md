# Acceptance test specification

\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car is turned off} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and monitoring the local network & &\\
    \hline
    \textbf{2} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{4} & Press finish order & A confirmation message saying "This is your chosen rooms" and a list of the rooms 1, 2 and 3 appears & & \\
    \hline
    \textbf{5} & Click confirm & & & \\ 
    \hline
    \textbf{6} & Check Wireshark for a message from the UI to the server & There is a message sent from the UI to the server and the server has received the message & & \\
    \hline
    \textbf{7} & Open the text file "orders.txt" on the server and check the contents & The file contains the order of room 1, 2 and 3 & & \\
    \hline
    \textbf{8} & Check Wireshark for a message from the server to the car & There is a message sent from the server to the car and the car has received the message & & \\
    \hline
    \textbf{9} & Look at the green LED & The green LED is turned on & & \\
    \hline
    \textbf{10} & Look at the UI &  message saying "An order has been successfully made" appears & & \\
    \hline
    \textbf{11} & Look at the UI & After a delay the UI closes & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2}
\label{tab:at-usecase2}
\end{table}



\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 1: The dispensary nurse selects the cancel option}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\ 
    \hline
    \textbf{2} & Choose room 1 and 3 & Room 1 and 3 is marked & & \\
    \hline
    \textbf{3} & Press "cancel" & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - extension 1}
\label{tab:at-usecase2ex1}
\end{table}


\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 2: No rooms were selected}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\ 
    \hline
    \textbf{2} & Press finish order & An error message saying "You did not choose any rooms for this order" appears & & \\
    \hline
    \textbf{3} & Press enter & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - extension 2}
\label{tab:at-usecase2ex2}
\end{table}

\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 3: The dispensary nurse selects the "Deny" option}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{ (OK/FAIL)}\\
    \hline
    \textbf{1} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{3} & Press finish order & A confirmation message saying "This is your chosen rooms" and a list of the rooms 1, 2 and 3 appears & & \\
    \hline
    \textbf{4} & Click "Deny" & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\ 
    \hline
\end{tabularx}
\caption{Accepttest - Use Case 2 - extension 3}
\label{tab:at-usecase2ex3}
\end{table}


\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 4: There is no car available}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional, and there is a car idle at its last location} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{ (OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and monitoring the local network & &\\
    \hline
    \textbf{2} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI, A finish and cancel option appears & & \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{4} & Press finish order & A confirmation message saying "This is your chosen rooms" and a list of the rooms 1, 2 and 3 appears & & \\
    \hline
    \textbf{5} & Click confirm & & & \\ 
    \hline
    \textbf{6} & Check Wireshark for a message from the UI to the server & There is a message sent from the UI to the server and the server has received the message & & \\
    \hline
    \textbf{7} & Open the text file "orders.txt" on the server and check the contents & The file contains the order of room 1, 2 and 3 & & \\
    \hline
    \textbf{8} & Press the cars start button & The car starts driving to homebase & & \\
    \hline
    \textbf{9} & Wait for the car to arrive at the home base & The car arrives at the homebase & & \\ 
    \hline
    \textbf{10} & When the car arrives at homebase check Wireshark for a message from the car to the server & There is a message sent from the car to the server and the server has received the message & & \\
    \hline
    \textbf{11} & Check Wireshark for a message from the server to the car & There is a message sent from the server to the car and the car has received the message & & \\
    \hline
    \textbf{12} & Look at the green LED & The green LED is turned on & & \\
    \hline
    \textbf{13} & Look at the UI &  message saying "An order has been successfully made" appears & & \\
    \hline
    \textbf{14} & Look at the UI & After a delay the UI closes & & \\
    \hline
\end{tabularx}
\caption{Accepttest - Use Case 2 - extension 4}
\label{tab:at-usecase2ex4}
\end{table}


\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 4: There is no car available}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional, and there is no car idle at the homebase} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{ (OK/FAIL)}\\
    \hline
    \textbf{1} &  & & & \\
    \hline 
\end{tabularx}
\caption{Accepttest - Use Case 1}
\label{tab:at-usecase1a}
\end{table}