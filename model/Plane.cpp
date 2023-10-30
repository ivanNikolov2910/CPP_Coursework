#include "Plane.h"

Plane::Plane(const string &manufacturer, const string &brand, int runwayLength, double fuelPerKilometer) {
    Plane::manufacturer = manufacturer;
    Plane::brand = brand;
    Plane::runwayLength = runwayLength;
    Plane::fuelPerKilometer = fuelPerKilometer;
}

Plane::Plane() {}

Plane::~Plane() {}

const string &Plane::getManufacturer() const {
    return manufacturer;
}

void Plane::setManufacturer(const string &manufacturer) {
    Plane::manufacturer = manufacturer;
}

const string &Plane::getBrand() const {
    return brand;
}

void Plane::setBrand(const string &brand) {
    Plane::brand = brand;
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

int Plane::getCargoWeight() const {
    return cargoWeight;
}

void Plane::setCargoWeight(int cargoWeight) {
    Plane::cargoWeight = cargoWeight;
}

int Plane::getBusinessSeats() const {
    return businessSeats;
}

void Plane::setBusinessSeats(int businessSeats) {
    Plane::businessSeats = businessSeats;
}

int Plane::getPassengerSeats() const {
    return passengerSeats;
}

void Plane::setPassengerSeats(int passengerSeats) {
    Plane::passengerSeats = passengerSeats;
}

const string &Plane::getId() const {
    return Plane::id;
}

