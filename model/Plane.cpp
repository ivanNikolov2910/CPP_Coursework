#include <string>
#include "Plane.h"

Plane::Plane() {}

Plane::~Plane() {}

const std::string &Plane::getManufacturer() const {
    return manufacturer;
}

const std::string &Plane::getBrand() const {
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

const std::string &Plane::getId() const {
    return Plane::id;
}

Plane::Plane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
             double fuelPerKilometer, int pilotCount, int stewardCount) : id(id), manufacturer(manufacturer),
                                                                          brand(brand), runwayLength(runwayLength),
                                                                          fuelPerKilometer(fuelPerKilometer),
                                                                          pilotCount(pilotCount),
                                                                          stewardCount(stewardCount) {}

int Plane::getPilotCount() const {
    return pilotCount;
}

void Plane::setPilotCount(int pilotCount) {
    Plane::pilotCount = pilotCount;
}

int Plane::getStewardCount() const {
    return stewardCount;
}

void Plane::setStewardCount(int stewardCount) {
    Plane::stewardCount = stewardCount;
}
