# Results

Shown below is the results of our acceptance test for the main scenario of Use Case 3. For all results, see Acceptance Test result in appendices.

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase and the server is running with a single route of 2 rooms stored} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and is monitoring the local network & Wireshark is monitoring the network & OK \\ 
    \hline
    \textbf{2} & Press the Action button & [Wireshark]A request to fetch routes is sent from the car to the server & The route is requested & OK \\
    \hline
    \textbf{3} & Look at the LEDs & The green LED is on & The green LED is turned on & OK \\
    \hline
    \textbf{4} & Prepare a timer to time the system & User is ready to time the system & The system is being timed & OK \\
    \hline
    \textbf{5} & Press the Action button and start the timer & The green LED turns off and after a maximum of 5 seconds the car starts driving & The green LED turns off and the car starts driving immediately & OK \\
    \hline
    \textbf{6} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & The car turns and drives in the pattern of the map, but it sometimes over/underturns & Partial OK \\
    \hline
    \textbf{8} & Press the Action button and start the timer & The green LED turns off and the car starts driving & The LED turns off and the car starts driving immediately & OK \\
    \hline
    \textbf{9} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & Again, it drives in a pattern that matches the map, but it is not very precise & Partial OK\\
    \hline
    \textbf{10} & Press the Action button & The green LED turns off and the car starts driving & The LED is off and the car starts driving & OK \\
    \hline
    \textbf{11} & Wait for car to arrive at homebase & The car is idle at homebase & Again, the car is not very precise compared to our map, but the logic is followed & Partial OK \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Main scenario}
\label{tab:at-usecase3main}
\end{table}

# Discussion
\newpage