---
title: "SW3 Semester Project"
subtitle: "Technical Analysis"
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

# Technical analysis

We decided to rate with a score from 1 to 5, where a higher score is better.

## Pathfinding algorithm

|                       | Dijkstra |  A*   | A* w/ multithreading |
| :-------------------- | :------: | :---: | :------------------: |
| Speed                 |    1     |   3   |          5           |
| Processing complexity |    4     |   3   |          1           |
| Memory impact         |    1     |   2   |          2           |
| Developer cost        |    1     |   2   |          4           |
: Analysis of pathfinding algorithms

We have found 3 pathfinding algorithms to compare, Dijkstra's algorithm[@Dijkstra-Wikipedia], A\* algorithm[@AStar-Wikipedia], and A\* using multithreading to improve convergence speed. Overall the algorithms are pretty similar in the sense that they each provide improvement on their predecessor, however at the cost of being more complex in both implementation and execution. Dijkstra's algorithm is the simplest conceptually as it simply naively traverses every possible path until it finds its goal. A\* improves on this by adding a heuristic element that helps push/weigh it towards its goal so it is less encouraged to search irrelevant routes, however the value of this heuristic function hinges on its quality, as a bad one can hurt the algorithm over the naive approach of Dijkstra. The last option is to use A\* with multithreading to speed up convergence rate, however this would also add extra overhead to developer time, as with anything multithreading, it can be hard to debug issues.

The attributes we want to prioritize are speed and processing complexity, as our goal is to be able to find a path quickly but do not want to consume all the resources of the RPi. So a balance between the two are important.
Developer cost is also an important factor as we want to be able to actually get a finished and working pathfinding implementation, since if developer cost is too high we might not be able to finish it in time.

**Speed**

When we are talking about speed we are mostly concerned with convergence speed, and in that aspect there is a clear winner amongst our choices, A\* with multithreading.

**Processing complexity**

Although A\* with multithreading is the fastest, it is also the most complex to implement, as we need to be careful that a thread does not attempt to search the same space another thread has already cleared. Here Dijkstra and normal A\* have the advantage as everything occurs on the same thread, and each new node is only traversed once.

**Memory impact**

The amount of memory each algorithm consumes is largely negligible but does scale primarily with graph/map size, when considering this, Dijkstra is the worst of the three since worst case the amount of nodes it has to check scales quadratically with the distance to the goal. Of course multithreaded A\* versus its single-threaded counterpart does add some memory overhead, however it isn't enough to cost any points.

**Developer cost**

Since the algorithms are related it means that we would be able to implement them from the simplest to most complex without needing to incur the full developer cost. As a result of this we have the capability to decide if we have time to attempt the better/faster iterations depending on the amount of ongoing work.

With all of the listed points in mind, our primary goal is to at least get a fully working A\* algorithm implemented, with multithreading as a bonus if time is available.

\newpage

## Car tracking scheme

|                           | Dead reckoning | Line following |  GPS  |
| :------------------------ | :------------: | :------------: | :---: |
| Precision                 |       5        |       4        |   1   |
| Drift/error accumulation  |       3        |       5        |   5   |
| Robustness                |       4        |       3        |   5   |
| Price                     |       5        |       2        |   4   |
| Upkeep                    |       5        |       2        |   5   |
| Developer cost/complexity |       4        |       3        |   5   |

: Analysis of methods for tracking the cars position

We have found three different strategies for tracking the cars
position. These are dead reckoning[@dead-reckoning-wikipedia], line following [@line-following-robot-arduino] and GPS[@GPS-wikipedia].
Dead reckoning is way to calculate the current position of of a
moving object by using a previously determined position and
incorporating the speed, direction and elapsed time. For line
following the idea is that the car would follow a line to its
destination. Two options for seeing the line are, a camera or
an ultraviolet sensor. The last option is to use a GPS to keep
track of the cars position.

For this project precision and drift/error accumulation are the
most important things to consider since they are vital for the
success of the tracking. The drift/error accumulation could be
dealt with by not having the car drive too long distances.
Developer cost/complexity is also very important since we want
the project to be of a scope that can be finished on time.

**Precision**

Dead reckoning has a very high precision if the correct hardware is
used. One of the simplest ways to get a high accuracy is by using
encoders. Encoders can break a full rotation of the wheel into many
signals, which gives a higher precision for the estimated speed used
for the calculations.

