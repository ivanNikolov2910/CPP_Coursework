#include <fstream>
#include "../../constants/constants.h"
#include "../Flight.h"

ResultCode createFlights(unsigned count = 1) {
    std::vector<Flight> flights;
    for (unsigned i = 0; i < count; ++i) {
        std::string id;
        Type type;
        std::string destination;
        unsigned time, distance;

        // Input validation
        while (true) {
            std::cout << "Enter flight id: ";
            std::cin >> id;
            if (validateId(id) == success) {
                break;
            }
            std::cout << "Flight id is not valid, try again" << std::endl;
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

        std::cout << "Enter destination: ";
        std::cin >> destination;

        std::cout << "Enter flight time in minutes: ";
        std::cin >> time;

        std::cout << "Enter distance in km: ";
        std::cin >> distance;

        flights.push_back(*new Flight(type, id, destination, time, distance));
    }

    std::fstream file;

    file.open("flights", std::fstream::in | std::fstream::out | std::fstream::app);

    if (!file) {
        file.open(FLIGHT_FILE_PATH);
        std::cerr << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Flight &flight: flights) {
        if (std::find(flights.begin(), flights.end(), flight) == flights.end()) {
            file << flight;
        }
    }

    std::cout << "Flights added successfully." << std::endl;
    return success;
}
