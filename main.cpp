#include <iostream>
#include "engine/FlightEngine.h"
#include "engine/PlaneEngine.h"
#include "engine/StaffEngine.h"
#include "engine/RunwayEngine.h"

int main() {
    char cmd;

    while (true) {
        std::cout << "Menu:" << std::endl
                  << "1. Manage flights" << std::endl
                  << "2. Manage planes" << std::endl
                  << "3. Manage staff" << std::endl
                  << "4. Manage runways" << std::endl
                  << "5. Exit" << std::endl
                  << std::endl
                  << "Enter option: ";
        std::cin >> cmd;

        switch (cmd) {
            case '1':
                ManageFlights();
                break;
            case '2':
                ManagePlanes();
                break;
            case '3':
                ManageStaff();
                break;
            case '4':
                ManageRunways();
                break;
            case '5':
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid option!" << std::endl;
        }

    }
}


