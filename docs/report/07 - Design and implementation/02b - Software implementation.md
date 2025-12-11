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

## MotorController
The turn() function is responsible for turning the car. The function takes a double, degrees, which is the amount of degrees the car has to turn. A positive value results in a counter-clockwise turn, and vice versa. As the function is called every time the car reaches a new point, and will sometimes have to keep going straight, the function will return immediately, if the value passed is 0. 

```cpp
if(degrees == 0)
    return;
```

The distance each wheel has to travel is then calculated, using the distance between the wheel, the circumference of the wheels and the value passed in the function. 

```cpp
// Calculate target encoder counts for the turn
    ((M_PI * CAR_DIAMETER) / WHEEL_CIRCUMFERENCE) * ENCODER_PR_ROTATION * (std::abs(degrees) / 360.0);
```

The current encoder positions are noted, and used to determine the target for both motors. Since the motors need to go in different direction, the sign of the target for each motor is set based on whether the value passed to the function is positive or negative, as described earlier.

```cpp
if(degrees > 0) {
        // turn right in place
        left_target = left_pos - dist_counts; // backward
        right_target = right_pos + dist_counts; // forward
    } else {
        // turn left in place
        left_target = left_pos + dist_counts; // forward
        right_target = right_pos - dist_counts; // backward
    }
```

Variables to store the error for each motor, i.e. its distance from target value are initialised, and we are now ready to enter the main loop of the function. 

In the loop, first the encoder positions are updated, as these are used in the PID regulation, which is updated immediately after.
```cpp
    // Current position
        left_pos = encoder_left_.get_position();
        right_pos = encoder_right_.get_position();

    // Update PWM
        int left_pwm = pid_left_.update(left_target, left_pos, &left_ctrl, INTEGRATION_THRESHOLD);
        int right_pwm = pid_right_.update(right_target, right_pos, &right_ctrl, INTEGRATION_THRESHOLD);
```

The errors are updated, and the PWM values from the PID regulation are passed into the drive() function to start driving. We then encounter the two conditions that will break the loop. First we'll look at 
```cpp
if(std::abs(left_error) < 20 && (std::abs(right_error)) < 20) {
            std::cout << "Left Error: " << left_error << ", Left PWM: " << left_pwm << std::endl;
            std::cout << "Right Error: " << right_error << ", Right PWM: " << right_pwm << std::endl;
            break;
        }
```
This if-statement simply checks if both engines are wihtin our margin for error, in this case 20 encoder pulses. If this condition is met, the loop will break, and the program will resume. However, the motors had a tendency of getting within a couple of pulses of the error-margin, and then not driving any further, as the duty cycle of the PWM signal is too low to make the motors turn. Therefore a second if-statement was added as a failsafe.

```cpp
if(std::abs(left_pwm) < 20 && std::abs(right_pwm) < 20) {
            ++m;
            if(m > 100) {
                std::cout << "Left Error: " << left_error << ", Left PWM: " << left_pwm << std::endl;
                std::cout << "Right Error: " << right_error << ", Right PWM: " << right_pwm << std::endl;
                break;
            }
        }
```

This loop checks if the duty cycle of the PWM signals is below 20. If this happens for 100 loops, the loop will break. This does result in the car not always being as precise as it perhaps could be, but removes any issues with the car getting stuck trying to drive a very small distance, never being able to overcome the internal resistance of the motors, which we deemed a worse outcome. 

When the loop breaks, the duty cycles for both motors are set to 0, to reduce the impact of the momentum the wheels/motors might have when exiting the loop, and then returns.

The function drive_distance(), works in very much the same way, except, of course, the wheels driving in different directions.


## PID

The PID class contains a key function called update(), which calculates a control output based on its inputs. The purpose of this function is to generate a control signal that drives the system, in this case a DC motor with encoder toward a desired target position. The function takes the following inputs: the target value the system should reach, the current measured value, a pointer to store the control output, and a threshold that determines when the integral term should be applied.

The first step in the function is to calculate the error, defined as the difference between the target value and the current value. This error represents how far the system is from the desired position and is used as the basis for all subsequent PID calculations. If the error is smaller than the integration threshold, the accumulated error variable is increased. This ensures that the integral term only contributes when the system is close enough to the target, preventing excessive accumulation.

Next, the proportional, integral, and derivative contributions are computed. The proportional term provides a corrective action directly proportional to the current error. When the motor is far from the target, this term generates a strong response to reduce the error quickly. As the motor approaches the target, the proportional term naturally decreases, preventing overshoot and unnecessary speed. The proportional value is equal to the current error.

The integral term addresses small, persistent errors that may remain due to friction, mechanical load, or system dead zones. By accumulating the error over time, the integral term ensures that the motor reaches the desired position accurately. It is calculated as the sum of the accumulated error multiplied by the time step.

The derivative term predicts the future trend of the error by measuring how quickly it is changing. If the motor is moving too rapidly toward the target, the derivative term applies a damping effect, reducing the control signal and helping to prevent overshoot or oscillations. The derivative value is computed as the difference between the current error and the previous error, divided by the time step.

