#include "../FlightUtils.h"

ResultCode ListFlights(std::vector<Flight> &flights) {
    std::ifstream file(FLIGHT_FILE_PATH);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    Flight newFlight;
    while (file >> newFlight) {
        flights.push_back(newFlight);
    }

    file.close();
    return success;
}

ResultCode CreateFlights(unsigned count) {
    std::vector<Flight> flights;
    ResultCode res = ListFlights(flights);
    if (res != success) {
        std::cout << "Could not fetch flights" << std::endl;
        return not_found_error;
    }

    for (unsigned i = 0; i < count; ++i) {
        flights.push_back(readFlightData(flights));
    }

    if (appendFlightsToFile(flights) != success) {
        std::cout << "Failed to write flights to the file." << std::endl;
        return internal_error;
    }

    std::cout << "Flights added successfully." << std::endl;
    return success;
}

ResultCode UpdateFlights(const std::string &id) {
    std::vector<Flight> flights;
    ResultCode res = ListFlights(flights);
    if (res != success) {
        std::cout << "Could not fetch flights" << std::endl;
        return not_found_error;
    }

    auto it = std::find_if(flights.begin(), flights.end(),
                           [&id](const Flight &flight) {
                               return flight.getId() == id;
                           });

    if (it != flights.end()) {
        if (updateFlightData(*it) != success) {
            std::cout << "Update failed." << std::endl;
            return validation_error;
        }
        return rewriteFlights(flights);
    }

    std::cout << "Flight with ID " << id << " not found." << std::endl;
    return not_found_error;
}

ResultCode DeleteFlights(const std::string &id) {
    std::vector<Flight> flights;
    ResultCode res = ListFlights(flights);
    if (res != success) {
        std::cout << "Could not fetch flights" << std::endl;
        return not_found_error;
    }

    auto it = std::find_if(flights.begin(), flights.end(),
                           [&id](const Flight &flight) {
                               return flight.getId() == id;
                           });

    if (it != flights.end()) {
        flights.erase(it);
        return rewriteFlights(flights);
    }

    std::cout << "Could not find flight with id: " << id << std::endl;
    return internal_error;
}

ResultCode rewriteFlights(const std::vector<Flight> &flight) {
    std::ofstream file;
    file.open(FLIGHT_FILE_PATH);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Flight &s: flight) {
        file << s;
    }

    file.close();
    std::cout << "Flights updated successfully." << std::endl;
    return success;
}

Flight readFlightData(const std::vector<Flight> &flights) {
    std::string id;
    Type type;
    std::string destination;
    unsigned time, distance;

    while (true) {
        std::cout << "Enter corp-data id: ";
        std::cin >> id;

        if (!std::regex_match(id, FLIGHT_ID_PATTER)) {
            std::cout << "Flight id is not valid, try again" << std::endl;
            continue;
        }

        bool shouldRestart = false;
        for (const Flight &flight: flights) {
            if (flight.getId() == id) {
                std::cout << "Flight id already exists" << std::endl;
                shouldRestart = true;
                break;
            }
        }

        if (shouldRestart) {
            continue;
        }
        break;
    }

    while (true) {
        int userInput;
        std::cout << "Enter a type (1 - cargo, 2 - passenger): ";
        std::cin >> userInput;

        if (userInput == 1 || userInput == 2) {
            type = static_cast<Type>(userInput);
            break;
        }
        std::cout << "Invalid input for type!" << std::endl;
    }

    while (true) {
        std::cout << "Enter destination: ";
        std::cin >> destination;

        if (validateDestination(destination) == success) {
            break;
        }
        std::cout << "Invalid input for name of destination!" << std::endl;
    }

    std::cout << "Enter corp-data time in minutes: ";
    std::cin >> time;

    std::cout << "Enter distance in km: ";
    std::cin >> distance;

    return *new Flight(type, id, destination, time, distance);
}

ResultCode appendFlightsToFile(const std::vector<Flight> &flights) {
    std::fstream file;
    file.open(FLIGHT_FILE_PATH, std::fstream::app);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Flight &flight: flights) {
        file << flight;
    }

    file.close();

    return success;
}

ResultCode updateFlightData(Flight &flight) {
    char cmd;
    std::string newDestination;

    std::cout << "Enter field index to update: " << "\n"
              << "1. Destination" << "\n"
              << "2. Time duration" << "\n"
              << "3. Distance" << "\n"
              << "4. Discard changes" << "\n";
    std::cin >> cmd;

    switch (cmd) {
        case '1':
            std::cin >> newDestination;
            if (validateDestination(newDestination) == success) {
                flight.setDestination(newDestination);
            } else {
                std::cout << "Invalid input for name of destination, update failed!" << std::endl;
                return validation_error;
            }
            break;
        case '2':
            unsigned newTime;
            std::cin >> newTime;
            flight.setTime(newTime);
            break;
        case '3':
            unsigned newDistance;
            std::cin >> newDistance;
            flight.setDistance(newDistance);
            break;
        case '4':
            return success;
        default:
            std::cout << "Invalid operation index, update failed" << std::endl;
            return validation_error;
    }

    return success;
}