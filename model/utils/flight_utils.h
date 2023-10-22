#ifndef COURSEWORK_FLIGHT_UTILS_H
#define COURSEWORK_FLIGHT_UTILS_H

#include "../../constants/constants.h"

ResultCode createFlights(unsigned count = 1);

ResultCode listFlights(std::vector<Flight> *flights);

#endif //COURSEWORK_FLIGHT_UTILS_H