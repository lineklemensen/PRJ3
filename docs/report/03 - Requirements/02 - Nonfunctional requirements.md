# Nonfunctional requirements {-}

## Usability {-}

1. Accessibility
    1. The car must be equipped with two LEDs, one green and one red.
    2. The car could have a speaker.
   
2. Documentation
    1. At least 5 routes should be stored in a JSON file on the server.
    2. A short user guide ($\leq$ 2 pages, printed and digital) could be available near the charging station.
    
3. User Interface
    1. The car must be equipped with 2 buttons, one for performing actions, one for power.
    2. The server must be accessed using a terminal UI on a PC on the local network.
    3. The User Interface must use text $\geq$ 14pt, in a high contrast color compared to the background.

## Reliability {-}

1. Availability
    1. The car must be operable for at least 10 minutes of continuous driving without restart or charging.
    2. The server should be able to run continously for at least 1 hour.
   
## Performance {-}

1. Efficiency & Speed
   1. The car must be ready for operation within 1 minute of power-on.
   2. The car must drive at an maximum speed of 5 km/h.

## + {-}

1. Constraints
   1. The car must be operable indoors on flat and dry surfaces.
   2. The system won't handle any outside interference.


## Limiting {-}
MOSCOW is used to limit our nonfuntional requirements.

\begin{table}[H]
\begin{tabularx}{1\textwidth} { 
  | >{\raggedright\arraybackslash}X 
  | >{\raggedright\arraybackslash}X 
  | >{\raggedright\arraybackslash}X  
  | >{\raggedright\arraybackslash}X | }
 \hline
 \textbf{Must} & \textbf{Should} & \textbf{Could} & \textbf{Won't}\\
 \hline
  U1.1, U3.1, U3.2, U3.3, R1.1 & U2.1, R1.2, P1.1, P1.2, +1.1 & U1.2, U2.2 & +1.2\\
 \hline
\end{tabularx}
\caption{MOSCOW}
\end{table}