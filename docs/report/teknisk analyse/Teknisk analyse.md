## Teknisk analyse
We decided to rate with a score from 1 to 5, where a higher score is better. 

\newpage
### Pathfinding algorithm

|                       | Dijkstra | A*  | A* /w multithreading |
| --------------------- | -------- | --- | -------------------- |
| Speed                 | 1        | 3   | 5                    |
| Processing complexity | 5        | 4   | 3                    |
| Memory impact         | 5        | 4   | 3                    |
| Developer cost        | 3        | 2   | 1                    |
: Analysis of pathfinding algorithms

We have found 3 pathfinding algorithms to compare, Dijkstra's algorithm, A* algorithm, and A* using multithreading to improve convergence speed. 

#Small intro on options#

The attributes we want to prioritise are speed and processing complexity, as our goal is to be able to find a path quickly but don't want to consume all the resources of the RPi. So a balance between the two are important. 
Developer cost is also an important factor as we want to be able to actually get a finished and working pathfinding implementation, since if developer cost is too high we might not be able to finish it in time.

##### Speed


##### Processing complexity


##### Memory impact


##### Developer cost


