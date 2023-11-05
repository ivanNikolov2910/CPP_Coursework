#include <string>
#include "../constants/constants.h"
#include "Flight.h"

Flight::Flight(Type type, std::string id, std::string destination, unsigned time, unsigned distance) {
    this->type = type;
    this->id = id;
    this->time = time;
    this->distance = distance;
    this->destination = destination;
}

Flight::Flight() {}

Flight::~Flight() {}

const std::string &Flight::getId() const {
    return id;
}

const std::string &Flight::getDestination() const {
    return destination;
}

void Flight::setDestination(const std::string &destination) {
    Flight::destination = destination;
}

unsigned int Flight::getTime() const {
    return time;
}

void Flight::setTime(unsigned int time) {
    Flight::time = time;
}

unsigned int Flight::getDistance() const {
    return distance;
}

Type Flight::getType() const {
    return type;
}

void Flight::setDistance(unsigned int distance) {
    Flight::distance = distance;
}

ResultCode validateDestination(const std::string& validateDestination) {
    if (std::regex_match(validateDestination, BASE_CITY_NAME)) {
        return success;
    }
    return validation_error;
}



