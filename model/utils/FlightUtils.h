#ifndef COURSEWORK_FLIGHTUTILS_H
#define COURSEWORK_FLIGHTUTILS_H

#include <iostream>
#include <fstream>
#include "../corp-data/Flight.h"

Flight readFlightData(const std::vector<Flight> &);

ResultCode appendFlightsToFile(const std::vector<Flight> &);

ResultCode updateFlightData(Flight &);

ResultCode rewriteFlights(const std::vector<Flight> &);


ResultCode ListFlights(std::vector<Flight> &);

ResultCode CreateFlights(unsigned);

ResultCode UpdateFlights(const std::string &id);

ResultCode DeleteFlights(const std::string &id);

#endif