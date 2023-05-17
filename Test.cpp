#include "doctest.h"
#include <stdexcept>
#include <iostream>
using namespace std;

#include "sources/Ninja.hpp"
#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
using namespace ariel;


TEST_SUITE("Point class") {

    TEST_CASE("constructors") {
        //default constructor
        Point p;
        CHECK(p.getX() == 0);
        CHECK(p.getY() == 0);

        Point p2(4, 9);
        CHECK(p2.getX() == 4);
        CHECK(p2.getY() == 9);
    }

    TEST_CASE("distance function") {
        Point p1(4, 4);
        Point p2(7, 8);
        CHECK(p1.distance(p2) == 5);
    }

    TEST_CASE("moveTowards function") {
        Point p1(4, 4);
        Point p2(4, 7);
        Point p3(4, 6);
        CHECK(p1.moveTowards(p1, p2, 2).getX() == 4);
        CHECK(p1.moveTowards(p1, p2, 2).getY() == 6);
    }
}

TEST_SUITE("Character class") {

    TEST_CASE("constructor") {
        Point p;
        Character c("mushe", p, 100);
        CHECK(c.getLocation().getX() == 0);
        CHECK(c.getLocation().getY() == 0);
        CHECK(c.getName() == "mushe");
        CHECK(c.getHitP() == 100);
        CHECK(c.isAlive() == true);
    }

    TEST_CASE("distance function") {
        Point p1(4, 4);
        Point p2(7, 8);
        Character c1("mushe", p1, 100);
        Character c2("avi", p2, 80);
        CHECK(c1.distance(c2) == 5);
    }

    TEST_CASE("hit function") {
        Point p;
        Character c("mushe", p, 100);
        c.hit(6);
        CHECK(c.getHitP() == 94);
    }
}

TEST_SUITE("Cowboy class") {

    TEST_CASE("constructor") {
        Point p(14,7);
        Cowboy c("mushe", p);
        CHECK(c.getLocation().getX() == 14);
        CHECK(c.getLocation().getY() == 7);
        CHECK(c.getName() == "mushe");
        CHECK(c.getHitP() == 110);
        CHECK(c.getBullets() == 6);
    }

    TEST_CASE("shoot function") {
        Point p1(14,7);
        Point p2(7, 8);
        Cowboy c("mushe", p1);
        Cowboy b("avi", p2);
        c.shoot(&b);
        CHECK(b.getHitP() == 100);
        for(int i = 0; i< 10; i++)
        {
            c.shoot(&b);
        }
        CHECK(b.getHitP() == 50);
        c.reload();
        for(int i = 0; i< 5; i++)
        {
            c.shoot(&b);
        }
        CHECK(b.getHitP() == 0);
        b.shoot(&c);
        CHECK(c.getHitP() == 110);
    }

    TEST_CASE("hasboolets function") {
        Point p1(14,7);
        Point p2(7, 8);
        Cowboy c("mushe", p1);
        Cowboy b("avi", p2);
        CHECK(c.hasboolets() == true);
        for(int i = 0; i< 6; i++)
        {
            c.shoot(&b);
        }
        CHECK(c.hasboolets() == false);
    }

    TEST_CASE("reload function") {
        Point p1(14,7);
        Point p2(7, 8);
        Cowboy c("mushe", p1);
        Cowboy b("avi", p2);
        CHECK(c.hasboolets() == true);
        for(int i = 0; i< 6; i++)
        {
            c.shoot(&b);
        }
        CHECK(c.hasboolets() == false);
        c.reload();
        CHECK(c.hasboolets() == true);
    }
}


TEST_SUITE("Ninja class and Ninja successor classes") {

    TEST_CASE("constructors") {
        //Ninja ctor
        Point p(2,1);
        Ninja c("jackieChan", p, 100, 34);
        CHECK(c.getLocation().getX() == 2);
        CHECK(c.getLocation().getY() == 1);
        CHECK(c.getName() == "jackieChan");
        CHECK(c.getHitP() == 100);
        CHECK(c.getSpeed() == 34);

        YoungNinja yn("david", p);
        CHECK(yn.getLocation().getX() == 2);
        CHECK(yn.getLocation().getY() == 1);
        CHECK(yn.getName() == "david");
        CHECK(yn.getHitP() == 100);
        CHECK(yn.getSpeed() == 14);

        TrainedNinja tn("lee", p);
        CHECK(tn.getLocation().getX() == 2);
        CHECK(tn.getLocation().getY() == 1);
        CHECK(tn.getName() == "lee");
        CHECK(tn.getHitP() == 120);
        CHECK(tn.getSpeed() == 12);

        OldNinja on("avi", p);
        CHECK(on.getLocation().getX() == 2);
        CHECK(on.getLocation().getY() == 1);
        CHECK(on.getName() == "avi");
        CHECK(on.getHitP() == 150);
        CHECK(on.getSpeed() == 8);
    }
       
    TEST_CASE("slash function") {
        Point p(2,1);
        YoungNinja yn("david", p);
        TrainedNinja tn("lee", p);
        yn.slash(&tn);
        CHECK(tn.getHitP() == 80);
    }
}


TEST_SUITE("Ninja class and Ninja successor classes") {

    TEST_CASE("constructors") {
        //Ninja ctor
        Point p(2,1);
        Point p2(14,7);

        YoungNinja yn("david", p);
        TrainedNinja tn("lee", p);
        OldNinja on("avi", p);
        Cowboy c("mushe", p2);

        Team t1(&yn);
        Team2 t2(&tn);
        SmartTeam t3(&c);
        CHECK(t1.getLeader() == &yn);
        CHECK(t2.getLeader() == &tn);
        CHECK(t3.getLeader() == &c);

    }
    TEST_CASE("stillAlive function") {
        Point p(2,1);
        Point p2(14,7);

        YoungNinja yn("david", p);
        TrainedNinja tn("lee", p);
        OldNinja on("avi", p);
        Cowboy c("mushe", p2);

        Team t1(&yn);
        t1.add(&tn);
        CHECK(t1.stillAlive() == true);
    }
}