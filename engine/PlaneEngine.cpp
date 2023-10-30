#include <iostream>
#include "../model/utils/PlaneUtils.cpp"
#include "../model/Plane.h"

void ManagePlanes() {
    char cmd;
    std::cout << "Managing flights..." << std::endl;
    while (true) {
        std::cout << "1. Create planes [-count]" << std::endl
                  << "2. Delete plane by id" << std::endl
                  << "3. List planes" << std::endl
                  << "4. Return to main menu" << std::endl
                  << std::endl
                  << "Enter option: ";
        std::cin >> cmd;

        int count;
        ResultCode res;
        std::vector<Plane> planes;
        string id;

        switch (cmd) {
            case '1':
                count = 1;
                std::cout << "Enter count of planes to create" << std::endl;
                std::cin >> count;
                res = CreatePlanes(count);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '2':
                std::cout << "Enter ID of plane to delete" << std::endl;
                std::cin >> id;
                res = DeletePlane(id);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '3':
                std::cout << "List of flights" << std::endl;
                res = ListPlanes(&planes);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                for (Plane &p: planes) {
                    std::cout << "Flight: " << std::endl;
                    std::cout << p;
                    std::cout << "-----------------------\n";
                }
                break;
            case '4':
                return;
            default:
                std::cout << "Invalid option!" << std::endl;
        }

    }
}