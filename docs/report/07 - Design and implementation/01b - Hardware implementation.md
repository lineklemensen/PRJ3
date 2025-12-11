# Hardware implementation
During the testing of the first version of our veroboard, we found out that the chosen voltage regulator couldn't handle the current needed to power on our RPi5. For this reason there was a need to look for a new voltage regulator, there was then made a new version of our veroboard design, the one currently in use, which fixed all the issues with bad parts.   

While implementing the dual H-bridge and motors, we found out that one of the sides H-bridge was not working as we expected so we came to the conclusion that it was faulty. For this reason we changed from using the Monster dual H-bridge to using a new one we got from Elab.

The cars frame, as shown in the below figure, is a solid 6mm plank of fibreboard. After the board got made to our requested size, and using the size of the RPi5, H-bridge, battery and veroboard, we were able to put spots on the board for where things were to be placed and drill out holes for bolts, that could hold the parts. 

While putting bolts on the plank, there was a realization that the nuts on the bolts would hit metal parts on the RPi5, and we were unsure if the RPi5 would short circuit so that plan was scrapped. The plan changed to using plastic legs to hold the RPi5 up into the air, and then hot glueing the plastic legs to the plank. The battery was also to big to just use the same bolts as for the motors, so instead zip ties was used to hold the battery down, but later this was changed to use elastic cord. 

\begin{figure}[H]
\begin{center}
\includegraphics[width=0.7\textwidth]{docs/appendices/pictures/car.png}
\caption{The "finished" car}
\end{center}
\end{figure}

\newpage