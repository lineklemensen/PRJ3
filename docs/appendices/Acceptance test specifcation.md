# Acceptance test specification

\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI & & \\
    \hline
    \textbf{2} & Choose room 1, 3, 4 and 6 then press finish order & A confirmation message saying "This is your chosen rooms" and a list of the rooms 1, 3, 4 and 6 appears & & \\
    \hline
    \textbf{3} & Click confirm & The UI returns to the order creation site & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 1}
\label{tab:at-usecase1}
\end{table}


\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 1: The dispensary nurse does not choose any rooms}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI & & \\
    \hline
    \textbf{2} & Press finish order & An error message saying "You did not choose any rooms for this order" appears & & \\
    \hline
    \textbf{3} & Press enter & The UI returns to the order creation site & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 1 - extension 1}
\label{tab:at-usecase1ex1}
\end{table}


\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 - Create order } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 2: The dispensary nurse clicks "Deny"}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the UI  & A message saying "Choose the rooms for this order" and a list of all rooms appear on the UI & & \\
    \hline
    \textbf{2} & Choose room 1, 3, 4 and 6 then press finish order & A confirmation message saying "This is your chosen rooms" and a list of the rooms 1, 3, 4 and 6 appears & & \\
    \hline
    \textbf{3} & Click Deny & The UI returns to the order creation site & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 1}
\label{tab:at-usecase1}
\end{table}

\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{???} \\
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

\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{???} \\
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

\begin{table}[h]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{???} \\
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