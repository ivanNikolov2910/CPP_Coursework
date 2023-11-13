#ifndef COURSEWORK_RUNWAYUTILS_H
#define COURSEWORK_RUNWAYUTILS_H


#include <fstream>
#include "../corp-data/Runway.h"
#include "../../constants/constants.h"

Runway readRunwayData(const std::vector<Runway> &);

ResultCode appendRunwayToFile(const std::vector<Runway> &);

ResultCode rewriteRunway(const std::vector<Runway> &runway);


ResultCode ListRunway(std::vector<Runway> &runway);

ResultCode CreateRunway();

ResultCode DeleteRunway(const std::string &id);

#endif