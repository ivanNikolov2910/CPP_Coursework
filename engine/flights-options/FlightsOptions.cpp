
#include "FlightsOptions.h"

ResultCode FlightsManagingOptions(std::vector<Flight> &flights) {
    char cmd;
    ResultData *resultData;
    ResultCode res;

    std::vector<Plane *> planes;
    std::vector<Runway> runways;
    Flight *flightToAssign;
    std::string flightId;

    res = ListRunway(runways);
    if (res != success) {
        std::cout << "No runways found to list" << std::endl;
        return internal_error;
    }

    res = ListPlanes(planes);
    if (res != success) {
        std::cout << "No planes found to list" << std::endl;
        return internal_error;
    }

    while (true) {
        std::cout << "1. Assign plane to flight" << std::endl
                  << "2. Search for recommended plane" << std::endl
                  << "3. Search assignable planes for flight" << std::endl
                  << "4. Return to main menu" << std::endl
                  << std::endl
                  << "Enter option: ";
        std::cin >> cmd;
        switch (cmd) {
            case '1':
                std::cout << "Assigning plane" << std::endl;
                for (const Flight &f: flights) {
                    std::cout << "Flight:" << std::endl;
                    std::cout << f;
                    std::cout << "-----------------------\n";
                }
                std::cout << "Enter plane id: ";
                while (true) {
                    std::cin >> flightId;
                    if (!std::regex_match(flightId, FLIGHT_ID_PATTER)) {
                        std::cout << "FLight id not valid" << std::endl;
                        continue;
                    }
                    break;
                }
                for (Flight &f: flights) {
                    if (f.getId() == flightId) {
                        flightToAssign = &f;
                        break;
                    }
                }

                if (flightToAssign == nullptr) {
                    std::cout << "Flight not found" << std::endl;
                    break;
                }

                std::cout << "Flight is assign to file" << std::endl;
                res = assignPlane(*flightToAssign, planes, runways);
                if (res != success) {
                    std::cout << "An error occurred, flight is not assigned" << std::endl;
                    break;
                }
                std::cout << "Flight is assigned to a plane" << std::endl;
                break;
            case '2':
                std::cout << "Searching for recommended plane" << std::endl;
                std::cout << "Enter flight id: ";
                while (true) {
                    std::cin >> flightId;
                    if (std::regex_match(flightId, FLIGHT_ID_PATTER)) {
                        break;
                    }
                    std::cout << "Flight id not valid" << std::endl;
                }

                for (const Flight &f: flights) {
                    if (f.getId() == flightId) {
                        resultData = recommendedPlanesByFlight(planes, f, runways);

                        if (resultData && resultData->res == success) {
                            std::cout << "Recommended Plane: " << *resultData->plane << "\n"
                                      << "on Runway: " << resultData->runway << std::endl;

                            std::cout << "Do you want to assign this plane: [y/n]";
                            std::cin >> cmd;
                            if (cmd == 'y') {
                                std::fstream file(ASSIGN_FLIGHTS_FILE_PATH, std::fstream::app);
                                if (file) {
                                    file << *resultData->plane << "\n"
                                         << f << "\n"
                                         << resultData->runway << "\n";
                                    file.close();
                                } else {
                                    std::cout << "Failed to open the file." << std::endl;
                                }
                            }
                        } else {
                            std::cout << "Could not process data to find the best plane" << std::endl;
                        }
                        break;
                    }
                }
                if (resultData) {
                    delete resultData;
                    resultData = nullptr;
                }
                break;
            case '3':
                std::cout << "Searching for applicable plane for flight" << std::endl;
                std::cout << "Enter flight id: ";
                while (true) {
                    std::cin >> flightId;
                    if (std::regex_match(flightId, FLIGHT_ID_PATTER)) {
                        break;
                    }
                    std::cout << "Flight id not valid" << std::endl;
                }

                for (const Flight &f: flights) {
                    if (f.getId() == flightId) {
                        std::string runwayId;
                        std::cout << "Select runway for the flight" << std::endl;
                        std::cin >> runwayId;
                        Runway *r = Runway::getRunwayById(runwayId, &runways);
                        if (r == nullptr) {
                            return not_found_error;
                        }
                        std::vector<Plane *> out;
                        res = applicablePlanesPerFlight(planes, f, *r, &out);
                        if (res != success) {
                            std::cout << "Could not find applicable flight" << std::endl;
                        }
                        for (Plane *p: out) {
                            std::cout << *p << std::endl;
                        }
                        break;
                    }
                }
                break;
            case '4':
                return success;
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }
}

ResultData *recommendedPlanesByFlight(const std::vector<Plane *> &planes, const Flight &flight,
                                      const std::vector<Runway> &runways) {
    auto *result = new ResultData;
    double minExpense = std::numeric_limits<double>::max();

    for (Plane *p: planes) {
        double totalExpense = calculateExpensesForFlight(*p, flight);

        for (const Runway &r: runways) {
            int runwayLengthDiff = p->getRunwayLength() - r.getLength();

            if (runwayLengthDiff >= 0 && totalExpense < minExpense) {
                minExpense = totalExpense;
                if (instanceof<CargoPlane>(p)) {
                    result->plane = dynamic_cast<CargoPlane *>(p);
                } else if (instanceof<PassengerPlane>(p)) {
                    result->plane = dynamic_cast<PassengerPlane *>(p);
                } else {
                    delete result;
                    return new ResultData(internal_error, {}, nullptr);
                }
                result->res = success;
                result->runway = r;
            }
        }
    }
    return result;
}

double calculateExpensesForFlight(const Plane &plane, const Flight &flight) {
    double fuelCost = flight.getDistance() * plane.getFuelPerKilometer() * FUEL_PRICE_PER_LITER;
    double staffSalary = flight.getDistance() *
                         ((static_cast<int>(flight.getDistance() / 1000) + 1) * STEWARD_SALARY_PER_FLIGHT *
                          plane.getStewardCount() +
                          (static_cast<int>(flight.getDistance() / 1000) + 1) * PILOT_SALARY_PER_FLIGHT *
                          plane.getPilotCount());
    return fuelCost + staffSalary;
}

ResultCode assignPlane(const Flight &flight, const std::vector<Plane *> &planes, const std::vector<Runway> &runways) {
    Type flightType = flight.getType();
    std::ofstream file(ASSIGN_FLIGHTS_FILE_PATH, std::fstream::app);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Plane *p: planes) {
        if ((flightType == cargo && instanceof<CargoPlane>(p)) ||
            (flightType == passenger && instanceof<PassengerPlane>(p))) {
            for (const Runway &r: runways) {
                if (flight.getDistance() >= r.getLength()) {
                    file << p << flight << r << "\n";
                    file.close();
                    return success;
                }
            }
        }
    }
    std::cout << "No suitable planes found for the corp-data" << std::endl;
    return internal_error;
}

ResultCode applicablePlanesPerFlight(const std::vector<Plane *> &planes, const Flight &flight, const Runway &runway,
                                     std::vector<Plane *> *out) {
    Type flightType = flight.getType();

    for (Plane *plane: planes) {
        if ((flightType == cargo && instanceof<CargoPlane>(plane)) ||
            (flightType == passenger && instanceof<PassengerPlane>(plane))) {
            if (plane->getRunwayLength() <= runway.getLength()) {
                out->push_back(plane);
            }
        }
    }

    return out->empty() ? not_found_error : success;
}

