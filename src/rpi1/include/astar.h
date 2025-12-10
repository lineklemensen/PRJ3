#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <thread>
#include <chrono>
#include "Grid.h"
#include "Point.h"
#include "Route.h"

#define ROWS 7
#define COLS 11


struct cell {
    Point p;
    double total_cost; // f = g +h
    double start_cost; // g cost
    double cost_to_dest; // h cost
};

class Astar {
public:
    static std::vector<std::vector<Point>> calculate_path(const Route r);
private:
    // A* search between two points
    static std::vector<Point> aStar_search(const Point src, const Point dest);
    static std::vector<Point> create_rooms(const Route& r);

    // Checks if the coordinates are inside the given grid
    static bool is_valid(const Point& p)
    {
        return (p.x >= 0) && (p.x < ROWS) && (p.y >= 0) && (p.y < COLS);
    }

    // Checks if the cell given is traversable, (1 = open, 0 = blocked)
    static bool is_unblocked(const Point& p)
    {
        return grid[p.x][p.y] == 1;
    }

    // Reconstruct the path by following the parent pointers
    static void trace_path(cell cell_details[][COLS], const Point& reached, std::vector<Point>& route)
    {
        Point p = reached;
        std::stack<Point> Path;

        //Follows the parents backwards until the source has been reached
        while(cell_details[p.x][p.y].p != p) {
            Path.push(p);
            p = cell_details[p.x][p.y].p;
        }
        Path.push(p); // push the start node

        //Reverse the stack into a vector
        while(!Path.empty()) {
            route.push_back(Path.top());
            Path.pop();
        }
    }

    // Sends a coordinate to the car
    static void send_to_driver(const Point& p)
    {
        std::cout << "Driving to: " << p.x << "," << p.y << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    //Pause execution Enter is pressed(becomes button later on)
    static void wait_for_button()
    {
        //std::cout << "Press Enter to continue..." << std::endl;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //std::cin.get();
    }
};
