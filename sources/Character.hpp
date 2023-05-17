#pragma once
#include <iostream>

#include "Point.hpp"

namespace ariel{
class Character
{
    protected:
    Point location;
    int hit_points;
    std::string name;

    public:
    Character(std::string name, const Point& loc, int hit):name(name), location(loc), hit_points(hit){}

    bool isAlive() const{return false;}
    double distance(const Character& c) const{return 2.0;}
    void hit(int hits){}
    std::string getName() const{return name;}
    Point getLocation() const{return location;}
    std::string print() const{return name;}

    int getHitP(){return hit_points;}

};
}