# Acceptance test specification {-}

# Use Case 1 - Start

## Main scenario

\begin{table}[H] 
\begin{tabularx}{\textwidth}{| c |*{3}{X|} p{2cm} |} 
    \hline 
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 1 - Start } \\
    \hline 
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario} \\
    \hline 
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off ??and the hotspot is turned on??} \\ 
    \hline 
    \multicolumn{5}{|c|}{} \\ 
    \hline \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\ 
    \hline 
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and monitoring the network & & \\ 
    \hline 
    \textbf{2} & Place the car on homebase & The car is on homebase & & \\ 
    \hline 
    \textbf{3} & Press the 'Power' button & Wireshark shows the car successfully establishing a connection to the network and the red LED turns on & & \\ 
    \hline 
\end{tabularx} 
\caption{Acceptance test - Use Case 1 - Main scenario} 
\label{tab:at-usecase1main} 
\end{table}

### Exception 1 - No power on the battery
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use Case 1 - Start} \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 1 }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and monitoring the network & & \\ 
    \hline 
    \textbf{2} & Place the car on homebase & The car is on homebase & & \\ 
    \hline 
    \textbf{3} & Press the 'Power' button & The red LED does not turn on & & \\ 
    \hline 
\end{tabularx}
\caption{Acceptance test - Use Case 1 - Exception 1 - No power on the battery}
\label{tab:at-usecase1ex1}
\end{table}

\newpage

### Exception 2 - Connection to network fails
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use Case 1 - Start} \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off and hotspot is turned off } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and monitoring the network & & \\ 
    \hline 
    \textbf{2} & Place the car on homebase & The car is on homebase & & \\ 
    \hline 
    \textbf{3} & Press the 'Power' button & Wire shark doesnt show connection between car and server & & \\ 
    \hline 
    \textbf{4} & Car doesnt connect with ther server & The red LED starts to blink & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 1 - Exception 2 - Connection to network fails}
\label{tab:at-usecase1ex2}
\end{table}

\newpage

# Use Case 2 - Create Route
## Main scenario
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and is monitoring the local network & &\\
    \hline
    \textbf{2} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{4} & Navigate to and select 'Finish route' & A confirmation message saying "These are your chosen rooms" and a list of the chosen rooms appears & & \\
    \hline
    \textbf{5} & 'Confirm' is selected & Wireshark shows a message being sent to the server & & \\ 
    \hline
    \textbf{6} & Open the text file "routes.txt" on the server and check the contents & The file contains the order of room 1, 2 and 3 & & \\
    \hline
    \textbf{8} & Look at the UI & The Terminal UI displays "The route has been successfully made" and "Press Enter to close the UI" & & \\
    \hline
    \textbf{9} & Press Enter & The Terminal UI closes & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 1}
\label{tab:at-usecase2main}
\end{table}

\newpage

### Exception 1 - The dispensary nurse selects the "Cancel" option
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 1 - The dispensary nurse selects the "Cancel" option }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and is monitoring the local network & &\\
    \hline
    \textbf{2} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{4} & Navigate to and select 'Cancel route' & All rooms are deselected and the Terminal UI closes & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 1 - The dispensary nurse selects the "Cancel" option}
\label{tab:at-usecase2ex2}
\end{table}

\newpage

### Extension 1 - Room is already added
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - Room already added }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and is monitoring the local network & &\\
    \hline
    \textbf{2} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{4} & Select rooms 2 and 3 again & Rooms 2 and 3 will be unselected & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 1 - Room is already added}
\label{tab:at-usecase2ex2}
\end{table}

\newpage

### Extension 2 - No rooms were selected
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 3 - No rooms were selected}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and is monitoring the local network & &\\
    \hline
    \textbf{2} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{3} & Press confirm before selecting any rooms & An error message is displayed on the UI. Return to point 2 in the main scenario & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 2 - No rooms were selected}
\label{tab:at-usecase2ex3}
\end{table}

