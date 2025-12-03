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
std::vector<Astar::Point> aStar_search(int grid[][COLS], Astar::Point src, Astar::Point dest)
{
    std::vector<Astar::Point> route;

    // Sanity checks
    if(!Astar::is_unblocked(grid, src.first, src.second)) {
        std::cout << "Source is blocked.\n";
        return route;
    }
    if(!Astar::is_unblocked(grid, dest.first, dest.second)) {
        std::cout << "Destination is blocked.\n";
        return route;
    }
    if(Astar::is_destination(src.first, src.second, dest)) {
        route.push_back(src);
        return route;
    }

    bool closed_list[ROWS][COLS] = {};

    // Initialization of the node details
    cell cell_details[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            cell_details[i][j] = {-1, -1, FLT_MAX, FLT_MAX, FLT_MAX};

    int i = src.first;
    int j = src.second;

    // Source node setup
    cell_details[i][j].total_cost = 0.0;
    cell_details[i][j].start_cost = 0.0;
    cell_details[i][j].cost_to_dest = 0.0;
    cell_details[i][j].parent_i = i;
    cell_details[i][j].parent_j = j;

    // A min-heap priority queue for A*
    std::priority_queue<Astar::PriorityPoint, std::vector<Astar::PriorityPoint>, std::greater<Astar::PriorityPoint>>
            open_list;
    open_list.push({0.0, {i, j}});

    bool found_dest = false;

    // Movement directions for the 4 ways we can move
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // The main loop for A*
    while(!open_list.empty()) {
        Astar::PriorityPoint current = open_list.top();
        open_list.pop();

        i = current.second.first;
        j = current.second.second;
        closed_list[i][j] = true;

        //Exploring the neighbors
        for(int d = 0; d < 4; d++) {
            int nr = i + dr[d];
            int nc = j + dc[d];

            if(!Astar::is_valid(nr, nc))
                continue;

            //Reached the destination
            if(Astar::is_destination(nr, nc, dest)) {
                cell_details[nr][nc].parent_i = i;
                cell_details[nr][nc].parent_j = j;
                Astar::trace_path(cell_details, {nr, nc}, route);
                found_dest = true;
                break;
            }

            //normal A* expansion
            if(!closed_list[nr][nc] && Astar::is_unblocked(grid, nr, nc)) {
                double g_new = cell_details[i][j].start_cost + 1.0;
                double h_new = Astar::calculate_h_value(nr, nc, dest);
                double f_new = g_new + h_new;

                // Update the path if we found a better one
                if(cell_details[nr][nc].total_cost > f_new) {
                    open_list.push({f_new, {nr, nc}});
                    cell_details[nr][nc].total_cost = f_new;
                    cell_details[nr][nc].start_cost = g_new;
                    cell_details[nr][nc].cost_to_dest = h_new;
                    cell_details[nr][nc].parent_i = i;
                    cell_details[nr][nc].parent_j = j;
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
    for(unsigned int it = 0; it + 1 < route.size(); it++) {
        //Goes through the entire route

        if(route[it].first == route[it + 1].first && //If the next x coordinate is the same as current one
           route[it].second != route[it + 1].second) // And if the next y is different then the current one
        {
            while(route[it].first == route[it + 1].first && //while the next x coordinate is the same as current one
                  route[it].second != route[it + 1].second) // And while the next y is different from the current one
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
    std::vector<Astar::Point> waypoints = Astar::rooms();
    int num_points = waypoints.size();

    // Path matrix for all pairs
    std::vector<std::vector<std::vector<Astar::Point>>> paths(
        num_points, std::vector<std::vector<Astar::Point>>(num_points));
    std::vector<std::vector<double>> cost(num_points, std::vector<double>(num_points, 1e9));

    cell grid;
    //A* for all pairs (i,j) only once
    for(int i = 0; i < num_points; i++) {
        for(int j = i + 1; j < num_points; j++) {
            std::vector<Astar::Point> p = aStar_search(grid.grid, waypoints[i], waypoints[j]);
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
        std::cout << "(" << waypoints[idx].first << "," << waypoints[idx].second << ") -> ";
    std::cout << "END\n\n";


    // Wait at start
    std::cout << "Starting at waypoint 0: (" << waypoints[0].first << "," << waypoints[0].second << ")\n";
    Astar::wait_for_button();


    // Drive through route
    for(size_t i = 1; i < best_order.size(); i++) {
        int a = best_order[i - 1];
        int b = best_order[i];
        for(Astar::Point p : paths[a][b])
            Astar::send_to_driver(p);
        std::cout << "Reached waypoint " << b << ": (" << waypoints[b].first << "," << waypoints[b].second << ")\n";
        Astar::wait_for_button();
    }
    std::cout << "Route has been completed.\n";
    return 0;
}