Line following would be able to get toward its destination correctly
but might struggle with knowing when exactly it has arrived, due
to there being a need for a physical stop sign.

GPS has different levels of precision depending on the specific product.
Range of errors typically fall within 1-5 meters. In this case even
an error of 1 meter could make entering a room hard.

**Drift/error accumulation**

Dead reckoning has a slight drift that slowly accumulates until it
reaches a known position. This could be dealt with by having the
position reset when it returns to start.

Line following does not have any drift.

GPS does not have any drift

**Robustness**

Dead reckoning using encoders would not function if the rotation
of the wheels does not correspond to the distance traveled, and is therefor largely hardware dependent.

If the line following version ends up away from the line or the
line gets damaged the system would not work.

The GPS would only really fail if the satellite connection can not
be established.

**Price**

Dead reckoning only requires the motors have encoders. Encoders
are pretty cheap so this does not add much to the cost.

Line following would require making a line on the floor to follow
and a camera or ultra violet sensor. This is a significant cost.

GPS would require adding a GPS module which increases the cost.

**Upkeep**

Dead reckoning does not acquire additional upkeep.

Line following requires that the line is constantly kept clear
enough for the camera/ultra violet sensor to recognize it.

GPS does not require additional upkeep.

**Developer cost/complexity**

Dead reckoning only require the addition of an encoder, with the software being rather easy to implement.

Line following requires a hardware component to recognize the line.
This adds an additional point of failure. Software wise this is
more complex, requiring some kind of image processing.

GPS would be the simplest to implement since it involves integrating
a GPS module and then using the data.

In conclusion we have decided to use dead reckoning since it has
the highest precision is simple enough to implement and the biggest
downside can be dealt with by not having the car drive too long
distances.

\newpage

## Motor speed control

|            |  PID  | Linear interpolation |
| :--------- | :---: | :------------------: |
| Smoothness |   5   |          2           |
| Precision  |   4   |          4           |

There are two different kind of motor speed control we have chosen to look into for this project. The ones we have picked to choose from are Proportional-Integral-Derivative controller, PID control for short[@PID-Wikipedia] and Linear interpolation[@LinInt-Wikipedia].

**Similarities**

Since both PID control and interpolation have many similarities, because their purpose aligns with a good degree of control and speed changes, we will start with the likeness of the two.

They both deal with speed transition, where PID tries to bring the actual speed of the object to travel as smoothly to the target as possible, by adjusting the input throughout the travel, whereas line interpolation on the other hand creates a smooth ramp from one point to another.

Both have a goal of avoiding sudden jumps in speed, where PID control will naturally dampen if it overshoots and it is well tuned and Linear interpolation prevents step changes by gradually ramping throughout.
For stability reason and cost reduction, they try to improve the life spans of the motor and mechanical safety by smoothing out motor control and not doing sudden changes in the speed which stresses the gears, belts etc.

**Differences**

Even with lots of similarities they complete the task very differently. PID control is a control method with a closed loop where the motor speed will be adjusted based on the error between the actual speed and target speed using proportional, integral and derivative terms. 

**PID Pros**

PID compensates for the load changes since it is always changing its parameters, which also makes the driving smooth and we can accurately track the speed. 
PID works with high precision to a degree that it is industrial-grade.

**PID Cons**

One of the big issues with PID control is it that it can be very time consuming with regards to properly tuning and computation time.

Linear interpolation is a feedforward method where the motor speed reference is ramping up or down linearly over time between two set points given, usually from start to a given target, although at the "corners" of the ramp.

**Linear Interpolation Pros**
Very simple to implement, so wont be as time consuming as PID control.

Linear interpolation avoids mechanical shocks and tear by preventing sudden jumps in speed.

It makes the motion of the vehicle predictable.

**Linear Interpolation Cons**
It is an open-loop, which means it does not correct for load changes and resistance increases, which may lead to the actual speed may lag behind its target.
Using linear interpolation makes it so there is no guarantee of the precise speed giving unless the motor is loaded exactly like it is tuned.
Overall limited adaptability.

**Conclusion**

Even though PID control is the harder to implement option, more time consuming and requires fine tuning, for this project it is a better option than linear interpolation, because linear interpolation might provide an easier implementation and ease of use, but the drawbacks with its tuning and adaptability makes it so that PID control is the better option.
In conclusion we are going to use PID control for motor speed control for this project. 

\newpage

## Network Protocol