After calculating the proportional, integral, and derivative contributions, each is multiplied by its respective tuning parameter. This yields a control value, which may be too large or too small for the hardware. To ensure safety and stability, the value is first squashed to stay within predefined minimum and maximum limits. Additionally, the rate of change of the control signal is limited to prevent abrupt increases or decreases. This ramp limiting helps maintain smooth acceleration and deceleration the motor.

Finally, for monitoring and debugging purposes, the function prints relevant information, including the current value, target value, control output, and error, every 50 iterations. This makes it much easier to observe since the time step is typically small.

```cpp
int Pid::update(double set_value, double current_value, double *ctrl_value, double integration_threshold)
{
    double error_ = set_value - current_value;

    if (std::fabs(error_) < integration_threshold)
        error_sum_ += error_;

    double kp_val = error_;
    double ki_val = error_sum_ * dt_;
    double kd_val = (error_ - previous_error_) / dt_;

    previous_error_ = error_;

    double ctrl = kp_ * kp_val + ki_ * ki_val + kd_ * kd_val;
 
    // squash to min/max
    double squashed_ctrl = squash(ctrl);

    // ramp limiting
    if (squashed_ctrl > last_ctrl_ + ramp_limit_)
        squashed_ctrl = last_ctrl_ + ramp_limit_;
    else if (squashed_ctrl < last_ctrl_ - ramp_limit_)
        squashed_ctrl = last_ctrl_ - ramp_limit_;

    last_ctrl_ = squashed_ctrl;

    if (ctrl_value)
        *ctrl_value = squashed_ctrl;

    n_++;
    if (n_ % 50 == 0) {
        std::cout << "curr_val: " << current_value
                  << "  set_val: " << set_value
                  << "  ctrl: " << squashed_ctrl
                  << "  error: " << error_ << std::endl;
    }

    return static_cast<int>(std::round(squashed_ctrl));
}
```

## Encoder

The encoder class uses poll() to handle a rotary encoder using event-based triggering. It monitors two GPIO pins corresponding to the A and B channels of the encoder. By detecting the order in which these pins go high and using a quadrature decoding lookup table, the code can determine whether the encoder is rotating forward or backward.

Before entering the main loop, the class sets up a structure containing the file descriptors needed by poll(), along with a lookup table that maps state transitions to position changes. All processing happens inside a loop that continues as long as the running_ flag remains true.

At the start of each loop iteration, poll() is called. This is a blocking call with an infinite timeout, meaning it will wait indefinitely until one of the monitored file descriptors becomes readable. Under normal operation, this happens whenever an edge is detected on one of the encoder’s GPIO pins. However, because the encoder may not always be moving for example, when the vehicle is stationary “wake pipe” is also included in the poll() set. Writing anything to this pipe makes it readable, causing poll() to return. If this wake-up event occurs, the loop exists.

When an event occurs on one of the GPIO pins, the function reads a gpioevent_data structure that indicates which pin triggered and whether the event was a rising or falling edge. Based on this information, the code reconstructs the new logical state of the encoder’s A and B signals. It then combines the previous state and the newly computed state into a 4-bit index. This index is used to access the quadrature decoding table, which determines whether the transition represents a step forward, a step backward, or an invalid transition. The resulting value is added to the encoder’s position counter.

Finally, the new A/B state becomes the stored last_state_, ensuring that the next detected edge will be interpreted correctly. This process repeats for every encoder event until the wake pipe is triggered or running_ is set to false, allowing the thread to shut down cleanly.

```cpp
void Encoder::monitor_events()
{
    struct gpioevent_data event_data;

    // Quadrature decoding lookup table
    const int8_t quad_table[16] = {0, -1, 1, 0,
                                   1, 0, 0, -1,
                                   -1, 0, 0, 1,
                                   0, 1, -1, 0};

    while (running_)
    {
        int ret = poll(poll_fds_, 3, -1);
        if (ret < 0)
            break;

        if (poll_fds_[2].revents & POLLIN) // wake pipe
        {
            char buf[8];
            read(wake_pipe_[0], buf, sizeof(buf));
            break;
        }

        for (int i = 0; i < 2; ++i)
        {
            if (poll_fds_[i].revents & POLLIN)
            {
                ssize_t bytes = read(poll_fds_[i].fd, &event_data, sizeof(event_data));
                if (bytes != sizeof(event_data))
                    continue;

                int a = (i == 0) ? (event_data.id == GPIOEVENT_EVENT_RISING_EDGE) : (last_state_ >> 1) & 1;
                int b = (i == 1) ? (event_data.id == GPIOEVENT_EVENT_RISING_EDGE) : last_state_ & 1;

                int current_state = (a << 1) | b;
                int index = (last_state_ << 2) | current_state;
                encoder_position_ += quad_table[index];
                last_state_ = current_state;
            }
        }
    }
}
```

\newpage
