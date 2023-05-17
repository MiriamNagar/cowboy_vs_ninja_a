#pragma once

#include <iostream>



namespace ariel{
class Point
{
private:
    double coor_x;
    double coor_y;

public:
    Point():coor_x(0), coor_y(0){}
    Point(double x, double y):coor_x(x), coor_y(y){}

    double getX(){return coor_x;}
    double getY(){return coor_y;}

    double distance(const Point& other) const{return 4.0;}
    void print() const{}
    Point moveTowards(const Point& origin, const Point& destination, double distance) const{return Point();}
};
}