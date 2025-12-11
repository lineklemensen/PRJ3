# Software implementation

## Astar
### Calculate route
Firstly we generate the points,rooms, that the car can visit, which include the starting point (0,0), \newline
const std::vector<Point> waypoints = create_rooms(r); \newline
const int num_points = waypoints.size(); \newline

here the waypoints stores all the points of interest, and num_points is the total number of points. \newline

### Compute paths
Then we need to find the shortest path between all pairs of waypoints given, so later on solve the TSP efficiently. \newline

```cpp
std::vector paths(num_points, std::vector<std::vector<Point>>(num_points));
std::vector cost(num_points, std::vector<int>(num_points, 1e9));
```

Paths stores the astar from waypoints i to j, and cost stores the length of that path, this is initialized to a large number for comparison. \newline

to calculate the paths the following is done: \newline

```cpp
for(int i = 0; i < num_points; i++) {  
    for(int j = 0; j < num_points; j++) {  
        std::vector<Point> p = aStar_search(waypoints[i], waypoints[j]); 
        if(p.empty()) continue; 
        
        const int len = p.size() - 1;  
        paths[i][j] = p; 
        cost[i][j] = len; 
    } 
} 
```

For every pair, (i,j), astar_search finds the shortest path.
If a path exists, we store it in paths and its length in cost.

\newpage
### Solve TSP brute-force
Next step is to try all the possible orders of visiting the rooms to find the total shortest total route. \newline

```cpp
std::vector<int> perm; 
for(int i = 1; i < num_points; i++) 
    perm.push_back(i); 

//We generate all permutations excluding the starting point, which is always 0. 
int best_cost = 1e9; 
std::vector<int> best_order; 
```

`best_cost` keeps track of the shortest distance found.
`best_order` keeps the corresponding visiting order.  

```cpp
//For each permutation: 
do { 
    std::vector<int> candidate_order; 
    candidate_order.push_back(0); 
    candidate_order.insert(candidate_order.end(), perm.begin(), perm.end()); 
    candidate_order.push_back(0); // return to start 


    //Then we create a candidate route that starts and ends at 0.  

    int sum = 0; 
    bool valid = true; 
    for(size_t i = 1; i < candidate_order.size(); i++) { 
        if(paths[candidate_order[i - 1]][candidate_order[i]].empty()) { 
            valid = false; 
            break; 
        } 
        sum += cost[candidate_order[i - 1]][candidate_order[i]]; 
    } 


    //We sum the costs of consecutive legs in the route given, if any has no path, we mark the route as invalid.  
    if(valid && sum < best_cost) {
        best_cost = sum;
        best_order = candidate_order;
    }
//If the route is valid and shorter than previous best, we update best_order.
} while(std::next_permutation(perm.begin(), perm.end()));
// Repeating for all permutations to find the optimal visiting order.
```

\newpage
### Combine paths  
Once we have the best order to visit, the code concatenate the individual paths into a full route:  
```cpp
std::vector<std::vector<Point>> combined_path; 

for(size_t i = 1; i < best_order.size(); i++) { 
    int a = best_order[i - 1]; 
    int b = best_order[i]; 
    combined_path.push_back(paths[a][b]); 
} 

return combined_path; 
```

Each segment paths(a)(b), is added to combined_path. The final combined_path is what the car should follow.

### Astar search  
The astar_search function finds the shortest path between two points.  
```cpp
if(!is_unblocked(src) || !is_unblocked(dest)) return route; 
if(src == dest) return {src}; 

// Exit early if the source or destination is blocked, or if they are the same. 
bool closed_list[ROWS][COLS] = {}; 
cell cell_details[ROWS][COLS]; 

// closed_list tracks visited nodes, cell details stores the costs and parent points for the paths reconstruction. 
cell_details[src.x][src.y] = { 
    .p = src, 
    .total_cost = 0.0, 
    .start_cost = 0.0, 
    .cost_to_dest = 0.0, 
}; 
```

Initialize the source node with 0 cost.  
```cpp
std::priority_queue<PriorityPoint, std::vector<PriorityPoint>, std::greater<>> open_list; 
open_list.emplace(0.0, src); 
```

open_list is a min-heap based on total cost f = g + h.  

