// Created by johan on 07-11-2025.
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>
#include <cfloat>
#include <json_dto/pub.hpp>
#include <cpr/cpr.h>

#define ROWS 25
#define COLS 25

typedef std::pair<int, int> Point; // Grid coordinates (row, column)
typedef std::pair<double, std::pair<int, int>> PriorityPoint; // the f-cost + coordinate

struct Route
{
    //Determines which rooms to visit {1,0,1} == "visit room 1 and room 3
    int rooms[3] = {0, 0, 0};

    template<typename JSON_IO>
    void json_io(JSON_IO& io)
    {
        io & json_dto::mandatory("rooms", m_);
    }
}

void HttpHandler::get_route(cpr::Response& res){
    // We need to use an out var since thread return values are weird
    res = cpr::Get(cpr::Url{"http://172.16.15.2:8080/get_route"},
                   cpr::Header{{"Content-Type", "application/json"}});
}

cpr::Response res;
auto t = std::thread(HttpHandler::send_route, res);

t.join();
if(res.status_code != cpr::status::HTTP_OK) {
suicide();
exit(-1);
}

Route r = json_dto::from_json(res.body);
/*
  Do stuff with route info
*/


// The representation A* node
struct cell {
    int parent_i, parent_j; // parent position
    double total_cost; // f = g +h
    double start_cost; // g cost
    double cost_to_dest; // h cost
};

// Checks if the coordinates are inside the given grid
bool is_valid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Checks if the cell given is traversable, (1 = open, 0 = blocked)
bool is_unblocked(int grid[][COLS], int row, int col) {
    return grid[row][col] == 1;
}

//Checks if the destination has been reached
bool is_destination(int row, int col, Point dest) {
    return row == dest.first && col == dest.second;
}

// The heuristic: Euclidean distance
double calculate_h_value(int row, int col, Point dest) {
    return sqrt((row - dest.first) * (row - dest.first) +
                (col - dest.second) * (col - dest.second));
}


// Reconstruct the path by following the parent pointers
void trace_path(cell cell_details[][COLS], Point reached, std::vector<Point> &route) {
    int row = reached.first;
    int col = reached.second;

    std::stack<Point> Path;


    //Follows the parents backwards until the source has been reached
    while (!(cell_details[row][col].parent_i == row && cell_details[row][col].parent_j == col)) {
        Path.push({row, col});
        int t_row = cell_details[row][col].parent_i;
        int t_col = cell_details[row][col].parent_j;
        row = t_row;
        col = t_col;
    }
    Path.push({row, col}); // push the start node


    //Reverse the stack into a vector
    while (!Path.empty()) {
        route.push_back(Path.top());
        Path.pop();
    }
}


