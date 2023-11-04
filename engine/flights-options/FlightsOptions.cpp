#include <vector>
#include "../../model/Flight.h"
#include "../../model/Plane.h"

ResultCode recommendedPlanesByFlight(std::vector<Plane> &planes, Flight flight);

ResultCode calculateExpensesForFlight(double &totalExpenses, Plane plane, Flight flight);

ResultCode FlightsManagingOptions(std::vector<Flight> &flights) {
    char cmd;
    while (true) {
        std::cin >> cmd;

        switch (cmd) {
            case '1':
                std::cout << "Assign plane to flight" << std::endl;
                break;
            case '2':
                std::cout << "Search for recommended plane for flight" << std::endl;
                break;
            case '3':
                return success;
            default:
                std::cout << "Invalid option" << std::endl;
        }
    }
}