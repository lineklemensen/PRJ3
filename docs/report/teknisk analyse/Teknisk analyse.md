## Technical analysis
We decided to rate with a score from 1 to 5, where a higher score is better.

\newpage
### Pathfinding algorithm

|                       | Dijkstra | A*  | A* /w multithreading |
| --------------------- | -------- | --- | -------------------- |
| Speed                 | 1        | 3   | 5                    |
| Processing complexity | 4        | 3   | 1                    |
| Memory impact         | 1        | 2   | 2                    |
| Developer cost        | 1        | 2   | 4                    |
: Analysis of pathfinding algorithms

We have found 3 pathfinding algorithms to compare, Dijkstra's algorithm, A* algorithm, and A* using multithreading to improve convergence speed. Overall the algorithms are pretty similar in the sense that they each provide improvement on their predecessor, however at the cost of being more complex in both implementation and execution. Dijkstra's algorithm is the simplest conceptually as it simply naively traverses every possible path until it finds its goal. A* improves on this by adding a heuristic element that helps push/weight it towards its goal so it is less encouraged to search wasted routes, however the value of this heuristic function hinges on its quality, as a bad one can hurt the algorithm over the naive approach of Dijkstra. The last option is to use A* with multithreading to speed up convergence rate, however this would also add extra overhead to developer time, as with anything multithreading, it can be hard to debug issues.

The attributes we want to prioritize are speed and processing complexity, as our goal is to be able to find a path quickly but do not want to consume all the resources of the RPi. So a balance between the two are important.
Developer cost is also an important factor as we want to be able to actually get a finished and working pathfinding implementation, since if developer cost is too high we might not be able to finish it in time.

##### Speed
When we are talking about speed we are mostly concerned with convergence speed, and in that aspect there is a clear winner amongst our choices, A* with multithreading.

##### Processing complexity
Although A* with multithreading is the fastest, it is also the most complex to implement, as we need to be careful that a thread does not attempt to search the same space another thread has already cleared. Here Dijkstra and normal A* have the advantage as everything occurs on the same thread, and each new node is only traversed once.

##### Memory impact
The amount of memory each algorithm consumes is largely negligible but does scale primarily with graph/map size, when considering this, Dijkstra is the worst of the three since worst case the amount of nodes it has to check scales quadratically with the distance to the goal. Of course multithreaded A* versus its single-threaded counterpart does add some memory overhead, however it isn't enough to cost any points.

##### Developer cost
Since the algorithms are related it means that we would be able to implement them from the simplest to most complex without needing to incur the full developer cost. As a result of this we have the capability to decide if we have time to attempt the better/faster iterations depending on the amount of ongoing work.

With all of the listed points in mind, our primary goal is to at least get a fully working A* algorithm implemented, with multithreading as a bonus if time is available.