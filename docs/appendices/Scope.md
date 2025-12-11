---
title: "SW3 Semester Project"
subtitle: "Scope"
fontsize: 12pt
geometry: margin=1.5cm
---

\begin{center}


\includegraphics[width=0.28\textwidth]{docs/appendices/pictures/AU.png}


\vspace{0.6cm}


\begin{tabular}{r r r}
\hline
\textbf{Students} & \textbf{Student number} & \textbf{Initials} \\
\hline
Johan Høffner & 202409238 & JH \\
Line Nystrup Klemensen & 202407497 & LK \\
Nicolai Broholm Hansen & 202409080 & NH \\
Frederik Vagn Lorenzen & 202406665 & FL \\
Daniel Jenrich Svendsen & 202408416 & DS \\
Mikkel Kristiansen & 202301563 & MK \\
Kasper Ørtoft Rasmussen & 202207121 & KR \\
Christopher Frank Jørgensen & 202300791 & CJ \\
\hline
\end{tabular}

\vspace{0.8cm}

\textbf{Project Counselor} \\
“Jenny” Jung Min Kim


Submission date: \textbf{12-12-2025} \\[6mm]

University Name: Aarhus University \\
Degree / Program: Software Engineering

\end{center}

\clearpage


\clearpage

# Scope of the project

## Project concept delimitation

The project concept focuses on designing a basic functional prototype system that supports the delivery of medicine a hospital setting. The system consists of a server that receives user input from a dispensary nurse and forwards a list of rooms to the car. Then the car performs simple pathfinding to the given rooms and moves along the route.

We decided to limit the project concept to a simplified workflow where the car drives to predefined rooms in an indoor environment. The concept demonstrates the core interaction between the server, the car and the user, including receiving room lists, calculating Astar pathfinding, waiting for user confirmation and driving between the fixed locations.

The project concept excludes more advanced features like obstacle detection, dynamic environmental sensing etc.

We also exclude integration with external hospital IT systems, authentication systems, or any other form of medication verification. The concept doesn't cover secure transport mechanisms, real-world safety regulations or large scale deployment with multiple cars 

These points are excluded because they require additional hardware, more complex software, and much more time than the project allows. They are not necessary either to demonstrate the core functionality of helping nurses at the hospital by doing the medicine delivery for them.


## The scope of the project

The project is scoped to demonstrate the core workflow of receiving delivery orders, sending the car on a route, and confirming the arrival of the car on the given locations. Our focus is to showcase how a simple system can support nurses in their daily tasks by reducing the workload and risks of forgetting the medicine

The project does not however aim to develop a fully autonomous or hospital-ready solution. However it aims to make a controlled prototype with limited features, allowing us to focus on the interactions in the system and with the nurses.


## Summary

The project is scoped on developing a simple prototype system that demonstrates how medicine delivery can be supported through basic automation. The system includes a server that receives input from a dispensary nurse and a car that drives to a predefined room based on a provided list.

The project focuses on the essential functions needed to show the interaction between the server, the car and the user. Advanced features such as fully autonomous navigation, dynamic obstacle detection, external IT integration or real hospital deployment are not included. The goal is to present a clear and functional concept that illustrates how automated delivery could assist nurses in their daily workflow