#include <iostream>
#include "../PlaneEngine.h"

void ManagePlanes() {
    while (true) {
        std::cout << "Managing planes..." << std::endl;
        std::cout << "1. Create planes [-count]" << std::endl
                  << "2. Delete plane by ID" << std::endl
                  << "3. List planes" << std::endl
                  << "4. Return to the main menu" << std::endl
                  << std::endl
                  << "Enter an option: ";

        char cmd;
        std::cin >> cmd;

        int count = 0;
        ResultCode res;
        std::vector<Plane *> planes;
        std::string id;

        switch (cmd) {
            case '1':
                std::cout << "Enter the count of planes to create: ";
                std::cin >> count;
                res = CreatePlanes(count);

                if (res != success) {
                    std::cout << "Failed to create planes." << std::endl;
                } else {
                    std::cout << "Planes created successfully." << std::endl;
                }
                break;
            case '2':
                std::cout << "Enter the ID of the plane to delete: ";
                std::cin >> id;
                res = DeletePlane(id);

                if (res != success) {
                    std::cout << "Failed to delete the plane." << std::endl;
                } else {
                    std::cout << "Plane deleted successfully." << std::endl;
                }
                break;
            case '3':
                std::cout << "List of planes:" << std::endl;
                res = ListPlanes(planes);

                if (res != success) {
                    std::cout << "Failed to list planes." << std::endl;
                } else {
                    for (const Plane *p: planes) {
                        std::cout << "Plane:" << std::endl;
                        std::cout << *p << std::endl;
                        std::cout << "-----------------------\n";
                    }
                }
                break;
            case '4':
                return;
            default:
                std::cout << "Invalid option! Please choose a valid option." << std::endl;
        }
    }
}