\newpage
### Main Loop  
```cpp
while(!open_list.empty()) { 
    Point current = open_list.top().point; 
    open_list.pop(); 
    closed_list[current.x][current.y] = true; 
    

//this picks the node with the lowest cost, marking as it its visited. 
constexpr Point adj[4] = {{-1,0},{1,0},{0,-1},{0,1}}; 
for(auto d : adj) { 
    Point n{current + d}; 
    if(!Astar::is_valid(n)) continue; 
    
//Explore the 4 neighbors(up, down, left, right), skipping invalid neighbors. 
if(dest == n) { 
    cell_details[n.x][n.y].p = current; 
    Astar::trace_path(cell_details, n, route); 
    found_dest = true; 
    break; 
} 


// If one of the neighbors is the destination, trace back the path and exit. 
double g_new = cell_details[current.x][current.y].start_cost + 1.0; 
double h_new = Point::distance(n, dest); 
double f_new = g_new + h_new; 

//g_new = cost from start to neighbor. 
//h_new = heuristic(straight-line distance to destination). 
//f_new = total estimated cost. 

if(cell_details[n.x][n.y].total_cost > f_new) { 
    open_list.emplace(f_new, n); 
    cell_details[n.x][n.y] = {current, f_new, g_new, h_new}; 
} 

```

Update the neighbor if we found a better path, and push it to the queue.

### Path compression
Lastly, it removes unnecessary points along the straight lines:  
```cpp
for(int it = 0; it + 1 < route.size(); it++) {
    if(route[it].x == route[it + 1].x) { ... }
    else { ... }
}
```

a given example for this can be [(0,0),(0,1),(0,2)] → [(0,0),(0,2)].  
this reduces the number of points the car needs to follow and will make the drive smoother.

\newpage
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

\newpage
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

The PID class contains a function called update(), which calculates a control output based on its inputs. The purpose of this function is to generate a control signal that drives the system, in this case a DC motor with encoder toward a desired target position. The function takes four inputs, the target value, the current value, a pointer to store the control output, and a threshold that determines when the integral term should be applied.

The first step in the function is to calculate the error, defined as the difference between the target value and the current value. This error represents how far the system is from the desired position and is used as the basis for all other PID calculations. If the error is smaller than the integration threshold, the accumulated error variable is increased. This ensures that the integral term only contributes when the system is close enough to the target, preventing excessive accumulation.

\newpage
Next, the proportional, integral, and derivative contributions are computed. The proportional term provides a corrective action directly proportional to the current error. When the motor is far from the target, this term generates a strong response to reduce the error quickly. As the motor approaches the target, the proportional term naturally decreases, preventing overshoot and unnecessary speed. The proportional value is equal to the current error.

The integral term addresses small, persistent errors that may remain due to friction, mechanical load, or system dead zones. By accumulating the error over time, the integral term ensures that the motor reaches the desired position accurately. It is calculated as the sum of the accumulated error multiplied by the time step.

The derivative term predicts the future trend of the error by measuring how quickly it is changing. If the motor is moving too rapidly toward the target, the derivative term applies a damping effect, reducing the control signal and helping to prevent overshoot or oscillations. The derivative value is computed as the difference between the current error and the previous error, divided by the time step.

After calculating the proportional, integral, and derivative contributions, each is multiplied by its respective tuning parameter. This yields a control value, which may be too large or too small for the hardware. To ensure safety and stability, the value is first squashed to stay within predefined minimum and maximum limits. Additionally, the rate of change of the control signal is limited to prevent abrupt increases or decreases. This ramp limiting helps maintain smooth acceleration and deceleration of the motor.

Finally, for monitoring and debugging purposes, the function prints relevant information, including the current value, target value, control output, and error, every 50 iterations. This makes it much easier to observe since the time step is typically small.

\newpage
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

\newpage
## Encoder

The encoder class uses poll() to handle a rotary encoder using event-based triggering. It monitors two GPIO pins corresponding to the A and B channels of the encoder. By detecting the order in which these pins go high and using a quadrature decoding lookup table, the code can determine whether the encoder is rotating forward or backward.

Before entering the main loop, the class sets up a structure containing the file descriptors needed by poll(), along with a lookup table that maps state transitions to position changes. All processing happens inside a loop that continues as long as the running_ flag remains true.

At the start of each loop iteration, poll() is called. This is a blocking call with an infinite timeout, meaning it will wait indefinitely until one of the monitored file descriptors becomes readable. Under normal operation, this happens whenever an edge is detected on one of the encoder’s GPIO pins. However, because the encoder may not always be moving for example, when the vehicle is stationary “wake pipe” is also included in the poll() set. Writing anything to this pipe makes it readable, causing poll() to return. If this wake-up event occurs, the loop exists.

