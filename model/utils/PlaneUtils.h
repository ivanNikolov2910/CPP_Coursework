#ifndef COURSEWORK_PLANEUTILS_H
#define COURSEWORK_PLANEUTILS_H

#include <fstream>
#include "../corp-data/Flight.h."
#include "../plane/CargoPlane.h"
#include "../plane/PassengerPlane.h"
#include "../../constants/constants.h"

Plane *readPlaneData(const std::vector<Plane *> &);

ResultCode appendPlanesToFile(const std::vector<Plane *> &);

ResultCode rewritePlanes(const std::vector<Plane *> &);


ResultCode ListPlanes(std::vector<Plane *> &planes);

ResultCode CreatePlanes(int);

ResultCode DeletePlane(const std::string &id);

#endif
