/*
    Patrick Ging
    Professor Zamanksy
    Lab 09 
    funcs.cpp
*/
#include <iostream>
#include <cmath>
#include "funcs.h"

void deleteCoord3D(Coord3D *p) {
    // deletes the coordinate manually
    delete p;
}

Coord3D* createCoord3D(double x, double y, double z) {
    /*
        Creates a manual memory entry of Coord3d and will
        asssign it x y z and return the entrys address.
    */
    Coord3D* coord = new Coord3D;
    (*coord).x = x;
    (*coord).y = y;
    (*coord).z = z;

    return coord;
}

double length(Coord3D *p) {
    /*
        Returns the distance of the point from the origin
        using distance formula
    */
   int x = (*p).x;
   int y = (*p).y;
   int z = (*p).z;

   return std::sqrt(x*x + y*y + z*z);
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    /* 
        Takes two points, p1, and p2, and returns the adress of 
        the pointer farther away from the origin
    */

    double d1 = length(p1);
    double d2 = length(p2);

    if (d1 > d2) {
        return p1; 
    } else {
        return p2;
    }

}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    /*
        Takes a position and velocity vector and will apply the velocity to 
        the position vector according to the time

        returns nothing
    */
   // new position = old position + time * velocity
   (*ppos).x = (*ppos).x + dt * (*pvel).x;
   (*ppos).y = (*ppos).y + dt * (*pvel).y;
   (*ppos).z = (*ppos).z + dt * (*pvel).z;
}