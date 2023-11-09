#include "../RunwayUtils.h"

ResultCode ListRunway(std::vector<Runway> &runway) {
    std::ifstream file(RUNWAY_FILE_PATH);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    Runway *newRunway = new Runway();
    while (file >> *newRunway) {
        runway.push_back(*newRunway);
    }

    return success;
}

ResultCode CreateRunway() {
    std::vector<Runway> runway;
    ResultCode res = ListRunway(runway);
    if (res != success) {
        std::cout << "Could not fetch runways" << std::endl;
    }

    Runway newRunway = readRunwayData(runway);
    runway.push_back(newRunway);

    if (appendRunwayToFile(runway) != success) {
        std::cout << "Failed to write runway to the file." << std::endl;
        return internal_error;
    }

    std::cout << "Runway added successfully." << std::endl;
    return success;
}

ResultCode DeleteRunway(const std::string &id) {
    std::vector<Runway> runway;
    ResultCode res = ListRunway(runway);
    if (res != success) {
        std::cout << "Failed to fetch staff" << std::endl;
        return internal_error;
    }

    int toDelete = -1;
    for (int i = 0; i < runway.capacity(); ++i) {
        if (runway.at(i).getId() == id) {
            toDelete = i;
            break;
        }
    }

    std::cout << toDelete;
    if (toDelete != -1) {
        runway.erase(runway.begin() + toDelete);
        return rewriteRunway(runway);
    }
    std::cout << "Could not find runway with id: " << id << std::endl;
    return internal_error;
}

ResultCode rewriteRunway(const std::vector<Runway> &runway) {
    std::ofstream file;
    file.open(RUNWAY_FILE_PATH);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Runway &s: runway) {
        file << s;
    }

    file.close();
    std::cout << "Flights updated successfully." << std::endl;
    return success;
}


Runway readRunwayData(const std::vector<Runway> &runway) {
    std::string id;
    int length;

    while (true) {
        std::cout << "Enter runway id: ";
        std::cin >> id;

        bool shouldRestart = false;
        for (const Runway &r: runway) {
            if (r.getId() == id) {
                std::cout << "Staff id already exists" << std::endl;
                shouldRestart = true;
                break;
            }
        }

        if (shouldRestart) {
            continue;
        }
        break;
    }

    std::cout << "Enter runway length: ";
    std::cin >> length;


    return *new Runway(id, length);
}

ResultCode appendRunwayToFile(const std::vector<Runway> &runway) {
    std::fstream file;
    file.open(RUNWAY_FILE_PATH, std::fstream::app);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Runway &r: runway) {
        file << r;
    }

    file.close();

    return success;
}

ResultCode updateRunwayData(Runway &runway) {
    char cmd;
    std::string id;
    int length;

    std::cout << "Enter field index to update: " << "\n"
              << "1. Id" << "\n"
              << "2. Length" << "\n"
              << "3. Discard changes" << "\n";
    std::cin >> cmd;

    switch (cmd) {
        case '1':
            std::cin >> id;
            runway.setId(id);
            break;
        case '2':
            std::cin >> length;
            runway.setLength(length);
            break;
        case '3':
            return success;
        default:
            std::cout << "Invalid operation index, update staff" << std::endl;
            return validation_error;
    }

    return success;
}