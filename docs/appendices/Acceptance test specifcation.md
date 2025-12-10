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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off} \\ 
    \hline 
    \multicolumn{5}{|c|}{} \\ 
    \hline \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\ 
    \hline 
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and monitoring the local network & The network is being monitored & OK \\ 
    \hline 
    \textbf{2} & Press the 'Power' button & [Wireshark] shows the car successfully establishing a connection to the local network and the red LED turns on & The car turns on but doesn't connect to network & FAIL \\ 
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Exception 1 - No power on battery}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the 'Power' button & The red LED does not turn on & The LED doesn't turn on & OK \\ 
    \hline 
\end{tabularx}
\caption{Acceptance test - Use Case 1 - Exception 1 - No power on the battery}
\label{tab:at-usecase1exception1}
\end{table}


### Exception 2 - Connection to network fails
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use Case 1 - Start} \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - Connection to network fails }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off and the local network is not running } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline 
    \textbf{1} & Press the 'Power' button & The red LED starts to blink & Not implemented & FAIL \\ 
    \hline 
\end{tabularx}
\caption{Acceptance test - Use Case 1 - Exception 2 - Connection to network fails}
\label{tab:at-usecase1exception2}
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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network the RPI's are using with Wireshark & Wireshark is opened and is monitoring the local network & Wireshark is monitoring the network & OK \\
    \hline
    \textbf{2} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and clear option appear as well & The message appears on the TUI & OK \\ 
    \hline
    \textbf{3} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & The chosen rooms are marked on the TUI & OK \\
    \hline
    \textbf{4} & Navigate to and select 'Finish' & A confirmation message saying "These are your chosen rooms" and a list of the chosen rooms appears & The list of chosen rooms appears on the TUI & OK \\
    \hline
    \textbf{5} & 'Confirm' is selected & [Wireshark] A route is sent to the server & Wireshark shows a package being sent and the server has received the route & OK \\ 
    \hline
    \textbf{6} & Open the text file "logger.txt" on the server and check the contents & The file contains the list of selected rooms (1, 2 and 3) & The route is contained in "logger.txt" on the server & OK\\
    \hline
    \textbf{8} & Look at the UI & The Terminal UI displays "The route has been successfully made" & Fail for nu & FAIL for nu \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Main scenario}
\label{tab:at-usecase2main}
\end{table}

\newpage

### Exception 1 - The dispensary nurse selects the "Clear" option
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 1 - The dispensary nurse selects the "Clear" option }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and clear option appear as well & The message is displayed correctly on the TUI & OK \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & The chosen rooms are marked on the TUI & OK \\
    \hline
    \textbf{3} & Navigate to and select 'Clear' & All rooms are deselected & All rooms are deselected on the TUI & OK \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Exception 1 - The dispensary nurse selects the "Clear" option}
\label{tab:at-usecase2exception1}
\end{table}


### Extension 1 - Room is already added
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - Room is already added }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and clear option appear as well & The message is displayed on the TUI & OK \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & The chosen rooms are marked on the TUI & OK \\
    \hline
    \textbf{3} & Select rooms 2 and 3 again & Rooms 2 and 3 will be unselected & The chosen rooms are unselected on the TUI & OK \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 1 - Room is already added}
\label{tab:at-usecase2extension1}
\end{table}

\newpage

### Extension 2 - No rooms were selected
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - No rooms were selected}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and clear option appear as well & The message is displayed on the TUI & OK \\ 
    \hline
    \textbf{2} & Press confirm before selecting any rooms & An error message is displayed on the UI. Return to point 2 in the main scenario & Fail for nu & Fail for nu \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 2 - No rooms were selected}
\label{tab:at-usecase2extension2}
\end{table}

