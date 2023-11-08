#include <string>
#include "Staff.h"

Staff::Staff(const std::string &id, const std::string &name, const std::string &family, StaffPosition position,
             double salary) {
    Staff::id = id;
    Staff::name = name;
    Staff::family = family;
    Staff::position = position;
    Staff::salary = salary;
}

Staff::~Staff() = default;

const std::string &Staff::getId() const {
    return id;
}

void Staff::setId(const std::string &id) {
    Staff::id = id;
}

const std::string &Staff::getName() const {
    return name;
}

void Staff::setName(const std::string &name) {
    Staff::name = name;
}

const std::string &Staff::getFamily() const {
    return family;
}

void Staff::setFamily(const std::string &family) {
    Staff::family = family;
}

StaffPosition Staff::getPosition() const {
    return position;
}

void Staff::setPosition(StaffPosition position) {
    Staff::position = position;
}

double Staff::getSalary() const {
    return salary;
}

void Staff::setSalary(double salary) {
    Staff::salary = salary;
}



