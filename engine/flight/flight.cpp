#include "flight.h"

using std::cout, std::endl, std::cin;

void managingFlights() {
    char cmd;
    std::cout << "Managing flights..." << std::endl;
    while (true) {
        cout << "1. Create flights [-count]" << endl
             << "2. Delete flights by id" << endl
             << "3. List flights" << endl
             << "4. Return to main menu" << endl
             << endl
             << "Enter option: ";
        cin >> cmd;

        unsigned count;
        ResultCode res;
        std::vector<Flight> flights;

        switch (cmd) {
            case '1':
                count = 1;
                cout << "Enter count of flight to create" << endl;
                cin >> count;
                res = createFlights(count);
                if (res != success) {
                    cout << "Changes are not saved" << endl;
                }
                break;
            case '2':
                cout << "Managing planes..." << endl;
                break;
            case '3':
                res = listFlights(&flights);
                if (res != success) {
                    cout << "Changes are not saved" << endl;
                }
                for (Flight &f: flights) {
                    std::cout << f;
                }
                break;
            case '4':
                return;
            default:
                cout << "Invalid option!" << endl;
        }

    }
}