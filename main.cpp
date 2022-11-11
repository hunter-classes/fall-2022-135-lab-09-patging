/*
  Patrick Ging
  Professor Zamanksy
  Lab 9
  main.cpp
*/

#include <iostream>
#include "funcs.h"

std::string printPoint(Coord3D *point) {
  /*
  Prints a point in a string mode. Mostly to make writing main code easier
  returns a string
  */
  return "{" + std::to_string((*point).x) + "," + std::to_string((*point).y) + "," + std::to_string((*point).z) + "}";
}

int main()
{
  
  Coord3D point = {1,2,3};
  Coord3D point2 = {0,0,3};
  Coord3D velocities = {0,1,2};

  // length
  std::cout << "Length of the vector " << printPoint(&point) << "is " << length(&point) << std::endl;
  std::cout << "Length of the vector " << printPoint(&point2) << "is " << length(&point2) << std::endl;

  //Farther from original

  std::cout << "The farthest from the origin between " << printPoint(&point) << " and " << printPoint(&point2) << " is ";


  if (fartherFromOrigin(&point,&point2) == &point) {
      std::cout << printPoint(&point) << std::endl;
  } else {
        std::cout << printPoint(&point2) << std::endl;
  }

  //Move
 
  std::cout << printPoint(&point) << " with velocities " << printPoint(&velocities) << " after 10 seconds is ";
  move(&point,&velocities,10);
  std::cout << printPoint(&point) << std::endl;

  //creae/dete

  Coord3D * cord; 
  cord = createCoord3D(1,1,1);

  std::cout << "Created point " << printPoint(cord) << " with length " << length(cord) << std::endl;
  deleteCoord3D(cord);
  std::cout << "Deleted point" << std::endl;

    return 0;

}
