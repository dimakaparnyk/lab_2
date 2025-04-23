#pragma once

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
    double area() const;
    bool contains(const Point& p) const;
    bool containsAlt(const Point& p) const;
    bool isDegenerate() const;  // Add this method declaration
};

double dist(const Point& p1, const Point& p2);
double cross(const Point& p1, const Point& p2);
double heronArea(const Triangle& t);
