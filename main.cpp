#include <iostream>
#include "engine/FlightEngine.cpp"
#include "engine/PlaneEngine.cpp"

using namespace std;

int main() {
    char cmd;

    while (true) {
        cout << "Menu:" << endl
             << "1. Manage flights" << endl
             << "2. Manage planes" << endl
             << "3. Manage staff" << endl
             << "4. Manage runways" << endl
             << "5. Exit" << endl
             << endl
             << "Enter option: ";
        cin >> cmd;

        switch (cmd) {
            case '1':
                ManageFlights();
                break;
            case '2':
                ManagePlanes();
                break;
            case '3':
                cout << "Managing staff..." << endl;
                break;
            case '4':
                cout << "Managing runways..." << endl;
                break;
            case '5':
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid option!" << endl;
        }

    }
}


