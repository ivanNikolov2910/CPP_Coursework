#include "Flight.h"
#include "../constants/constants.h"

Flight::Flight(Type type, string id, string destination, unsigned time, unsigned distance) {
    this->type = type;
    this->id = id;
    this->time = time;
    this->distance = distance;
    this->destination = destination;
}

Flight::Flight() {

}

Flight::~Flight() {

}

const string &Flight::getId() const {
    return id;
}

const string &Flight::getDestination() const {
    return destination;
}

void Flight::setDestination(const string &destination) {
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

ResultCode validateDestination(string validateDestination) {
    if (std::regex_match(validateDestination, BASE_CITY_NAME)) {
        return success;
    }
    return validation_error;
}



