## Teknisk analyse


### Pathfinding algorithm

|||

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
position. These are dead reckoning, line following and GPS.
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
