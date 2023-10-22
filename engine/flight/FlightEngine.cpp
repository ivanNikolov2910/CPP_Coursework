#include "FlightEngine.h"

using std::cout, std::endl, std::cin;

void ManagingFlights() {
    char cmd;
    std::cout << "Managing flights..." << std::endl;
    while (true) {
        cout << "1. Create flights [-count]" << endl
             << "2. Update flights by id" << endl
             << "3. Delete flights by id" << endl
             << "4. List flights" << endl
             << "5. Return to main menu" << endl
             << endl
             << "Enter option: ";
        cin >> cmd;

        unsigned count;
        ResultCode res;
        std::vector<Flight> flights;
        std::string id;

        switch (cmd) {
            case '1':
                count = 1;
                cout << "Enter count of flight to create" << endl;
                cin >> count;
                res = CreateFlights(count);
                if (res != success) {
                    cout << "Changes are not saved" << endl;
                }
                break;
            case '2':
                cout << "Enter ID of flight to update" << endl;
                cin >> id;
                res = UpdateFlights(id);
                if (res != success) {
                    cout << "Changes are not saved" << endl;
                }
                break;
            case '3':
                cout << "Enter ID of flight to delete" << endl;
                cin >> id;
                res = DeleteFlights(id);
                if (res != success) {
                    cout << "Changes are not saved" << endl;
                }
                break;
            case '4':
                cout << "List of flights" << endl;

                res = ListFlights(&flights);
                if (res != success) {
                    cout << "Changes are not saved" << endl;
                }
                for (Flight &f: flights) {
                    std::cout << "Flight: " << std::endl;
                    std::cout << f;
                    std::cout << "-----------------------\n";
                }
                break;
            case '5':
                return;
            default:
                cout << "Invalid option!" << endl;
        }

    }
}