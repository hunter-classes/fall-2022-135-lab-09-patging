#include <iostream>
#include "funcs.h"
#include "coord3d.h"
// add functions here

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