### Extension 3 - The dispensary nurse selects the "Deny" option
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Extension 3 - The dispensary nurse selects the "Deny" option}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and clear option appear as well & The message is displayed on the TUI & OK \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & The rooms are marked TUI & OK \\
    \hline
    \textbf{3} & Navigate to and select 'Finish selecting' & A confirmation message saying "These are your chosen rooms" and a list of the chosen rooms is displayed & The list of rooms is displayed on the TUI & OK\\
    \hline
    \textbf{4} & 'Deny' is selected & Popup closes & The popup is closed & OK \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Extension 3 - The dispensary nurse selects the "Deny" option}
\label{tab:at-usecase2extension3}
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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase and the server is running with a single route of 2 rooms stored} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and is monitoring the local network & Wireshark is monitoring the network & OK \\ 
    \hline
    \textbf{2} & Press the Action button & [Wireshark]A request to fetch routes is sent from the car to the server & A post is sent but get is not visible & OK ? \\
    \hline
    \textbf{3} & Look at the LEDs & The green LED is on & The green LED is turned on & OK \\
    \hline
    \textbf{4} & Prepare a timer to time the system & User is ready to time the system & The system is being timed & OK \\
    \hline
    \textbf{5} & Press the Action button and start the timer & The green LED turns off and after a maximum of 5 seconds the car starts driving & The green LED turns off and the car starts driving immediately & OK \\
    \hline
    \textbf{6} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & The car turns and drives in the pattern of the map, but it sometimes over/underturns & OK ?\\
    \hline
    \textbf{8} & Press the Action button and start the timer & The green LED turns off and the car starts driving & The LED turns off and the car starts driving immediately & OK \\
    \hline
    \textbf{9} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & Again, it drives in a pattern that matches the map, but it is not very precise & OK ?\\
    \hline
    \textbf{10} & Press the Action button & The green LED turns off and the car starts driving & The LED is off and the car starts driving & OK \\
    \hline
    \textbf{11} & Wait for car to arrive at homebase & The car is idle at homebase & Same as point 6 / 9 & OK ? \\
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Exception 1 - No available routes }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase and server is running with no routes stored} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and is monitoring the local network & Wireshark is monitoring the network & OK \\ 
    \hline
    \textbf{2} & Press the action button & [Wireshark] A request to fetch routes is sent to the server & Same as main scenario point 2 & OK \\ 
    \hline
    \textbf{3} & Prepare a timer & The user is ready to time the system & The user is timing the system & OK \\ 
    \hline
    \textbf{4} & Observe LEDs & The green LED starts blinking for 5 seconds, then the car enters idle mode & The LED blinks for 5 seconds & OK \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Exception 1 - No available routes}
\label{tab:at-usecase3exception1}
\end{table}

### Exception 2 - Network Error
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Exception 2 - Network error }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase and the server is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Prepare a timer & The user is ready to time the system & Timer is ready & OK \\ 
    \hline
    \textbf{1} & Observe the LEDs & [Visual test]The red LED starts blinking & Not implemented & FAIL \\ 
    \hline
    \textbf{2} & Wait 15 seconds & The red LED stops blinking and the car enters idle mode & Not implemented & FAIL \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Exception 2 -  Network Error}
\label{tab:at-usecase3exception2}
\end{table}
\newpage

### Extension 1 - Remaining locations in the route(excl. homebase)
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 3 - Complete delivery route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 1 - Remaining locations in the route (excl. homebase) }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is powered on and has arrived at a destination(excl. homebase) } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the Action button & The green LED turns off, and the cars starts driving & The green LED turns off and the car starts driving immediately & OK \\ 
    \hline
    \textbf{2} & Return to point 10 in the main scenario & The car resumes from point 10 & The car continues route as expected & OK \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Extension 1 -  Remaining locations in the route (excl. homebase) }
\label{tab:at-usecase3extension1}
\end{table}


# Use Case 4 - Shutdown of car
## Main scenario
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 4 - Shutdown of car} \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Main scenario }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is idle at homebase } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the Power button & The car terminates all driving instructions and powers off safely & The car turned off after the second click & OK ?? \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 4 - Main scenario}
\label{tab:at-usecase4main}
\end{table}