\newpage
### Extension 3 - The dispensary nurse selects the "Deny" option(ikke done)
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and is monitoring the local network & &\\
    \hline
    \textbf{2} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{4} & Navigate to and select 'Finish route' & A confirmation message saying "These are your chosen rooms" and a list of the rooms 1, 2 and 3 appears & & \\
    \hline
    \textbf{5} & 'Deny' is selected & All rooms are deselected. & & \\ 
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Main Extension 3 - The dispensary nurse selects the "Deny" option}
\label{tab:at-usecase2main}
\end{table}

\newpage

# Use Case 3 - Complete Delivery Route
## Main scenario
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is idle on homebase and the server has a single route with 2 rooms stored} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and is monitoring the local network & & \\ 
    \hline
    \textbf{2} & Press the Action button & A request to fetch routes is sent from the car to the server & & \\
    \hline
    \textbf{3} & Look at the LEDs & The green LED is on & & \\
    \hline
    \textbf{4} & Prepare a timer to time the response & User is ready to time the response & & \\
    \hline
    \textbf{5} & Press the Action button and start the timer & The green LED turns off and after a maximum of 5 seconds the car starts driving & & \\
    \hline
    \textbf{6} & When the car starts driving, stop the timer & The response time has been measured & & \\
    \hline
    \textbf{7} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & & \\
    \hline
    \textbf{8} & Prepare a timer to time the response & User is ready to time the response & & \\
    \hline
    \textbf{9} & Press the Action button and start the timer & The green LED turns off and after a maximum of 5 seconds the car starts driving & & \\
    \hline
    \textbf{10} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & & \\
    \hline
    \textbf{11} & Press the Action button & The green LED turns off and the car starts driving & & \\
    \hline
    \textbf{12} & Wait for car to arrive at homebase & The car is idle on homebase & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Main scenario}
\label{tab:at-usecase3main}
\end{table}
\newpage

### Exception 1 - No available routes
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 1 - No available routes }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is powered on, connected to the network and at homebase no route has been created } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Car requests a route from the server & No route is available & & \\ 
    \hline
    \textbf{2} & Observe LEDs & The green LED starts blinking & & \\ 
    \hline
    \textbf{3} & Wait 5 seconds & The green LED continues blinking during the wait & & \\ 
    \hline
    \textbf{4} & Observe LEDs & The green LED stops blinking, and the car enters idle mode & & \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Exception 1 - No available routes}
\label{tab:at-usecase4main}
\end{table}
\newpage

### Exception 2 - Network Error
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - Network error }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is powered on, connected to the network and at homebase no route has been created } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Car requests a route from the server & No route is available & & \\ 
    \hline
    \textbf{2} & Observe LEDs & The green LED starts blinking & & \\ 
    \hline
    \textbf{3} & Wait 5 seconds & The green LED continues blinking during the wait & & \\ 
    \hline
    \textbf{4} & Observe LEDs & The green LED stops blinking, and the car enters idle mode & & \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Exception 2 -  Network Error}
\label{tab:at-usecase4main}
\end{table}
\newpage

### Extension 1 - Remaining locations in the route(excl. homebase)
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 3 - Remaining locations in the route (exel. homebase) }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is powered on and the car fails to send or receive data from the server. } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the "Action" button & The green LED turns off & & \\ 
    \hline
    \textbf{2} & Wait 5 seconds & The car waits before starting to drive & & \\ 
    \hline
    \textbf{3} & Observe car movement & The car starts driving to the next delivery location & & \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Extension 1 -  Remaining locations in the route (exel. homebase) }
\label{tab:at-usecase4main}
\end{table}


\newpage

# Use Case 4 - Shutdown of car
## Main scenario
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 4 - Shutdown of car} \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Main scenario }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is powered on, connected to the network and at homebase } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the Power button & The car terminates all driving instructions and powers off safely & & \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 4 - Main scenario}
\label{tab:at-usecase4main}
\end{table}


# Non-functional Requirements {-}

