#include "../RunwayUtils.h"


ResultCode ListRunway(std::vector<Runway> &runways) {
    std::ifstream file(RUNWAY_FILE_PATH);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    Runway newRunway;
    while (file >> newRunway) {
        runways.push_back(newRunway);
    }
    file.close();
    return success;
}

ResultCode CreateRunway() {
    std::vector<Runway> runways;
    ResultCode res = ListRunway(runways);
    if (res != success) {
        std::cout << "Could not fetch runways" << std::endl;
        return internal_error;
    }

    Runway newRunway = readRunwayData(runways);
    runways.push_back(newRunway);

    res = appendRunwayToFile(runways);
    if (res != success) {
        std::cout << "Failed to write runway to the file." << std::endl;
        return internal_error;
    }

    std::cout << "Runway added successfully." << std::endl;
    return success;
}

ResultCode DeleteRunway(const std::string &id) {
    std::vector<Runway> runways;
    ResultCode res = ListRunway(runways);
    if (res != success) {
        std::cout << "Failed to fetch runways" << std::endl;
        return internal_error;
    }

    auto it = std::find_if(runways.begin(), runways.end(),
                           [&id](const Runway &r) {
                               return r.getId() == id;
                           });

    if (it != runways.end()) {
        runways.erase(it);
        return rewriteRunway(runways);
    }

    std::cout << "Could not find runway with id: " << id << std::endl;
    return not_found_error;
}

ResultCode rewriteRunway(const std::vector<Runway> &runways) {
    std::ofstream file;
    file.open(RUNWAY_FILE_PATH);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Runway &r: runways) {
        file << r;
    }

    file.close();
    std::cout << "Runways updated successfully." << std::endl;
    return success;
}

Runway readRunwayData(const std::vector<Runway> &runways) {
    std::string id;
    int length;

    while (true) {
        std::cout << "Enter runway id: ";
        std::cin >> id;

        if (std::find_if(runways.begin(), runways.end(),
                         [&id](const Runway &r) {
                             return r.getId() == id;
                         }) != runways.end()) {
            std::cout << "Runway id already exists" << std::endl;
        } else {
            break;
        }
    }

    std::cout << "Enter runway length: ";
    std::cin >> length;

    return {id, length};
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
