#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <thread>
#include <chrono>
#include <wiringPi.h>
#include <json_dto/pub.hpp>
#include <cpr/cpr.h>
#include "Grid.h"

#define ROWS 7
#define COLS 13

// The representation A* node
struct Route {
    bool room1;
    bool room2;
    bool room3;


    template<typename JSON_IO>
    void json_io(JSON_IO& io)
    {
        io
                & json_dto::mandatory("room1", room1)
                & json_dto::mandatory("room2", room2)
                & json_dto::mandatory("room3", room3);
    }
};

struct Point {
    // Grid coordinates (row, column)
    int x, y;

    bool operator==(const Point& p) const
    {
        return x == p.x && y == p.y;
    }

    Point operator+(const Point& p) const
    {
        return {x + p.x, y + p.y};
    }

    bool operator>(const Point& p) const
    {
        return x > p.x;
    }
    static double distance(const Point& p1, const Point& p2)
    {
        return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                    (p1.y - p2.y) * (p1.y - p2.y));
    }
};

struct PriorityPoint {
    double pri;
    Point point;

    bool operator>(const PriorityPoint& p) const
    {
        return p.pri > pri;
    }
};

struct cell {
    Point p;
    double total_cost; // f = g +h
    double start_cost; // g cost
    double cost_to_dest; // h cost
};

class Astar {
public:
    static std::vector<Point> rooms(const Route& r)
    {
        std::vector<Point> waypoints;
        waypoints.emplace_back(0, 0);

        if(r.room1)
            waypoints.emplace_back(2, 4);
        if(r.room2)
            waypoints.emplace_back(6, 11);
        if(r.room3)
            waypoints.emplace_back(6, 9);

        return waypoints;
    };

    // Checks if the coordinates are inside the given grid
    static bool is_valid(Point p)
    {
        return (p.x >= 0) && (p.x < ROWS) && (p.y >= 0) && (p.y < COLS);
    }

    // Checks if the cell given is traversable, (1 = open, 0 = blocked)
    static bool is_unblocked(const Point& p)
    {
        return grid[p.x][p.y] == 1;
    }

    // Reconstruct the path by following the parent pointers
    static void trace_path(cell cell_details[][COLS], const Point reached, std::vector<Point>& route)
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
    static void send_to_driver(Point p)
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


private:
};
