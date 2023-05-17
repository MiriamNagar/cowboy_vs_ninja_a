#pragma once
#include <iostream>

#include "Character.hpp"
#include "Ninja.hpp"
#include "Point.hpp"

namespace ariel{
class Cowboy: public Character
{
    private:
    int bullets;

    public:
    Cowboy(std::string name, const Point& loc):Character(name, loc, 110), bullets(6){}
    void shoot(Character* c){}
    bool hasboolets() const{return false;}
    void reload(){}

    int getBullets(){return bullets;}

};
}