| Network Protocol |  TCP  |  UDP  |
| :--------------- | :---: | :---: |
| Latency          | High  |  Low  |
| Reliable         |  Yes  |  No   |
| Synchronized     |  Yes  |  No   |
| Ordered          |  Yes  |  No   |
: Analysis of network protocols

**TCP**

TCP stands for Transmission Control Protocol, and is a connection-oriented protocol. It is a slower protocol than UDP, since it establishes a synchronized connection, ensuring ordered delivery of data and no loss of data or packages. TCP is used for browsing the web, sending emails and files, and other such systems that don’t require low latency or cannot afford data loss.

TCP ensures a reliable connection, which is preferable for our project, since data loss could cause unpredictable behavior of our system, and the higher latency doesn’t negatively impact the system in any significant way.

**UDP**

UDP stands for User Datagram protocol, and is a connection-less protocol. This means the connection will be a lot faster, at the cost of reliability, since there is no way to acknowledge successful transfer of data. UDP is commonly used for streaming and online video games, that benefit greatly from the reduced latency, and don’t have big drawbacks as a result the data loss that may occur using UDP. 


**Conclusion**

For our project, we do not require a low-latency protocol, and data loss could be catastrophic to the routing/functioning of the car. In conclusion, we have decided to use TCP, since the drawbacks of higher latency are relatively small, compared to the potentially huge issues we could encounter using UDP. 


\newpage

## Programming language

|                      |   C   |  C++  |
| :------------------- | :---: | :---: |
| Object oriented      |  No*  |  Yes  |
| Library availability |   3   |   5   |
| Developer knowledge  |   1   |   3   |
: Analysis of programming languages

For this project we are required to have the combined code be at least 90% C or C++.
Since there is not much you can do with the remaining 10% in terms of useful programming, 
we would want to write the whole core program in one of those two languages.

**Object oriented**

Although C isn't intended to be object oriented you can of course write it in an object oriented way. However at that point you might as well simply use C++.

**Library availability**

The standard library for C++ is considerably larger than C's standard library. Because of this C++ is more appealing to us.

**Developer knowledge**

For most of our current study we've worked with C++, and have only had an introductory course on C over a couple lessons. With this in mind, C++ will lead to faster development as we're more comfortable with the language and know more of its features and available libraries. Also since C++ is backwards compatible with C we retain the ability to use low-level C in cases it becomes necessary.

**Conclusion**

Due to the comfortability with developing in C++ and our overall knowledge and experience with it, it will be what we write the program

\newpage

## Battery

|                   | 7.2V battery | 9.6V battery |
| :---------------- | :----------: | :----------: |
| Capacity          |      5       |      3       |
| Weight            |      3       |      4       |
| Voltage stability |      5       |      3       |
| Recharge time     |      4       |      5       |
| Price             |      5       |      5       |
| Developer cost    |      5       |      5       |
: Analysis of battery types for the car

**Evaluation**
Two batteries were considered: **7,2V/3000mAh NiMH battery** and **9,6V/2000mAh NiMH battery**. There are two determining factors when deciding which battery to use. First, **runtime**(Watt-hours): A higher runtime provides the vehicle with longer active time before it needs recharging. Second **overcurrent:** Risk of overcurrent increases when a battery has higher voltage than a component, which can cause overheating.


**Conclusion**
The **7,2V/3000mAh NiMH battery** is chosen since it satisfies our requirements the best with regards to runtime and overcurrent.

\newpage

## H-Bridge / Motor Driver

| Characteristic                    | L9110 | Monster Moto Shield (VNH2SP30) |
| :-------------------------------- | :---: | :----------------------------: |
| Current capacity / power handling |   2   |               5                |
| Voltage range                     |   4   |               5                |
| Efficiency / voltage drop         |   3   |               5                |
| Reliability / protection          |   3   |               5                |
| Control flexibility               |   3   |               5                |
| Ease of use                       |   5   |               3                |
| Cost                              |   5   |               3                |
: Analysis of H-Bridge motor drivers

We compared two motor driver modules for the vehicle: the **L9110 Dual H-Bridge Driver** and the **Monster Moto Shield (VNH2SP30)**.  
Both are commonly used in robotics, but they differ significantly in power capability, voltage range, and overall robustness.

**Technical Overview**

