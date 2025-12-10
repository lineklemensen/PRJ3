#pragma once

#include <cmath>

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
    double priority;
    Point point;

    bool operator>(const PriorityPoint& p) const
    {
        return p.priority > priority;
    }
};