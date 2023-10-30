
#include "Staff.h"

Staff::Staff(const string &id, const string &name, const string &family, StaffPosition position, double salary) {
    Staff::id = id;
    Staff::name = name;
    Staff::family = family;
    Staff::position = position;
    Staff::salary = salary;
}

Staff::~Staff() {

}

const string &Staff::getId() const {
    return id;
}

void Staff::setId(const string &id) {
    Staff::id = id;
}

const string &Staff::getName() const {
    return name;
}

void Staff::setName(const string &name) {
    Staff::name = name;
}

const string &Staff::getFamily() const {
    return family;
}

void Staff::setFamily(const string &family) {
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
