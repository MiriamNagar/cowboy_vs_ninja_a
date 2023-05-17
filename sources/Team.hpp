#pragma once
#include <iostream>
#include <vector>
#include <typeinfo>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"

namespace ariel{
class Team
{
    private:
    Character* leader;
    std::vector<Character*> team;

    public:
    Team(Character* leader):leader(leader){}
    ~Team(){}
    void add(Character* other){}
    void attack(Team* enemy){}
    int stillAlive() const{return 0;}
    void print() const{}

    Character* getLeader(){return leader;};
};

class Team2
{
    private:
    Character* leader;
    std::vector<Character*> team;

    public:
    Team2(Character* leader):leader(leader){}
    ~Team2(){}
    void add(Character* other){}
    void attack(Team2* enemy){}
    int stillAlive() const{return 0;}
    void print() const{}

    Character* getLeader(){return leader;};
};

class SmartTeam
{
    private:
    Character* leader;
    std::vector<Character*> team;

    public:
    SmartTeam(Character* leader):leader(leader){}
    ~SmartTeam(){}
    void add(Character* other){}
    void attack(SmartTeam* enemy){}
    int stillAlive() const{return 0;}
    void print() const{}

    Character* getLeader(){return leader;};
};
}