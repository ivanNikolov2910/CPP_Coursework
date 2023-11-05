#include <string>
#include "CargoPlane.h"

CargoPlane::CargoPlane(const std::string &id, const std::string &manufacturer, const std::string &brand,
                       int runwayLength,
                       double fuelPerKilometer, int cargoWeight) {
    Plane(id, manufacturer, brand, runwayLength, fuelPerKilometer);
    CargoPlane::cargoWeight = cargoWeight;
}

int CargoPlane::getCargoWeight() const {
    return cargoWeight;
}

void CargoPlane::setCargoWeight(int cargoWeight) {
    CargoPlane::cargoWeight = cargoWeight;
}