**L9110**  
The L9110 is a compact, low-cost H-bridge driver supporting **2.5–12 V** and delivering around **0.8 A continuous** per channel (up to 2 A peak).  
It is simple to use and ideal for small DC motors or lightweight robots. However, it lacks safety features such as overcurrent and thermal protection, making it unsuitable for high-power applications.

**Monster Moto Shield (VNH2SP30)**  
The Monster Moto Shield, built around two **VNH2SP30 full-bridge drivers**, can supply **14 A continuous** and **30 A peak** current per channel with a voltage range of **5.5–16 V**.  
It includes thermal shutdown, undervoltage, and current sensing protections, making it well-suited for larger robotic platforms and heavy-duty DC motors.

**Evaluation**

The **L9110** is sufficient for small robots, but our selected **Devantech EMG49 motor** can draw up to **13 A** at stall, far exceeding its capacity.  
In contrast, the **Monster Moto Shield** easily supports that current while offering protection and monitoring features.  
Its downsides are **higher cost**, **larger size**, and **slightly more complex wiring**, but these trade-offs are acceptable given its performance.

**Conclusion**

The **Monster Moto Shield** was chosen for this project because of its **high current handling**, **robust protection features**, and **compatibility** with the EMG49 motor.  
The **L9110** was rejected due to its low power limit, despite being more affordable and easier to implement.

\newpage

## Motor

**Technical Specifications**

| Specification                 | DC 6V     | DC 24V   |
| :---------------------------- | :-------- | :------- |
| Rated voltage                 | 6V        | 24V      |
| Rated torque                  | 10 kg·cm  | 16 kg·cm |
| Rated speed                   | 210 rpm   | 122 rpm  |
| No-load current               | 0.13A     | 500 mA   |
| Stall current                 | 3.2A      | 13A      |
| Stall power                   | 19.2 W    | 312 W    |
| Encoder counts per revolution | 341.2 PPR | 980 PPR  |
| Gear ratio                    | 1:34      | 49:1     |


**Performance**

The 24V motor delivers greater torque and higher encoder resolution, making it well-suited for heavy-duty applications requiring precise positioning and load handling. However, these advantages come at the cost of significantly higher current draw, greater heat generation, and the need for more robust power electronics. In the context of this lightweight robotic platform, this level of performance is unnecessary and excessive - effectively overkill for the intended requirements.

**Conclusion**

The 6V DC Geared Motor w/Encoder – 210 RPM 10 Kg·cm DFrobot, FIT0521, was chosen as the final drive motor.
Although the 24V variant provides superior torque and encoder precision, it is overkill for this application, leading to unnecessary power consumption, thermal load, and cost.

**Single or dual motor**

Two configurations were considered: **single-motor** and **dual-motor**.  
A single-motor design would require a mechanical differential to steer, increasing complexity despite lower power use.  
The **dual-motor** approach, using one motor per wheel, enables differential steering, simplifying control and greatly improving maneuverability and responsiveness.

| Characteristic  | Single Motor | Dual Motor |
| :-------------- | :----------: | :--------: |
| Maneuverability |      2       |     5      |
| Torque          |      3       |     5      |
| Complexity      |      5       |     3      |
| Power usage     |      4       |     3      |
| Redundancy      |      1       |     4      |
| Cost            |      5       |     3      |
: Analysis of motor configurations

**Conclusion**


The 6V dual-motor configuration offers the optimal combination of control accuracy, maneuverability, and energy efficiency, while maintaining compatibility with the vehicle’s battery and overall power design.
This setup ensures reliable, responsive, and well-balanced performance, making it the most practical and efficient solution for the project.

\newpage

## Final decision

| Component                   | Selected Option                | Key Advantages                                              | Trade-offs                                |
| :-------------------------- | :----------------------------- | :---------------------------------------------------------- | :---------------------------------------- |
| **Battery**                 | 7,2V/3000mAh NiMH battery      | Larger capacity                                             | Longer charge time due to larger capacity |
| **H-Bridge / Motor Driver** | Monster Moto Shield (VNH2SP30) | High current handling, protection, and dual-channel control | Larger size, higher cost                  |
| **Motor**                   | FIT0521 Dual motors            | High torque, encoder feedback, precise control              | Higher power consumption, increased cost  |


The **FIT0521t** motors combined with the **Monster Moto Shield** form a reliable drive solution.  
This pairing supports precise closed-loop control with encoder feedback and provides the robustness required for operation. The 3000mAh battery chosen will also be able to power the components for an extended length of time between charges.

\newpage

# References #