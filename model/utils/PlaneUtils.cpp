#include "../plane/CargoPlane.h"
#include "../plane/PassengerPlane.h"

Plane *readPlaneData(const std::vector<Plane *> &);

ResultCode appendPlanesToFile(const std::vector<Plane *> &);

ResultCode rewritePlanes(const std::vector<Plane *> &);

ResultCode ListPlanes(std::vector<Plane *> *planes) {
    std::ifstream file(PLANE_FILE_PATH);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    Plane *abstractPlane;
    while (file >> *abstractPlane) {
        planes->push_back(abstractPlane);
    }

    return success;
}

ResultCode CreatePlanes(int count) {
    std::vector<Plane *> planes;
    ResultCode res = ListPlanes(&planes);
    if (res != success) {
        std::cout << "Could not fetch flights" << std::endl;
    }

    for (int i = 0; i < count; ++i) {
        Plane *newPlane = readPlaneData(planes);
        planes.push_back(newPlane);
    }

    if (appendPlanesToFile(planes) != success) {
        std::cout << "Failed to write flights to the file." << std::endl;
        return internal_error;
    }

    std::cout << "Flights added successfully." << std::endl;
    return success;
}

ResultCode DeletePlane(const std::string &id) {
    std::vector<Plane *> planes;
    ResultCode res = ListPlanes(&planes);
    if (res != success) {
        std::cout << "Failed to fetch flights" << std::endl;
        return internal_error;
    }
    int toDelete = -1;
    for (int i = 0; i < planes.capacity(); ++i) {
        if (planes.at(i)->getId() == id) {
            toDelete = i;
            break;
        }
    }

    std::cout << toDelete;
    if (toDelete != -1) {
        planes.erase(planes.begin() + toDelete);
        return rewritePlanes(planes);
    }
    std::cout << "Could not find corp-data with id: " << id << std::endl;
    return internal_error;
}

Plane *readPlaneData(const std::vector<Plane *> &planes) {
    std::string id, manufacturer, brand;
    int runwayLength;
    double fuelPerKilometer;
    int pilotCount = 0, stewardCount = 0;

    int businessSeat = 0, passengerSeat = 0;
    int cargoWeight = 0;

    while (true) {
        std::cout << "Enter corp-data id: ";
        std::cin >> id;

        if (!std::regex_match(id, PLANE_ID_PATTER)) {
            std::cout << "Flight id is not valid, try again" << std::endl;
            continue;
        }

        bool shouldRestart = false;
        for (const Plane *plane: planes) {
            if (plane->getId() == id) {
                std::cout << "Plane id already exists" << std::endl;
                shouldRestart = true;
                break;
            }
        }

        if (shouldRestart) {
            continue;
        }
        break;
    }

    Type type;
    while (true) {
        int userInput;
        std::cout << "Enter a type (0 - cargo, 1 - passenger): ";
        std::cin >> userInput;

        if (userInput == 0 || userInput == 1) {
            type = static_cast<Type>(userInput);
            break;
        }
        std::cout << "Invalid input for type!" << std::endl;
    }

    std::cout << "Enter manufacturer: ";
    std::cin >> manufacturer;

    std::cout << "Enter brand: ";
    std::cin >> brand;

    std::cout << "Enter minimal runway length: ";
    std::cin >> runwayLength;

    std::cout << "Enter fuel per kilometer expense: ";
    std::cin >> fuelPerKilometer;

    std::cout << "Enter needed count of pilots: ";
    std::cin >> pilotCount;

    std::cout << "Enter needed count of stewards: ";
    std::cin >> stewardCount;

    if (type == cargo) {
        std::cout << "Enter max cargo weight [kg]: " << std::endl;
        std::cin >> cargoWeight;
    }
    if (type == passenger) {
        std::cout << "Enter count of seats for business class: " << std::endl;
        std::cin >> businessSeat;

        std::cout << "Enter count of seats for passenger class: " << std::endl;
        std::cin >> passengerSeat;
    }

    Plane *newPlane;
    if (cargoWeight > 0) {
        newPlane = new CargoPlane(id, manufacturer, brand, runwayLength, fuelPerKilometer, pilotCount, stewardCount,
                                  cargoWeight);
    } else {
        newPlane = new PassengerPlane(id, manufacturer, brand, runwayLength, fuelPerKilometer, pilotCount, stewardCount,
                                      businessSeat,
                                      passengerSeat);
    }
    std::cout << newPlane << std::endl;
    return newPlane;
}

ResultCode appendPlanesToFile(const std::vector<Plane *> &planes) {
    std::fstream file;
    file.open(PLANE_FILE_PATH, std::fstream::app);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Plane *plane: planes) {
        file << plane;
    }

    file.close();

    return success;
}

ResultCode rewritePlanes(const std::vector<Plane> &planes) {
    std::ofstream file;
    file.open(PLANE_FILE_PATH);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Plane &plane: planes) {
        file << plane;
    }

    file.close();
    std::cout << "Planes are updated successfully." << std::endl;
    return success;
}
