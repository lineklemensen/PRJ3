#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>
#include <cfloat>
/*
#include <json_dto/pub.hpp>
#include <cpr/cpr.h>
*/
#define ROWS 25
#define COLS 25
// The representation A* node
struct Route {
    bool room1 = true;
    bool room2 = true;
    bool room3 = true;
    /*
        template<typename JSON_IO>
        void json_io(JSON_IO& io)
        {
            io
            & json_dto::mandatory("room1", room1)
            & json_dto::mandatory("room2", room2)
            & json_dto::mandatory("room3", room3);
        }
    */
};

struct cell {
    int parent_i, parent_j; // parent position
    double total_cost; // f = g +h
    double start_cost; // g cost
    double cost_to_dest; // h cost
    //The hard-coded grid
    //1 = open, 0 = wall
    int grid [ROWS][COLS]= {
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
};

class Astar{
public:
    typedef std::pair<int, int> Point; // Grid coordinates (row, column)
    typedef std::pair<double, std::pair<int, int>> PriorityPoint; // the f-cost + coordinate

    static std::vector<Point> rooms(){
        std::vector<Astar::Point> waypoints;
        int num_points = 1;
        waypoints.push_back(std::make_pair(0,0));
        struct Route room;
        if(room.room1 == true){
            waypoints.push_back(std::make_pair(0,12));
            num_points ++;
        }
        if(room.room2 == true){
            waypoints.push_back(std::make_pair(24,12));
            num_points ++;
        }
        if(room.room3 == true){
            waypoints.push_back(std::make_pair(24,24));
            num_points ++;
        }
        // Remove last point if it duplicates the first
        if(num_points > 1 && waypoints[num_points-1] == waypoints[0]){
            waypoints.pop_back();
        }
        return waypoints;
    };

// Checks if the coordinates are inside the given grid
    static bool is_valid(int row, int col) {
        return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
    }

// Checks if the cell given is traversable, (1 = open, 0 = blocked)
    static bool is_unblocked(int grid[][COLS], int row, int col) {
        return grid[row][col] == 1;
    }

//Checks if the destination has been reached
    static bool is_destination(int row, int col, Point dest) {
        return row == dest.first && col == dest.second;
    }

// The heuristic: Euclidean distance
    static double calculate_h_value(int row, int col, Point dest) {
        return sqrt((row - dest.first) * (row - dest.first) +
                    (col - dest.second) * (col - dest.second));
    }

// Reconstruct the path by following the parent pointers
    static void trace_path(cell cell_details[][COLS], Point reached, std::vector<Point> &route) {
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

// Sends a coordinate to the car
    static void send_to_driver(Point p) {
        std::cout << "Driving to: " << p.first << "," << p.second << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

//Pause execution Enter is pressed(becomes button later on)
    static void wait_for_button() {
        std::cout << "Press Enter to continue..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

//Path length = number of moves
    static double path_length(std::vector<Point> path) {
        return static_cast<double>(path.size() - 1);
    }


private:

};