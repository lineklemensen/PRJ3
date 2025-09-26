# Technical analysis
We decided to rate with a score from 1 to 5, where a higher score is better.

\newpage
## Pathfinding algorithm

|                       | Dijkstra | A*  | A* /w multithreading |
| --------------------- | -------- | --- | -------------------- |
| Speed                 | 1        | 3   | 5                    |
| Processing complexity | 4        | 3   | 1                    |
| Memory impact         | 1        | 2   | 2                    |
| Developer cost        | 1        | 2   | 4                    |
: Analysis of pathfinding algorithms

We have found 3 pathfinding algorithms to compare, Dijkstra's algorithm[@Dijkstra-Wikipedia], A* algorithm[@AStar-Wikipedia], and A* using multithreading to improve convergence speed. Overall the algorithms are pretty similar in the sense that they each provide improvement on their predecessor, however at the cost of being more complex in both implementation and execution. Dijkstra's algorithm is the simplest conceptually as it simply naively traverses every possible path until it finds its goal. A* improves on this by adding a heuristic element that helps push/weight it towards its goal so it is less encouraged to search wasted routes, however the value of this heuristic function hinges on its quality, as a bad one can hurt the algorithm over the naive approach of Dijkstra. The last option is to use A* with multithreading to speed up convergence rate, however this would also add extra overhead to developer time, as with anything multithreading, it can be hard to debug issues.

The attributes we want to prioritize are speed and processing complexity, as our goal is to be able to find a path quickly but do not want to consume all the resources of the RPi. So a balance between the two are important.
Developer cost is also an important factor as we want to be able to actually get a finished and working pathfinding implementation, since if developer cost is too high we might not be able to finish it in time.

### Speed
When we are talking about speed we are mostly concerned with convergence speed, and in that aspect there is a clear winner amongst our choices, A* with multithreading.

### Processing complexity
Although A* with multithreading is the fastest, it is also the most complex to implement, as we need to be careful that a thread does not attempt to search the same space another thread has already cleared. Here Dijkstra and normal A* have the advantage as everything occurs on the same thread, and each new node is only traversed once.

### Memory impact
The amount of memory each algorithm consumes is largely negligible but does scale primarily with graph/map size, when considering this, Dijkstra is the worst of the three since worst case the amount of nodes it has to check scales quadratically with the distance to the goal. Of course multithreaded A* versus its single-threaded counterpart does add some memory overhead, however it isn't enough to cost any points.

### Developer cost 

Since the algorithms are related it means that we would be able to implement them from the simplest to most complex without needing to incur the full developer cost. As a result of this we have the capability to decide if we have time to attempt the better/faster iterations depending on the amount of ongoing work.

With all of the listed points in mind, our primary goal is to at least get a fully working A* algorithm implemented, with multithreading as a bonus if time is available.


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
a ultra violet sensor. The last option is to use a GPS to keep 
track of the cars position.

For this project precision and drift/error accumulation are the
most important things to consider since they are vital for the
success of the tracking. The drift/error accumulation could be 
dealt with by not having the car drive too long distances.
Developer cost/complexity is also very important since we want 
the project to be of a scope that can be finished on time.

### Precision
Dead reckoning has a very high precision if the correct hardware is
used. One of the simplest ways to get a high accuracy is by using 
encoders. Encoders can break a full rotation of the wheel into many
signals, which gives a higher precision for the estimated speed used
for the calculations.

Line following would be able to get toward its destination correctly
but might struggle with knowing when exactly it has arrived. Due 
to there being a need for a physically stop sign.

GPS has different levels of precision depending on specific product.
Range of errors typically fall within 1-5 meters. In this case even
a error of 1 meter could make entering a room hard.

### Drift/error accumulation
Dead reckoning has a slight drift that slowly accumulates until it
reaches a known position. This could be dealt with by having the 
position reset when it returns to start.

Line following does not have any drift.