\newpage

# Nonfunctional Requirements

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 1 - LEDs equipped on car} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Inspect the car & The car is equipped with one green LED and one red LED & - & -\\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 1}
\label{tab:at-nonFuncUsability1}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 2 - Car equipped with speaker} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Inspect the car & The car is equipped with a speaker & Not Implemented & FAIL \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 2}
\label{tab:at-nonFuncUsability2}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 3 - Routes stored on server} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI & The Terminal UI is running & - & -\\ 
    \hline
    \textbf{2} & Create 5 routes using the Terminal UI & 5 routes have been created & - & -\\ 
    \hline
    \textbf{3} & Open the text file "logger.txt" on the server & The 5 routes are stored in the file & - & -\\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 3}
\label{tab:at-nonFuncUsability3}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 4 - User guide} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Read the user guide & The user guide explains the functionality of the car, and how to operate it & - & -  \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 4}
\label{tab:at-nonFuncUsability4}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 5 - Car equipped with buttons} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Inspect the car & The car is equipped with 2 buttons, for performing actions and power on/off & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 5}
\label{tab:at-nonFuncUsability5}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 6 - Terminal UI} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI & The server can be accessed & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 6}
\label{tab:at-nonFuncUsability6}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Usability 7 - Terminal UI text} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI & The text is size > 14, and the color of the text is in stark contrast to the background & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Usability 7}
\label{tab:at-nonFuncUsability7}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Reliability 1 - Continuous driving of car} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Start a timer & The user is timing the system & - & - \\ 
    \hline
    \textbf{2} & Run the test program ??? & The car is driving at max speed & - & - \\ 
    \hline
    \textbf{3} & Wait 10 minutes & The car is still driving & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Reliability 1}
\label{tab:at-nonFuncReliability1}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Reliability 2 - Continuous operation of server} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Start a timer & The user is timing the system & - & - \\ 
    \hline
    \textbf{2} & Start the server & The server is running & - & - \\ 
    \hline
    \textbf{3} & Wait 1 hour & The server is still running & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Reliability 2}
\label{tab:at-nonFuncReliability2}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Performance 1 - Car power on time} \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Start a timer & The user is timing the system & - & - \\ 
    \hline
    \textbf{2} & Press the power button & The car begins powering on & - & - \\ 
    \hline
    \textbf{3} & Wait 1 minute & The remote SSH connection shows "Waiting for button press/ Waiting for req route eller whatever" & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Performance 1}
\label{tab:at-nonFuncPerformance1}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{Performance 2 - Car maximum speed} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Mark a line with a length of 10 meters on a drivable surface & The testing track is ready & - & - \\ 
    \hline
    \textbf{2} & Start a time & The user is ready to time the system & - & - \\ 
    \hline
    \textbf{3} & Start the test program ??? & The car starts driving at max speed & - & - \\ 
    \hline
    \textbf{4} & Stop the timer when the car reaches the end of the line & The time for the car to travel 10 meters is noted & - & - \\ 
    \hline
    \textbf{5} & Calculate the speed of the car based on the time to travel the line & The average speed of the car is under 5 km/h & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - Performance 2}
\label{tab:at-nonFuncPerformance2}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{+ 1 - Driving environment} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Place the car indoors on a dry and flat surface & The car is in position & - & - \\ 
    \hline
    \textbf{2} & Execute a route & The car is able to drive on the surface & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - + 1}
\label{tab:at-nonFuncPlus1}
\end{table}

\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Requirement under test:}} & \multicolumn{3}{l|}{+ 2 - Outside interference} \\ 
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Pick up the car while it is driving and place it outside the designated map & The car has been moved to outside the map & - & - \\ 
    \hline
    \textbf{2} & Continue execution of route & The car is not able to find its way back to the map & - & - \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Nonfunctional Requirements - + 2}
\label{tab:at-nonFuncPlus2}
\end{table}