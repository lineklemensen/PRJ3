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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off and the local network is running} \\ 
    \hline 
    \multicolumn{5}{|c|}{} \\ 
    \hline \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\ 
    \hline 
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and monitoring the local network & & \\ 
    \hline 
    \textbf{2} & Press the 'Power' button & [Wireshark] shows the car successfully establishing a connection to the local network and the red LED turns on & & \\ 
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Exception 1 }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the 'Power' button & The red LED does not turn on & & \\ 
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is turned off and the local network is not running } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline 
    \textbf{1} & Press the 'Power' button & The red LED starts to blink & & \\ 
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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server and local network is running} \\
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
    \textbf{5} & 'Confirm' is selected & [Wireshark] A route is sent to the server & & \\ 
    \hline
    \textbf{6} & Open the text file "routes.txt" on the server and check the contents & The file contains the order of room 1, 2 and 3 & & \\
    \hline
    \textbf{8} & Look at the UI & The Terminal UI displays "The route has been successfully made" and "Press Enter to close the UI" & & \\
    \hline
    \textbf{9} & Press Enter & The Terminal UI closes & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Main scenario}
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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server and local network is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{3} & Navigate to and select 'Cancel route' & All rooms are deselected and the Terminal UI closes & & \\
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 2 - Exception 1 - The dispensary nurse selects the "Cancel" option}
\label{tab:at-usecase2exception1}
\end{table}


### Extension 1 - Room is already added
\begin{table}[H]
\begin{tabularx}{\textwidth}{| c |*{3}{X|} c |}
    \hline
    \multicolumn{2}{|l|}{\textbf{Use case under test:}} & \multicolumn{3}{l|}{Use case 2 - Create route } \\ 
    \hline
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - Room already added }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server and local network is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{3} & Select rooms 2 and 3 again & Rooms 2 and 3 will be unselected & & \\
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 3 - No rooms were selected}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The server and local network is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{2} & Press confirm before selecting any rooms & An error message is displayed on the UI. Return to point 2 in the main scenario & & \\
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{Main scenario}\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The system is running and functional} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Open the Terminal UI  & A message saying "Choose the rooms for this route" and a list of all rooms appear on the UI. A finish and cancel option appear as well & & \\ 
    \hline
    \textbf{2} & Choose room 1, 2, and 3 & Room 1, 2 and 3 are marked & & \\
    \hline
    \textbf{3} & Navigate to and select 'Finish route' & A confirmation message saying "These are your chosen rooms" and a list of the chosen rooms is displayed & & \\
    \hline
    \textbf{4} & 'Deny' is selected & All rooms are deselected. & & \\ 
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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase, the local network is running, and the server is running with a single route of 2 rooms stored} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and is monitoring the local network & & \\ 
    \hline
    \textbf{2} & Press the Action button & [Wireshark]A request to fetch routes is sent from the car to the server & & \\
    \hline
    \textbf{3} & Look at the LEDs & The green LED is on & & \\
    \hline
    \textbf{4} & Prepare a timer to time the system & User is ready to time the system & & \\
    \hline
    \textbf{5} & Press the Action button and start the timer & The green LED turns off and after a maximum of 5 seconds the car starts driving & & \\
    \hline
    \textbf{6} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & & \\
    \hline
    \textbf{8} & Press the Action button and start the timer & The green LED turns off and the car starts driving & & \\
    \hline
    \textbf{9} & Wait for the car to arrive at next location & Car has arrived at next location, and green LED is on & & \\
    \hline
    \textbf{10} & Press the Action button & The green LED turns off and the car starts driving & & \\
    \hline
    \textbf{11} & Wait for car to arrive at homebase & The car is idle at homebase & & \\
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
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase, local network is running and server is running with no routes stored} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Monitor the local network using Wireshark & Wireshark is opened and is monitoring the local network & & \\ 
    \hline
    \textbf{2} & Press the action button & [Wireshark] A request to fetch routes is sent to the server & & \\ 
    \hline
    \textbf{3} & Prepare a timer & The user is ready to time the system & & \\ 
    \hline
    \textbf{4} & Observe LEDs & [Wireshark] The green LED starts blinking for 5 seconds, then the car enters idle mode & & \\ 
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 2 - Network error }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{>{\hsize=\dimexpr 2\hsize+2\tabcolsep+\arrayrulewidth}X|}{The car is idle at homebase and the local network and server is running} \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Prepare a timer & The user is ready to time the system & & \\ 
    \hline
    \textbf{1} & Observe the LEDs & [Visual test]The red LED starts blinking & & \\ 
    \hline
    \textbf{2} & Wait 15 seconds & The red LED stops blinking and the car enters idle mode & & \\ 
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
    \multicolumn{2}{|l|}{\textbf{Scenario:}} & \multicolumn{3}{l|}{ Extension 3 - Remaining locations in the route (exel. homebase) }\\  
    \hline
    \multicolumn{2}{|l|}{\textbf{Precondition:}} & \multicolumn{3}{l|}{The car is powered on and has arrived at a destination(excl. homebase) } \\
    \hline
    \multicolumn{5}{|c|}{}\\
    \hline
    \textbf{No.} & \textbf{Action} & \textbf{Expected result} & \textbf{Actual result} & \textbf{(OK/FAIL)}\\
    \hline
    \textbf{1} & Press the Action button & The green LED turns off, and the cars starts driving & & \\ 
    \hline
    \textbf{2} & Return to point 10 in the main scenario &  & & \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 3 - Extension 1 -  Remaining locations in the route (exel. homebase) }
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
    \textbf{1} & Press the Power button & The car terminates all driving instructions and powers off safely & & \\ 
    \hline