GPS does not have any drift

### Robustness
Dead reckoning using encoders would not function if the rotation
of the wheels does not correspond to the distance traveled. For 

If the line following version ends up a way from the line or the
line gets damaged the system would not work.

The GPS would only really fail if the satellite connection can not
be established.

### Price
Dead reckoning only requires the motors have encoders. Encoders
are pretty cheap so this does not add much to the cost.

Line following would require making a line on the floor to follow 
and a camera or ultra violet sensor. This is a significant cost.

GPS would require adding a GPS module which increases the cost.

### Upkeep
Dead reckoning does not acquire additional upkeep.

Line following requires that the line is constantly kept clear
enough for the camera/ultra violet sensor to recognize it.

GPS does not require additional upkeep.

### Developer cost/complexity
Dead reckoning only require the addition of an encoder. This makes
hardware a unlikely failure point. The software is also not to 
complex to implement.

Line following requires a hardware component to recognize the line.
This adds an additional point of failure. Software vise this is 
more complex, requiring some kind of image processing.

GPS would be the simplest to implement since it involves integrating
a GPS module and then using the data.


In conclusion we have decided to use dead reckoning since it has
the highest precision is simple enough to implement and the biggest
downside can be dealt with by not having the car drive too long 
distances.

\newpage

## Motor control speed

There are two different kind of motor control speed we have chosen to look into for this project. Those we have picked to are Proportional-intergral-derivative controller, PID control for short [@https://en.wikipedia.org/wiki/Proportional%E2%80%93integral%E2%80%93derivative_controller]
and Linear interpolation [@https://en.wikipedia.org/wiki/Linear_interpolation].

### Similarities:
Since both PID control and interpolation have mane simlarities because of their purpose alines with good control quality and motor speed changes will we start witht the alikeness of the 2.

They both deal with speed transition, where PID tires to bring the actual speed of the object to act as smoothly to the target as possible by adjusting the input thoughout the travel
Where interpolation on the other hand creates a smooth ramp from one point to another.

Both aswell try to avoid sudden jumps in speed, Where PID control will naturally dampen if it overshoot and it is well tuned and Linear interpolation prevents step changes by gradually ramping thoughout.
For stability reason and cost reduction, they try to improve the life spans of the motor and mechanical safte by smoothing out motor control and not doing sudden changes in the speed which stresses the gears, belts etc.

### Differences:
Even with lots of similarities they complete the task very differently.

Starting with PID control, what is it? PID control is a control method with a closed loop where the motor speed will be adjusted based on the error between the actual speed and target speed using proportional intergral and derivative terms. 

#### Pros
PID compensates for the load changes since it keeps on changing the whole time, which also makes the driving smooth and that we can accurately track the speed

PID works really precise to such a degree that it is industrial-grade.

#### Cons
One of the big issues with PID control is it that it is really time consuming in the regard it needs to be properly tuning and needs a lot of computing


Secondly Linear interpolation. It is a feedforward method where the motor speed reference is ramping up or down linearly over time between two setpoints given, usually from start to a giving target

#### Pros
It is very simple to implement, so wont be as time consuming as PID control.

Linear interpolation avoids mechanical shocks and tear by preventing sudden jumps in speed.

It makes the motion of the vehicle predictable 

#### Cons
Its an open-loop, which means it does not correct for load changes and resistance increaseas, which may lead to the actual speed may lag behind its target.
Using linear interpolation makes it so there is no guarantee of the precise speed giving unless the mtoro is loaded exactly like it is tuned.
Overall limited adaptability.


### Conclusion

Even though that PID control is the harder to implement option, more time consuming and requires fine tuning. For this giving project it is a better option that linear interpolation, because linear interpolation might provide with an easier implementation and ease of use, but the drawbacks with its tuning and adaptability makes it so that PID control is the better option for this project.
In conclusion we are going to use PID control for motor speed control for this project. 

