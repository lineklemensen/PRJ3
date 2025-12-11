# Results

Shown below is the results of our acceptance test for the main scenario of Use Case 3. For all results, see Acceptance Test in appendices.

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

\newpage

# Discussion

Most of the test that did not succed can be narrowed down to two major reasons. These boil down to: bad hardware and prioritization under our time limit.

\vspace{0.5cm}

An easy example of the hardware failing comes in the form of one of the two motors that were used, had a lower output then the other. This meant that, when both were sat to operate at 70% duty cycle one of them would output less then the other. This threw off the path finding, resulting in some of the test partially passing, due to difference between where it was contra where it should be. To try and salvage, this a function was implementated in the code to try and make the duty cycle sync up. This did not completly solve the problem but helped lessen the over/under shooting of the destination it was supposed to reach, as well as make the car drive in a straight line more consistently.  

Another such issue appeared when switching to a different H-Bridge, which had a bigger internal resistor which meant the motors got less voltage. This, as well as the added weight of the rest of the car, meant higher duty cycles were required to maintain the same speeds, which threw off our PID tuning.

Lastly concerning hardware issues was the third wheel or the back wheel. This wheel is essentially a shopping cart wheel, which turned out to be a slight problem when the car had to do a hard turn or turn around, because the wheel would not be in the correct position and therefore create added resistance to the car when it tried to turn. If more time had been available, a ball wheel could have been implemented instead to eliminate the problem.

\vspace{0.5cm}

With this project, a lot of expectations and ideas got thrown into it. However, as it later became evident, not all of them were able to be implemented within the time limitation on the project. Because of that, some tests  failed, since other parts of the project got prioritized as being more important than others. Among these are blinking LEDs and a user manual, since that was not deemed crucial enough for the project to be prioritized above other parts. Most of these parts that have been down prioritized have been either exstentions or exceptions to our use cases, which were added to make the project more user friendly and help find potential errors in either hardware or software. The parts that were considered to be more important than these, were the requirements that would form the minimum requirements to make a functional prototype and thereby a proof of concept. 