When an event occurs on one of the GPIO pins, the function reads a gpioevent_data structure that indicates which pin triggered and whether the event was a rising or falling edge. Based on this information, the code reconstructs the new logical state of the encoder’s A and B signals. It then combines the previous state and the newly computed state into a 4-bit index. This index is used to access the quadrature decoding table, which determines whether the transition represents a step forward, a step backward, or an invalid transition. The resulting value is added to the encoder’s position counter.

Finally, the new A/B state becomes the stored last_state_, ensuring that the next detected edge will be interpreted correctly. This process repeats for every encoder event until the wake pipe is triggered or running_ is set to false, allowing the thread to shut down cleanly.

\newpage
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
## TUI

The TUI was designed to be very general, which allows for adding new ui elements with ease, instead of having hardcoded functionality for every element. This is done by having a couple base classes, `Screen` and `Element` which can be inherited to allow for their own implementation.  

### Screen stack  
From a high level view the TUI uses an idea of a "screen stack" where different screens can be pushed and popped, where the top one is always the one that gets interacted with.  
This can be seen in the constructor for the `Tui` class where all it really does is construct a screen which then gets pushed to the screen stack.

```cpp
Tui::Tui()
{
    screen_stack_.push(new MainScreen());
    screen_stack_.top()->print();
}
```

The elements included in the screen are then implementation defined. It can contain any number of ui elements which the screen itself handles and keeps track of.

### UI elements  
The other base class `Element` provides some basic functionality to define what a ui element must do. The minimum required to implement is the print function which includes what the element prints to the screen.  
The most basic element is a `TextElement` which as the name implies only has text. It can't be selected and therefore doesn't have any action when pressed either.  
The other two elements that we needed to implement was a basic button, `Button`, and a button with a checkbox, `StatefulButton`. The basic button has an arbitrary action associated with it, which can be any function assigned at construction e.g. pushing or popping a screen from the stack, or modifying existing elements. 

This functionality can even expand into more complex lambda functions, such as the "Finish" button on the main screen. Which needs to decide whether to show the popup depending on if the user has selected any rooms or not.

```cpp
const auto finish_button = new Button("Finish", [=] {
    const Route r{room1, room2, room3};
    if(!r.empty())
        Tui::push_screen(new PopupScreen(r));
    else {
        static auto no_room_error = TextElement("Please select at least one room...");
        no_room_error.print();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
});
```

\newpage
### Key mapping

Each element has a map/dictionary where the key in the map corresponds to the actual input key that gets read from the user. This is used for moving the selection between elements whenever the user hits any of the up, down, left or right directional keys. Essentially the map corresponds to "given this input key, what is the corresponding ui element to move to", so when the user inputs up, the "selected" cursor should move to the element above the current.

```cpp
//From include/Elements/Element.h
class Element {
public:
    ...
    Element* get_button(Key key);
protected:
    ...
    std::map<Key, Element*> keyMap_;
}

//From src/Screens/Screen.cpp
void Screen::update_selection()
{
    switch(const auto key = Input::get_input()) {
        case ENTER: {
            if(const auto e = dynamic_cast<Button*>(selected_))
                e->action();
            break;
        }
        case UP:
        case DOWN:
        case LEFT:
        case RIGHT: {
            if(const auto b = selected_->get_button(key)) {
                selected_->print();
                std::cout << "  ";
                selected_ = b;
                selected_->print();
                std::cout << "<-";
            }
            break;
        }
        default: break;
    }
}
```

When adding elements to a screen we need to also "register" which keys correspond to what elements. For example the "Finish" and "Clear" buttons are to the left and right of eachother, so in their respective keymaps "Finish" would have an index in the map where the key is RIGHT and the value is a pointer to the "Clear" button, and vice versa. This is used for navigating between the elements using the arrow keys.  

```cpp
//In MainScreen ctor
finish_button->connect(clear_button, HORIZONTAL);
finish_button->add_keybind(UP, room3);
clear_button->add_keybind(UP, room3);
room3->add_keybind(DOWN, finish_button);
```

\newpage
Additionally since each element have their own keymap it allows for several elements to use the same key to refer to an element. This functionality is used when setting up the three elements "Room 3", "Finish" and "Clear". In this case when "Finish" or "Clear" is selected, pressing up should result in the selection arrow moving to the "Room 3" element, but pressing down after should always move to the "Finish" element, this simple "state machine" is also showcased in Figure \ref{tui:keymap}.