## Nonfunctional Requirements

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
\hline
\multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Functionality - Request route while idle} \\
\hline
\multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car powered on, idle, not on route} \\
\hline
\multicolumn{5}{|c|}{}\\
\hline
\textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
\hline
1 & Press 'Action' button & Car requests route from server & & \\
\hline
2 & Server returns route & Car receives valid JSON route & & \\
\hline
3 & Car starts route & Car follows route at max 5 km/h & & \\
\hline
4 & Car reaches destination & Car stops, LED indicates idle & & \\
\hline
\end{tabularx}
\caption{Acceptance test - Functionality: Request route while idle}
\label{tab:nf-functionality}
\end{table}



## Usability: LED and Speaker Feedback

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
\hline
\multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability - LED and speaker feedback} \\
\hline
\multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car powered on, ready to start or waiting} \\
\hline
\multicolumn{5}{|c|}{}\\
\hline
\textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
\hline
1 & Car ready to start route & Green LED on, speaker announces ready & & \\
\hline
2 & Car waiting at destination & Red LED on, speaker announces waiting & & \\
\hline
3 & Route completed & Green LED flashes, speaker announces completion & & \\
\hline
\end{tabularx}
\caption{Acceptance test - Usability: LED and speaker feedback}
\label{tab:nf-usability}
\end{table}

##  Reliability: Continuous Operation

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
\hline
\multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Reliability - Continuous operation} \\
\hline
\multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car fully charged, powered on, ready to drive} \\
\hline
\multicolumn{5}{|c|}{}\\
\hline
\textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
\hline
1 & Drive car continuously & Car operates for $\geq$ 1 hour without failure & & \\
\hline
2 & Server runs simultaneously & Server operates $\leq$ 6 hours continuously & & \\
\hline
3 & Perform simple maintenance & Tasks completed $\leq$ 10 minutes & & \\
\hline
\end{tabularx}
\caption{Acceptance test - Reliability: Continuous operation and maintenance}
\label{tab:nf-reliability}
\end{table}



## Performance: Response Time and Range

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
\hline
\multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Reliability - Continuous operation} \\ 
\hline
\multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car fully charged, powered on, ready to drive} \\ 
\hline
\multicolumn{5}{|c|}{} \\ 
\hline
\textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\ 
\hline
1 & Drive car continuously & Car operates for $\geq$1 hour without failure & & \\ 
\hline
2 & Server runs simultaneously & Server operates $\geq$6 hours continuously & & \\ 
\hline
3 & Perform simple maintenance & Tasks completed $\leq$10 minutes & & \\ 
\hline
\end{tabularx} \\ 
\caption{Acceptance test - Reliability: Continuous operation and maintenance}
\label{tab:nf-reliability}
\end{table}


## Supportability: Logging
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
\hline
\multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Supportability - Logging and remote retrieval} \\ 
\hline
\multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car powered on, has performed multiple routes} \\ 
\hline
\multicolumn{5}{|c|}{} \\ 
\hline
\textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\ 
\hline
1 & Car completes route & Log entry created with route info & & \\ 
\hline
2 & Car fails a route & Log entry created with error info & & \\ 
\hline
3 & Retrieve logs remotely & Logs successfully retrieved & & \\ 
\hline
4 & Delete logs manually & Logs removed within system & & \\ 
\hline
\end{tabularx} \\ 
\caption{Acceptance test - Supportability: Logging and retrieval}
\label{tab:nf-supportability}
\end{table}


## Safety and Constraints

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
\hline
\multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Safety and operational constraints} \\ 
\hline
\multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{Car powered on, executing route} \\ 
\hline
\multicolumn{5}{|c|}{} \\ 
\hline
\textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\ 
\hline
1 & Press emergency stop & Car halts within 1 second & & \\ 
\hline
2 & Attempt operation outdoors or on wet surface & Car does not operate & & \\ 
\hline
3 & Attempt operation with obstacles & Car cannot avoid collisions & & \\ 
\hline
\end{tabularx} \\ 
\caption{Acceptance test - Safety and constraints}
\label{tab:nf-safety}
\end{table}
