/*
    Patrick Ging
    Professor Zamanksy
    Lab 09 
    tests.cpp
*/
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"

#include "funcs.h"

TEST_CASE("Testing the Coord3D class") {
    Coord3D p = {1,2,3};

    // in cpp any non zero non null num is truthy
    CHECK(p.x);
    CHECK(p.y);
    CHECK(p.z);

    CHECK(p.x == 1);
    CHECK(p.y == 2);
    CHECK(p.z == 3);
};


TEST_CASE("Testing Coord3D length") {
    Coord3D p = {2,0,0};
    Coord3D q = {2,-2,0};
    Coord3D g = {2,2,4};

    // thanks to emily klapper for the technique
    CHECK(length(&p) - 2 < 0.001);
    CHECK(length(&q) - 2.82843 < 0.001);
    CHECK(length(&g) -  4.89898 < 0.001);

};

TEST_CASE("FartherFromOrigin") {
    Coord3D p = {2,0,0};
    Coord3D q = {2,-2,0};
    Coord3D g = {2,2,4};

    CHECK(fartherFromOrigin(&p,&q) == &q);
    CHECK(fartherFromOrigin(&p,&g) == &g);
    CHECK(fartherFromOrigin(&g,&q) == &g);

};

TEST_CASE("Move() tests") {

    Coord3D p = {1,2,3};
    Coord3D v = {1,1,1};
    move(&p,&v,10);

    CHECK(p.x == 11);
    CHECK(p.y == 12);
    CHECK(p.z == 13);

    move(&p,&v,-10);

    CHECK(p.x == 1);
    CHECK(p.y == 2);
    CHECK(p.z == 3);

}

TEST_CASE("Delete AND Create funcs") {

    Coord3D* c1 = createCoord3D(1,1,1);
    Coord3D* c2 = createCoord3D(10,11,21);
    Coord3D* c3 = createCoord3D(-1,121,121);

    // seeing if the adresses exist
    CHECK(&c1);
    CHECK(&c2);
    CHECK(&c3);

    CHECK((*c1).x == 1);
    CHECK((*c1).y == 1);
    CHECK((*c1).z == 1);

    CHECK((*c2).x == 10);
    CHECK((*c2).y == 11);
    CHECK((*c2).z == 21);

    CHECK((*c3).x == -1);
    CHECK((*c3).y == 121);
    CHECK((*c3).z == 121);

    deleteCoord3D(c1);
    deleteCoord3D(c2);
    deleteCoord3D(c3);


};