\end{tabularx}
\caption{Acceptance test - Use Case 4 - Main scenario}
\label{tab:at-usecase4main}
\end{table}

\newpage

# Nonfunctional Requirements

Required tools for test of nonfunctional requirements: \newline
    - Car \newline
    - Server \newline
    - Client/UI \newline
    - User guide \newline
    - Charging station

\begin{longtable}{|p{0.19\textwidth}|p{0.19\textwidth}|p{0.19\textwidth}|p{0.19\textwidth}|p{0.11\textwidth}|}
\hline
\textbf{Requirement under test} & \textbf{Action} & \textbf{Expected Result} & \textbf{Actual result} & \textbf{(OK/FAIL)} \\  
\hline
Functionality 1 - Car requests routes from server & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase}\\
\hline
1 & Open Wireshark to monitor the local network & Wireshark is monitoring the local network & H & H\\
\hline
2 & Press the action button & [Wireshark] The car sends a request to the server, and the server responds & H & H\\
\hline
Functionality 2 - Car continues route & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at destination}\\
\hline
1 & Press the action button & The car starts driving to continue its route & H & H\\
\hline
Usability 1 - The car is equipped with two LEDs & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase}\\
\hline
1 & Inspect the car & [Visual test] On the car is two LEDs, one green and one red & H & H\\
\hline
Usability 2 - The car is equipped with a speaker & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase, server is running and has <1 routes stored}\\
\hline
1 & Press the action button & When the green LED turns on, a sound is also played to indicate the car is ready to execute route & H & H\\
\hline
Usability 3 - User guide !!!!!!!!!!!!!!!!!!!!!!!!!!!! & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{A user guide has been written ???????}\\
\hline
1 & Write a user guide ???? & A user guide has been written ?????? & H & H\\
\hline
Usability 4 - User guide & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase}\\
\hline
1 & Read the user guide & The user guide includes troublehooting for 5 common error-scenarios & H & H\\
\hline
Usability 5 - Buttons on car & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase}\\
\hline
1 & Inspect the car & [Visual test]The car is equipped with two buttons labelled 'Action' and 'Power' & H & H\\
\hline
Usability 6 - UI & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase}\\
\hline
1 & Start creating route on client & A UI opens & H & H\\
\hline
Usability 7 - Text on UI & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase}\\
\hline
1 & Open the Client UI & The size of text in the UI is > 14pt, and the color of the text is a contrasting color to the background  & H & H\\
\hline
2 & Shine a flashlight at the screen or recreate a high-light environment in another way & The text in the UI is still readable & H & H\\
\hline
Reliability 1 - Continuous driving & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{The car is fully charged and 10+ routes are ready in server}\\
\hline
1 & Start a timer & The user is timing the system & H & H\\
\hline
2 & Press the action button & The car requests and receives a route, and the green LED turns on & H & H\\
\hline
3 & Press the action button & The car starts driving, and arrives at next destination & H & H\\
\hline
4 & Repeat point 3 until car is back at homebase & The car is at homebase and ready to request another route & H & H\\
\hline
5 & Repeat point 1 to 4 until 65 minutes have passed(To account for delays when fetching/continuing routes, etc.) & 65 minutes have passed and the car is still executing routes without issues & H & H\\
\hline
Reliability 2 - Continuous running of server & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Server is running and car is idle at homebase}\\
\hline
1 & Prepare and start a timer or stopwatch & The user is tracking the time & H & H\\
\hline
2 & Wait until 6 hours have passed, then press the action button on the car to request a route & The route is fetched without issues & H & H\\
\hline
Reliability 3 - Continuous running of server & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Server is running and car is idle at homebase}\\
\hline
1 & Prepare and start a stopwatch or timer & The timer/stopwatch is tracking the time & H &\\
\hline
2 & Remove the current battery from the car & The battery is removed successfully & H & H\\
\hline
3 & Install a new battery in the car & The new battery is installed successfully & H & H\\
\hline
4 & Stop the stopwatch/timer & Less then 10 minutes have passed & H & H\\
\hline
Reliability 4 - Success rate of routes & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase and server is running with 10 routes stored}\\
\hline
1 & Press the action button & The green LED lights up & H & H\\
\hline
2 & Press the action button & The car starts executing route & H & H\\
\hline
3 & Wait for car to arrive at destination & The car is at destination, and green LED is on & H & H\\
\hline
4 & Repeat point 2 to 3 until route is complete & The car is idle at homebase & H & H\\
\hline
5 & Repeat step 1 to 4 until 10 routes have been completed in total & The car completed at least 9 routes & H & H\\
\hline
Reliability 5 - Car drives on wet floor & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase and server is running}\\
\hline
1 & Grab a bottle of water(500 ml) and pour it evenly over the surface that makes up your testing environment & The surface the car is going to drive on is wet & H & H\\
\hline
2 & Press the action butto on the car & The green LED turns on & H & H\\
\hline
3 & Press the action button & The car starts executing route & H &\\
\hline
4 & Watch car while its exeucting route & The car cannot complete the route & H & H\\
\hline
Performance 1 - Button response time & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase and server is running}\\
\hline
1 & Open Wireshark to monitor the local network & Wireshark is monitoring the local network & H & H\\
\hline
2 & Prepare and start stopwatch/timer & The user is now tracking the time & H & H\\
\hline
3 & Press the action button & [Wireshark] The car requests a route within 1 second & H & H\\
\hline
Performance 2 - Car startup time & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is turned off and server is running}\\
\hline
1 & Prepare a stopwatch/timer & The user is tracking the time & H & H\\
\hline
2 & Press the power button, and wait for the green LED to turn on & The green LED turns on within 1 minute & H & H\\
\hline
Performance 3 - Car minimum range & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle and fully charged at homebase and server is running}\\
\hline
1 & Find the longest possible route in your testing setup & The longest route is found & H & H\\
\hline
2 & Create make multiple copies of said route on server, so that the total length of routes stored is 500 meters or higher & Routes of total length < 500 meters have been stored on server & H & H\\
\hline
3 & Press the action button & The green LED turns on & H & H\\
\hline
4 & Press the action button & The car starts driving to next destination & H & H\\
\hline
5 & Wait for car to reach destination & The car has reached its destination and the green LED is on & H & H\\
\hline
6 & Repeat point 4 through 5 until car has completed route and is idle at homebase & The car is idle at homebase & H & H\\
\hline
7 & Repeat point 3 through 6 until car the total length driven by car exceeds 500 meters & The battery is still powering the car & H & H\\
\hline
Performance 4 - Car maximum speed & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is idle at homebase and server is running}\\
\hline
1 & Prepare a speedometer & The speed of the car is ready to be read & H & H\\
\hline
2 & Press the action button & The green LED turns on & H & H\\
\hline
3 & Press the action button & The car starts driving to next destination & H & H\\
\hline
4 & Track the speed of the car during the completion of the route, until the route car has reached its destination & The car is idle at destination & H & H\\
\hline
5 & Repeat point 3 through 4 until route is completed, while still tracking the speed & The car never exceeds a speed of 5 km/h & H & H\\
\hline
XXXXX xxxxx - Car car car & Precondition: & \multicolumn{3}{|p{0.5\textwidth}|}{Car is car car}\\
\hline
1 & do car car & car car & H & H\\
\hline
1 & do car car & car car & H & H\\
\hline

\end{longtable}