\begin{figure}[H]
\centering
    \begin{subfigure}{.3\textwidth}
        \centering
        \includegraphics[width=0.7\textwidth]{docs/diagrams/out/Software implementation/Tui example.png}
        \caption{Elements in the TUI}
    \end{subfigure}%
    \begin{subfigure}{.3\textwidth}
        \centering
        \includegraphics[width=0.7\textwidth]{docs/diagrams/out/Software implementation/Keymap example.png}
        \caption{Representation of the elements' keymaps}
        \label{tui:keymap}
    \end{subfigure}
\caption{Tui element traversal example}
\end{figure}


\newpage
## Server
The server was made to handle requests from TUI and Car, if any errors should occur while handling a request the server is to respond with a status code. additionally its responsible for storing all routes that are send to it through POST requests, this is done with a queue that holds each route from POST. When only using a queue one considerable problem would happen if the server shuts down and that is the queue being empty upon server start. The solution created for this was making a log file storing all the routes that the queue also had. With this if the server starts and there was still routes left when it shut down, the log file will put all routes its containing into the queue. 
  
### RouteHandler
This handles the server setup using restinio, its purpose is to host the server and handle any request that is received.

### GET handler
This handler is used when a GET request in done to the server, if the queue is empty it returns a status code for "no content", else it calls get_route from LogHandler
and sets the response body of the request to the returned value.
```cpp
	auto on_get_route(const restinio::request_handle_t& req, rr::route_params_t) const
	{
		auto resp = init_resp(req->create_response());

		if (route_logger.queue_empty()) {
			resp.header().status_line(restinio::status_no_content());
			return resp.done();
		}

		std::string result = route_logger.get_route();

		resp.set_body(result);


		return resp.done();
	}
```

### POST handler
This handler is used when the server receives a POST request, if the request body is empty return status code "no content". Else it simply calls the function post_route() from LogHandler.

```cpp
	auto on_post_route(const restinio::request_handle_t& req, rr::route_params_t) const
	{
		auto resp = init_resp(req->create_response());


		if (req->body().empty()) {
			resp.header().status_line(restinio::status_no_content());
			return resp.done();
		}

		route_logger.post_route(req->body());


		return resp.done();

	}
```

  
### LogHandler
To implement the class LogHandler a queue is made with the library deque, and has basic function for queues. 


log_file.open is used to open a file with the given name being logger.txt, ios::app is used here to make sure that if a file does not exist with that name it will then create one. An error is thrown if the condition !logfile.is_open() is met, since that would indicate that something went wrong when opening/creating the log file. After opening the log file std::ifstream is used to operate on the log file, the while loop takes the first line inside log_file and push_back that line into the queue.

```cpp
    private:
    std::ofstream log_file;
    std::deque<std::string> route_queue;
    std::string file_path;

    public:
    LogHandler(const std::string& file_path = "logger.txt") : file_path(file_path) {
        log_file.open(file_path, std::ios::app);
        if (!log_file.is_open()) {
            throw std::runtime_error("failed to opn file");
        }

        if (log_file.is_open()) {
            std::ifstream log_file_stream(file_path);
            std::string line;
            while (std::getline(log_file_stream, line)) {
                route_queue.push_back(line);
            }
        }
    };
```


### POST
The data received from POST request is done with a function called post_route. The function is a void because it should not return anything, what it does is calling route_queue to push back the string received, then if the log_file is open route_queue.back is used to also add the string from the request into log_file with log_file.flush. 
```cpp
    void post_route(const std::string& log_rooms) {
        route_queue.push_back(log_rooms);
        if (log_file.is_open()) {
            log_file << route_queue.back() << "\n";
            log_file.flush();
        }
    };
```


## GET
This function is used for taking the first element in route_queue and put it into a string first_route so that pop_front can be done on the queue, it then calls update_route() to update the log_file centent and finally return first_route

```cpp
    std::string get_route() {

        if (route_queue.empty()) {
            throw std::runtime_error("no route queue given");
        }

        std::string first_route = route_queue.front();
        route_queue.pop_front();
        update_route();
        return first_route;
    }
```


## update 
Update_route() is simply to take every element in route_queue and put it into log_file.
```cpp
    void update_route() {
        std::ofstream out(file_path);
        for (auto route_item : route_queue) {
            out << route_item << "\n";
        }
    }

    bool queue_empty() const {
        return route_queue.empty();
    }
};
```


