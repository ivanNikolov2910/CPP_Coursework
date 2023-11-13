#include "../RunwayEngine.h"


void ManageRunways() {
    char cmd;
    std::cout << "Managing runways..." << std::endl;
    while (true) {
        std::cout << "1. Create runway" << std::endl
                  << "2. Delete runway by id" << std::endl
                  << "3. List runway" << std::endl
                  << "4. Return to main menu" << std::endl
                  << std::endl
                  << "Enter option: ";
        std::cin >> cmd;

        ResultCode res;
        std::vector<Runway> runways;
        std::string id;

        switch (cmd) {
            case '1':
                res = CreateRunway();
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '2':
                std::cout << "Enter ID of runway to delete" << std::endl;
                std::cin >> id;
                res = DeleteRunway(id);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                }
                break;
            case '3':
                std::cout << "List of runways" << std::endl;

                res = ListRunway(runways);
                if (res != success) {
                    std::cout << "Changes are not saved" << std::endl;
                    break;
                }
                for (Runway &r: runways) {
                    std::cout << "Runway: " << std::endl;
                    std::cout << r << std::endl;
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
