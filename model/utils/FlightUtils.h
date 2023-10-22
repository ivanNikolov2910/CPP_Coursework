#ifndef COURSEWORK_FLIGHTUTILS_H
#define COURSEWORK_FLIGHTUTILS_H

#include "../../constants/constants.h"

ResultCode CreateFlights(unsigned count = 1);

ResultCode ListFlights(std::vector<Flight> *flights);

ResultCode UpdateFlights(std::string id);

ResultCode DeleteFlights(std::string id);

#endif //COURSEWORK_FLIGHTUTILS_H