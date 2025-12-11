# Hardware design 
The project needed to be able to turn the LED's on and off, handle the power to our motors and regulate the voltage to said LED's and our RPi5. To do this, we are using a voltage regulator, to get our input of 7.2V to 5.1V.  Then we use three transistors to either open or close a ground connection to our LED's and motors, with the help of a signal from our RPi5. Using Ohm's law, $R = V/I$, we could find the resistances needed for the two LED's resistors, the first one being 160ohm and the other being 330ohm. Then for the resistances thats connected to our voltage regulator, we are using this formula, $V_out = 1.25V * (1 + R2/R1)$, which ends up resulting in R2 being 400ohm and R1 being 130.


\begin{figure}[H]
\begin{center}
\includegraphics[width=0.7\textwidth]{docs/appendices/pictures/multisim.png}
\caption{Multisim diagram over the currently used veroboard}
\end{center}
\end{figure}

Using the above diagram, we could then make a veroboard design.   

\begin{figure}[H]
\begin{center}
\includegraphics[width=0.7\textwidth]{docs/appendices/pictures/Veroboarddesign.png}
\caption{DIY layout over the current veroboard}
\end{center}
\end{figure}


\newpage