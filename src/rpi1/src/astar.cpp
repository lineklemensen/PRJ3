// Created by johan on 07-11-2025.
#include <cfloat>
#include <queue>

#include "astar.h"
#include <vector>
/*
void HttpHandler::get_route(cpr::Response&& res){
    // We need to use an out var since thread return values are weird
    res = cpr::Get(cpr::Url{"http://172.16.15.2:8080/get_route"},
                   cpr::Header{{"Content-Type", "application/json"}});
}
*/

// A* search between two points
std::vector<Point> aStar_search(const Point src, const Point dest)
{
    std::vector<Point> route;

    // Sanity checks
    if(!Astar::is_unblocked(src)) {
        std::cout << "Source is blocked.\n";
        return route;
    }
    if(!Astar::is_unblocked(dest)) {
        std::cout << "Destination is blocked.\n";
        return route;
    }
    if(src == dest) {
        route.push_back(src);
        return route;
    }

    bool closed_list[ROWS][COLS] = {};

    // Initialization of the node details
    cell cell_details[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            cell_details[i][j] = {-1, -1, FLT_MAX, FLT_MAX, FLT_MAX};

    int i = src.x;
    int j = src.y;

    // Source node setup
    cell_details[i][j].total_cost = 0.0;
    cell_details[i][j].start_cost = 0.0;
    cell_details[i][j].cost_to_dest = 0.0;
    cell_details[i][j].parent_i = i;
    cell_details[i][j].parent_j = j;

    // A min-heap priority queue for A*
    std::priority_queue<PriorityPoint, std::vector<PriorityPoint>, std::greater<>> open_list;
    open_list.emplace(0.0, src);

    bool found_dest = false;

    // The main loop for A*
    while(!open_list.empty()) {
        Point current = open_list.top().point;
        open_list.pop();

        i = current.x;
        j = current.y;
        closed_list[i][j] = true;

        // Movement directions for the 4 ways we can move
        constexpr Point adj[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Exploring the neighbors
        for(auto d : adj) {
            Point n{current + d};

            if(!Astar::is_valid(n))
                continue;

            // Reached the destination
            if(dest == n) {
                cell_details[n.x][n.y].parent_i = i;
                cell_details[n.x][n.y].parent_j = j;
                Astar::trace_path(cell_details, n, route);
                found_dest = true;
                break;
            }

            // normal A* expansion
            if(!closed_list[n.x][n.y] && Astar::is_unblocked(n)) {
                double g_new = cell_details[i][j].start_cost + 1.0;
                double h_new = Point::distance(n, dest);
                double f_new = g_new + h_new;

                // Update the path if we found a better one
                if(cell_details[n.x][n.y].total_cost > f_new) {
                    open_list.emplace(f_new, n);
                    cell_details[n.x][n.y].total_cost = f_new;
                    cell_details[n.x][n.y].start_cost = g_new;
                    cell_details[n.x][n.y].cost_to_dest = h_new;
                    cell_details[n.x][n.y].parent_i = i;
                    cell_details[n.x][n.y].parent_j = j;
                }
            }
        }
        if(found_dest)
            break;
    }

    if(!found_dest) {
        std::cout << "No path found.\n";
        return route;
    }


    // Straight line compression
    int removedCount = 0;
    for(int it = 0; it + 2 < route.size(); it++) {
        // Goes through the entire route


        if(route[it].x == route[it + 1].x && // If the next x coordinate is the same as current one
           route[it].y != route[it + 1].y) // And if the next y is different then the current one
        {
            while(route[it].x == route[it + 1].x && // while the next x coordinate is the same as current one
                  route[it].y != route[it + 1].y) // And while the next y is different from the current one
            {
                route.erase(route.begin() + it); // Remove current position
                removedCount++; // Count up amount of remove points
            }
        } else {
            while(route[it].x != route[it + 1].x &&
                  // while the next x coordinate is the different from the current one
                  route[it].y == route[it + 1].y) // And while the next y is the same as current one
            {
                route.erase(route.begin() + it); // Remove current position
                removedCount++; // Count up amount of remove point
            }
        }
    }
    if(removedCount > 0)
        std::cout << "[Straight-line compression removed " << removedCount << " points]\n";

    return route;
}

int main()
{
    /*
        cpr::Response res;
        auto t = std::thread(HttpHandler::get_route, res);

        t.join();
        if(res.status_code != cpr::status::HTTP_OK) {
            //HOW TO KILL PROGRAM
        }
        Route r = json_dto::from_json<Route>(res.text);

      room coordinates*/
    const std::vector<Point> waypoints = Astar::rooms(r);
    const int num_points = waypoints.size();

    // Path matrix for all pairs
    std::vector<std::vector<std::vector<Point>>> paths(num_points, std::vector<std::vector<Point>>(num_points));
    std::vector<std::vector<double>> cost(num_points, std::vector<double>(num_points, 1e9));

    cell grid;
    //A* for all pairs (i,j) only once
    for(int i = 0; i < num_points; i++) {
        for(int j = i + 1; j < num_points; j++) {
            std::vector<Point> p = aStar_search(waypoints[i], waypoints[j]);
            if(p.empty())
                continue;
            double len = Astar::path_length(p);
            paths[i][j] = paths[j][i] = p;
            cost[i][j] = cost[j][i] = len;
        }
    }


    // TSP brute force, generate permutations of visiting order
    std::vector<int> perm;
    for(int i = 0; i < num_points; i++) {
        perm.push_back(i);
    }

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
        for(size_t i = 1; i < candidate_order.size(); i++) {
            if(paths[candidate_order[i - 1]][candidate_order[i]].empty()) {
                valid = false;
                break;
            }
            sum += cost[candidate_order[i - 1]][candidate_order[i]];
        }

        // Update the best solution
        if(valid && sum < best_cost) {
            best_cost = sum;
            best_order = candidate_order;
        }
    } while(std::next_permutation(perm.begin(), perm.end()));

    // Print visiting order
    std::cout << "Optimal visiting order (returning to first waypoint):\n";
    for(int idx : best_order)
        std::cout << "(" << waypoints[idx].x << "," << waypoints[idx].y << ") -> ";
    std::cout << "END\n\n";


    // Wait at start
    std::cout << "Starting at waypoint 0: (" << waypoints[0].x << "," << waypoints[0].y << ")\n";
    Astar::wait_for_button();


    // Drive through route
    for(size_t i = 1; i < best_order.size(); i++) {
        int a = best_order[i - 1];
        int b = best_order[i];
        for(Point p : paths[a][b])
            Astar::send_to_driver(p);
        std::cout << "Reached waypoint " << b << ": (" << waypoints[b].x << "," << waypoints[b].y << ")\n";
        Astar::wait_for_button();
    }
    std::cout << "Route has been completed.\n";
    return 0;
}
