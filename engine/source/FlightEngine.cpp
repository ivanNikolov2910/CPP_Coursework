#include "../FlightEngine.h"

void ManageFlights() {
    char cmd;
    std::cout << "Managing flights..." << std::endl;
    while (true) {
        std::cout << "1. Create flights [-count]" << std::endl
                  << "2. Update flights by id" << std::endl
                  << "3. Delete flights by id" << std::endl
                  << "4. List flights" << std::endl
                  << "5. Detailed flights menu" << std::endl
                  << "6. Return to main menu" << std::endl
                  << std::endl
                  << "Enter option: ";
        std::cin >> cmd;

        unsigned count;
        ResultCode res;
        std::vector<Flight> flights;
        std::string id;

        switch (cmd) {
            case '1':
                count = 1;
                std::cout << "Enter count of flight to create" << std::endl;
                std::cin >> count;
                res = CreateFlights(count);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '2':
                std::cout << "Enter ID of flight to update" << std::endl;
                std::cin >> id;
                res = UpdateFlights(id);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '3':
                std::cout << "Enter ID of flight to delete" << std::endl;
                std::cin >> id;
                res = DeleteFlights(id);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '4':
                std::cout << "List of flights" << std::endl;

                res = ListFlights(flights);
                if (res != success) {
                    std::cout << "Could not list flights" << std::endl;
                    break;
                }
                std::cout << flights.capacity() << "\n";
                std::cout << flights.size() << "\n";
                for (Flight &f: flights) {
                    std::cout << "Flight: " << std::endl;
                    std::cout << f << std::endl;
                    std::cout << "-----------------------\n";
                }
                break;
            case '5':
                std::cout << "Detailed Flights Menu" << std::endl;
                res = ListFlights(flights);
                if (res != success) {
                    std::cout << "Could not list flights" << std::endl;
                    break;
                }
                if (!flights.empty()) {
                    res = FlightsManagingOptions(flights);
                    if (res != success) {
                        std::cout << "Changes are not saved" << std::endl;
                        break;
                    }
                } else {
                    std::cout << "No flights for detailed options" << std::endl;
                }
                break;
            case '6':
                return;
            default:
                std::cout << "Invalid option!" << std::endl;
        }

    }
}