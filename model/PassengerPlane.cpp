#include <string>
#include "PassengerPlane.h"

PassengerPlane::PassengerPlane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
                               double fuelPerKilometer, int businessSeat, int passengerSeat) {
    Plane(id, manufacturer, brand, runwayLength, fuelPerKilometer);
    this->businessSeat = businessSeat;
    this->passengerSeat = passengerSeat;
}

int PassengerPlane::getBusinessSeat() const {
    return businessSeat;
}

void PassengerPlane::setBusinessSeat(int businessSeat) {
    PassengerPlane::businessSeat = businessSeat;
}

int PassengerPlane::getPassengerSeat() const {
    return passengerSeat;
}

void PassengerPlane::setPassengerSeat(int passengerSeat) {
    PassengerPlane::passengerSeat = passengerSeat;
}


