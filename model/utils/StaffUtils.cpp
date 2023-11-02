#include <fstream>
#include <vector>
#include <iostream>
#include "../Staff.h"
#include "../../constants/constants.h"

Staff readStaffData(const std::vector<Staff> &);

ResultCode appendStaffToFile(const std::vector<Staff> &);

ResultCode updateStaffData(Staff &);

ResultCode rewriteStaff(const std::vector<Staff> &staff) {
    std::ofstream file;
    file.open(STAFF_FILE_PATH);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Staff &s: staff) {
        file << s;
    }

    file.close();
    std::cout << "Flights updated successfully." << std::endl;
    return success;
}


ResultCode ListStaff(std::vector<Staff> *staff) {
    std::ifstream file(STAFF_FILE_PATH);
    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    Staff newStaff;
    while (file >> newStaff) {
        staff->push_back(newStaff);
    }

    return success;
}

ResultCode CreateStaff(unsigned count) {
    std::vector<Staff> staff;
    ResultCode res = ListStaff(&staff);
    if (res != success) {
        std::cout << "Could not fetch flights" << std::endl;
    }

    for (unsigned i = 0; i < count; ++i) {
        Staff newStaff = readStaffData(staff);
        staff.push_back(newStaff);
    }

    if (appendStaffToFile(staff) != success) {
        std::cout << "Failed to write staff to the file." << std::endl;
        return internal_error;
    }

    std::cout << "Staff added successfully." << std::endl;
    return success;
}

ResultCode UpdateStaff(const string &id) {
    std::vector<Staff> staff;
    ResultCode res = ListStaff(&staff);
    if (res != success) {
        std::cout << "Failed to list staff" << std::endl;
        return internal_error;
    }

    Staff *staffToUpdate;
    for (Staff &s: staff) {
        if (s.getId() == id) {
            staffToUpdate = &s;
        }
    }

    if (staffToUpdate == nullptr) {
        std::cout << "Staff with ID " << id << " not found." << std::endl;
        return not_found_error;
    }

    if (updateStaffData(*staffToUpdate) != success) {
        std::cout << "Update failed." << std::endl;
        return validation_error;
    }

    return rewriteStaff(staff);
}

ResultCode DeleteStaff(const string &id) {
    std::vector<Staff> staff;
    ResultCode res = ListStaff(&staff);
    if (res != success) {
        std::cout << "Failed to fetch staff" << std::endl;
        return internal_error;
    }

    int toDelete = -1;
    for (int i = 0; i < staff.capacity(); ++i) {
        if (staff.at(i).getId() == id) {
            toDelete = i;
            break;
        }
    }

    std::cout << toDelete;
    if (toDelete != -1) {
        staff.erase(staff.begin() + toDelete);
        return rewriteStaff(staff);
    }
    std::cout << "Could not find staff with id: " << id << std::endl;
    return internal_error;
}


Staff readStaffData(const std::vector<Staff> &staff) {
    std::string id, name, family;
    double salary;
    StaffPosition position;

    while (true) {
        std::cout << "Enter staff id: ";
        std::cin >> id;

        bool shouldRestart = false;
        for (const Staff &s: staff) {
            if (s.getId() == id) {
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

    while (true) {
        int userInput;
        std::cout << "Enter a position (0 - pilot, 1 - steward): ";
        std::cin >> userInput;

        if (userInput == 1 || userInput == 2) {
            position = static_cast<StaffPosition>(userInput);
            break;
        }
        std::cout << "Invalid input for position!" << std::endl;
    }

    std::cout << "Enter first name: ";
    std::cin >> name;

    std::cout << "Enter last name: ";
    std::cin >> family;

    std::cout << "Enter salary: ";
    std::cin >> salary;

    return *new Staff(id, name, family, position, salary);
}

ResultCode appendStaffToFile(const std::vector<Staff> &staff) {
    std::fstream file;
    file.open(STAFF_FILE_PATH, std::fstream::app);

    if (!file) {
        std::cout << "Failed to open the file." << std::endl;
        return internal_error;
    }

    for (const Staff &s: staff) {
        file << s;
    }

    file.close();

    return success;
}

ResultCode updateStaffData(Staff &staff) {
    char cmd;
    double salary;
    int position;

    std::cout << "Enter field index to update: " << "\n"
              << "1. Salary" << "\n"
              << "2. Position" << "\n"
              << "3. Discard changes" << "\n";
    std::cin >> cmd;

    switch (cmd) {
        case '1':
            std::cin >> salary;
            staff.setSalary(salary);
            break;
        case '2':
            std::cin >> position;
            staff.setPosition(static_cast<StaffPosition>(position));
            break;
        case '3':
            return success;
        default:
            std::cout << "Invalid operation index, update staff" << std::endl;
            return validation_error;
    }

    return success;
}
