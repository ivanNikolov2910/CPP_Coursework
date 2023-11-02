#include "Plane.h"

Plane::Plane() {}

Plane::~Plane() {}

const string &Plane::getManufacturer() const {
    return manufacturer;
}

const string &Plane::getBrand() const {
    return brand;
}

int Plane::getRunwayLength() const {
    return runwayLength;
}

void Plane::setRunwayLength(int runwayLength) {
    Plane::runwayLength = runwayLength;
}

double Plane::getFuelPerKilometer() const {
    return fuelPerKilometer;
}

void Plane::setFuelPerKilometer(double fuelPerKilometer) {
    Plane::fuelPerKilometer = fuelPerKilometer;
}

const string &Plane::getId() const {
    return Plane::id;
}
