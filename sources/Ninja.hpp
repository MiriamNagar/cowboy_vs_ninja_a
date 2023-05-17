#pragma once
#include <iostream>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Point.hpp"

namespace ariel{
class Ninja: public Character
{
    private:
    int speed;

    public:
    Ninja(std::string name, const Point& loc, int hit, int speed):Character(name, loc, hit), speed(speed){}
    void move(const Character* c){return;}
    void slash(Character* c) const{return;}

    int getSpeed(){return speed;};
};


class OldNinja: public Ninja
{
    public:
    OldNinja(std::string name, const Point& loc):Ninja(name, location, 8, 150){}
};

class TrainedNinja: public Ninja
{
    public:
    TrainedNinja(std::string name, const Point& loc):Ninja(name, location, 12, 120){}
};

class YoungNinja: public Ninja
{
    public:
    YoungNinja(std::string name, const Point& loc):Ninja(name, location, 14, 100){}
};
}