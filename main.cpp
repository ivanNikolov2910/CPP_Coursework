#include <iostream>
#include "engine/flight/FlightEngine.h"

using namespace std;

int main() {
    char cmd;

    while (true) {
        cout << "Menu:" << endl
             << "1. Manage flights" << endl
             << "2. Manage planes" << endl
             << "3. Manage staff" << endl
             << "4. Exit" << endl
             << endl
             << "Enter option: ";
        cin >> cmd;

        switch (cmd) {
            case '1':
                ManagingFlights();
                break;
            case '2':
                cout << "Managing planes..." << endl;
                break;
            case '3':
                cout << "Managing staff..." << endl;
                break;
            case '4':
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option!" << endl;
        }

    }
}