// A* search between two points
std::vector<Point> aStar_search(int grid[][COLS], Point src, Point dest) {
    std::vector<Point> route;

    // Sanity checks
    if (!is_unblocked(grid, src.first, src.second)) {
        std::cout << "Source is blocked.\n";
        return route;
    }
    if (!is_unblocked(grid, dest.first, dest.second)) {
        std::cout << "Destination is blocked.\n";
        return route;
    }
    if (is_destination(src.first, src.second, dest)) {
        route.push_back(src);
        return route;
    }

    bool closed_list[ROWS][COLS];
    memset(closed_list, false, sizeof(closed_list));

    // Initialization of the node details
    cell cell_details[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            cell_details[i][j] = {-1, -1, FLT_MAX, FLT_MAX, FLT_MAX};

    int i = src.first;
    int j = src.second;

    //Source node setup
    cell_details[i][j].total_cost = 0.0;
    cell_details[i][j].start_cost = 0.0;
    cell_details[i][j].cost_to_dest = 0.0;
    cell_details[i][j].parent_i = i;
    cell_details[i][j].parent_j = j;

    // A min-heap priority queue for A*
    std::priority_queue<PriorityPoint, std::vector<PriorityPoint>, std::greater<PriorityPoint>> open_list;
    open_list.push({0.0, {i, j}});

    bool found_dest = false;

    // Movement directions for the 4 ways we can move
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    //The main loop for A*
    while (!open_list.empty()) {
        PriorityPoint current = open_list.top();
        open_list.pop();

        i = current.second.first;
        j = current.second.second;
        closed_list[i][j] = true;

        //Exploring the neighbors
        for (int d = 0; d < 4; d++) {
            int nr = i + dr[d];
            int nc = j + dc[d];

            if (!is_valid(nr, nc))
                continue;

            //Reached the destination
            if (is_destination(nr, nc, dest)) {
                cell_details[nr][nc].parent_i = i;
                cell_details[nr][nc].parent_j = j;
                trace_path(cell_details, {nr, nc}, route);
                found_dest = true;
                break;
            }

            //normal A* expansion
            if (!closed_list[nr][nc] && is_unblocked(grid, nr, nc)) {
                double g_new = cell_details[i][j].start_cost + 1.0;
                double h_new = calculate_h_value(nr, nc, dest);
                double f_new = g_new + h_new;

                // Update the path if we found a better one
                if (cell_details[nr][nc].total_cost > f_new) {
                    open_list.push({f_new, {nr, nc}});
                    cell_details[nr][nc].total_cost = f_new;
                    cell_details[nr][nc].start_cost = g_new;
                    cell_details[nr][nc].cost_to_dest = h_new;
                    cell_details[nr][nc].parent_i = i;
                    cell_details[nr][nc].parent_j = j;
                }
            }
        }
        if (found_dest)
            break;
    }

    if (!found_dest) {
        std::cout << "No path found.\n";
        return route;
    }


    // Straight line compression
    int removedCount = 0;
    for (unsigned int it = 0; it + 1 < route.size();it++ ) {//Goes through the entire route

        if (route[it].first == route[it + 1].first && //If the next x coordinate is the same as current one
            route[it].second != route[it + 1].second)// And if the next y is different then the current one
        {
            while (route[it].first == route[it + 1].first &&//while the next x coordinate is the same as current one
                   route[it].second != route[it + 1].second)// And while the next y is different then the current one
            {
                route.erase(route.begin() + it);//Remove current position
                removedCount++;//Count up amount of remove points
            }
        }
        else {
            while (route[it].first != route[it + 1].first && //while the next x coordinate is the different then the current one
                   route[it].second == route[it + 1].second)//And while the next y is the same as current one
            {
                route.erase(route.begin() + it);//Remove current position
                removedCount++;//Count up amount of remove point
            }
        }
    }
    if (removedCount > 0)
        std::cout << "[Straight-line compression removed " << removedCount << " points]\n";

    return route;
}

// Sends a coordinate to the car
void send_to_driver(Point p) {
    std::cout << "Driving to: " << p.first << "," << p.second << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

//Pause execution Enter is pressed(becomes button later on)
void wait_for_button() {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

//Path length = number of moves
double path_length(std::vector<Point> path) {
    return static_cast<double>(path.size() - 1);
}

int main() {
    //The hard-coded grid
    //1 = open, 0 = wall
    int grid[ROWS][COLS]= {
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };
    int num_points;
    std::cout << "Enter number of waypoints: ";
    std::cin >> num_points;

    //Read waypoint coordinates
    std::vector<Point> waypoints(num_points);
    for(int x = 0; x < num_points; x++) {
        std::cout << "Enter point " << x+1 << " (row col): ";
        std::cin >> waypoints[x].first >> waypoints[x].second;
    }

    // Remove last point if it duplicates the first
    if(num_points > 1 && waypoints[num_points-1] == waypoints[0]){
        waypoints.pop_back();
        num_points--;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n";

    // Path matrix for all pairs
    std::vector<std::vector<std::vector<Point>>> paths(num_points, std::vector<std::vector<Point>>(num_points));
    std::vector<std::vector<double>> cost(num_points, std::vector<double>(num_points, 1e9));

    //A* for all pairs (i,j) only once
    for(int i=0;i<num_points;i++){
        for(int j=i+1;j<num_points;j++){
            std::vector<Point> p = aStar_search(grid, waypoints[i], waypoints[j]);
            if(p.empty()) continue;
            double len = path_length(p);
            paths[i][j] = paths[j][i] = p;
            cost[i][j] = cost[j][i] = len;
        }
    }

    // TSP brute force, generate permutations of visiting order
    std::vector<int> perm;
    for(int i=1;i<num_points;i++) perm.push_back(i);

    double best_cost = 1e9;
    std::vector<int> best_order;

    // Adds up the costs for each consecutive leg
    do {
        std::vector<int> candidate_order;
        candidate_order.push_back(0);
        candidate_order.insert(candidate_order.end(), perm.begin(), perm.end());
        candidate_order.push_back(0); // always return to start

        double sum = 0;
        bool valid = true;
        for(size_t i=1;i<candidate_order.size();i++){
            if(paths[candidate_order[i-1]][candidate_order[i]].empty()){
                valid=false;
                break;
            }
            sum += cost[candidate_order[i-1]][candidate_order[i]];
        }

        // Update the best solution
        if(valid && sum < best_cost){
            best_cost = sum;
            best_order = candidate_order;
        }
    } while(std::next_permutation(perm.begin(), perm.end()));

    // Print visiting order
    std::cout << "Optimal visiting order (returning to first waypoint):\n";
    for(int idx : best_order)
        std::cout << "(" << waypoints[idx].first << "," << waypoints[idx].second << ") -> ";
    std::cout << "END\n\n";


    // Wait at start
    std::cout << "Starting at waypoint 0: (" << waypoints[0].first << "," << waypoints[0].second << ")\n";
    wait_for_button();


    // Drive through route
    for(size_t i=1;i<best_order.size();i++){
        int a = best_order[i-1];
        int b = best_order[i];
        for(Point p : paths[a][b])
            send_to_driver(p);
        std::cout << "Reached waypoint " << b << ": (" << waypoints[b].first << "," << waypoints[b].second << ")\n";
        wait_for_button();
    }

    std::cout << "Route has been completed.\n";
    return 0;
}
