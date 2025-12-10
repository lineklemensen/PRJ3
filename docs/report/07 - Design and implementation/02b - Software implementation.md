# Software implementation

## Astar
### Calculate route
Firstly we generate the points,rooms, that the car can visit, which include the starting point (0,0), \newline
const std::vector<Point> waypoints = create_rooms(r); \newline
const int num_points = waypoints.size(); \newline

here the waypoints stores all the points of interest, and num_points is the total number of points. \newline

### Compute paths
Then we need to find the shortest path between all pairs of waypoints given, so later on solve the TSP efficiently. \newline
std::vector paths(num_points, std::vector<std::vector<Point>>(num_points)); \newline
std::vector cost(num_points, std::vector<int>(num_points, 1e9)); \newline

Paths stores the astar from waypoints i to j, and cost stores the length of that path, this is initialized to a large number for comparison. \newline

to calculate the paths the following is done: \newline

for(int i = 0; i < num_points; i++) {  \newline
    for(int j = 0; j < num_points; j++) {  \newline
        std::vector<Point> p = aStar_search(waypoints[i], waypoints[j]); \newline
        if(p.empty()) continue; \newline
        \newline
        const int len = p.size() - 1;  \newline
        paths[i][j] = p; \newline
        cost[i][j] = len; \newline
    } \newline
} \newline

For every pair, (i,j), astar_search finds the shortest path.
If a path exists, we store it in paths and its length in cost.


### Solve TSP brute-force
Next step is to try all the possible orders of visiting the rooms to find the total shortest total route. \newline
std::vector<int> perm; \newline
for(int i = 1; i < num_points; i++) perm.push_back(i); \newline
\newline
We generate all permutations excluding the starting point, which is always 0. \newline
int best_cost = 1e9; \newline
std::vector<int> best_order; \newline
\newline
best_cost keeps track of the shortest distance found.
best_order keeps the corresponding visiting order.\newline

For each permutation: \newline
do { \newline
    std::vector<int> candidate_order; \newline
    candidate_order.push_back(0); \newline
    candidate_order.insert(candidate_order.end(), perm.begin(), perm.end()); \newline
    candidate_order.push_back(0); // return to start \newline
    \newline

Then we create a candidate route that starts and ends at 0. \newline

int sum = 0; \newline
bool valid = true; \newline
for(size_t i = 1; i < candidate_order.size(); i++) { \newline
    if(paths[candidate_order[i - 1]][candidate_order[i]].empty()) { \newline
        valid = false; \newline
        break; \newline
    } \newline
    sum += cost[candidate_order[i - 1]][candidate_order[i]]; \newline
} \newline
\newline

We sum the costs of consecutive legs in the route given, if any has no path, we mark the route as invalid. \newline
if(valid && sum < best_cost) { \newline
    best_cost = sum; \newline
    best_order = candidate_order; \newline
} \newline
\newline
If the route is valid and shorter than previous best, we update best_order. \newline
} while(std::next_permutation(perm.begin(), perm.end())); \newline
Repeating for all permutations to find the optimal visiting order. \newline
\newline

### Combine paths
Once we have the best order to visit, the code concatenate the individual paths into a full route: \newline
std::vector<std::vector<Point>> combined_path; \newline
\newline
for(size_t i = 1; i < best_order.size(); i++) { \newline
    int a = best_order[i - 1]; \newline
    int b = best_order[i]; \newline
    combined_path.push_back(paths[a][b]); \newline
} \newline
\newline
return combined_path; \newline
\newline
Each segment paths(a)(b), is added to combined_path. The final combined_path is what the car should follow. \newline

### Astar search
The astar_search function finds the shortest path between two points. \newline
if(!is_unblocked(src) || !is_unblocked(dest)) return route; \newline
if(src == dest) return {src}; \newline
\newline
Exit early if the source or destination is blocked, or if they are the same. \newline
bool closed_list[ROWS][COLS] = {}; \newline
cell cell_details[ROWS][COLS]; \newline
\newline
closed_list tracks visited nodes, cell details stores the costs and parent points for the paths reconstruction. \newline
cell_details[src.x][src.y] = { \newline
    .p = src, \newline
    .total_cost = 0.0, \newline
    .start_cost = 0.0, \newline
    .cost_to_dest = 0.0, \newline
}; \newline
\newline
Initialize the source node with 0 cost. \newline
std::priority_queue<PriorityPoint, std::vector<PriorityPoint>, std::greater<>> open_list; \newline
open_list.emplace(0.0, src); \newline
\newline
open_list is a min-heap based on total cost f = g + h. \newline

### Main Loop
while(!open_list.empty()) { \newline
    Point current = open_list.top().point; \newline
    open_list.pop(); \newline
    closed_list[current.x][current.y] = true; \newline
    \newline

this picks the node with the lowest cost, marking as it its visited. \newline
constexpr Point adj[4] = {{-1,0},{1,0},{0,-1},{0,1}}; \newline
for(auto d : adj) { \newline
    Point n{current + d}; \newline
    if(!Astar::is_valid(n)) continue; \newline
    \newline
Explore the 4 neighbors(up, down, left, right), skipping invalid neighbors. \newline
if(dest == n) { \newline
    cell_details[n.x][n.y].p = current; \newline
    Astar::trace_path(cell_details, n, route); \newline
    found_dest = true; \newline
    break; \newline
} \newline
\newline
If one of the neighbors is the destination, trace back the path and exit. \newline
double g_new = cell_details[current.x][current.y].start_cost + 1.0; \newline
double h_new = Point::distance(n, dest); \newline
double f_new = g_new + h_new; \newline
\newline
g_new = cost from start to neighbor. h_new = heuristic(straight-line distance to destination). f_new = total estimated cost. \newline

if(cell_details[n.x][n.y].total_cost > f_new) { \newline
    open_list.emplace(f_new, n); \newline
    cell_details[n.x][n.y] = {current, f_new, g_new, h_new}; \newline
} \newline
\newline
Update the neighbor if we found a better path, and push it to the queue.

### Path compression
Lastly, it removes unnecessary points along the straight lines: \newline
for(int it = 0; it + 1 < route.size(); it++) { \newline
    if(route[it].x == route[it + 1].x) { ... } \newline
    else { ... } \newline
} \newline
\newline

a given example for this can be [(0,0),(0,1),(0,2)] → [(0,0),(0,2)]. \newline
this reduces the number of points the car needs to follow and will make the drive smoother.








## calc_route()
To begin with I keep track of where the car currently is, where the next point is, and where the car last were. Then I can get the three sides for a triangle using the code below, for each side. 
```cpp
std::pair<double, double> last_pos_vector = {
        current_pos.first - last_pos.first, current_pos.second - last_pos.second
};
```

I'm doing this so that I'm able to use pythagoras theorem to calculate each side of the triangle. Doing this I can find the angle bewteen the last point and the current, and the current and the next point. I can then take the angle, and check if the car would go against the unit circle in relation to which way the car is facing.  
```cpp
if(current_pos.first < next_pos.first &&  
last_pos.first < next_pos.first && last_pos.second < next_pos.second) {
        cos_angle = cos_angle * -1;
} 
```
The code above, is then used three more times to handle the three other directions. It then returns an angle and length, that can be used as parameters for another function that makes driving instructions.