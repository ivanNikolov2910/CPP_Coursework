
#include "CargoPlane.h"

CargoPlane::CargoPlane(const string &manufacturer, const string &brand, int runwayLength, const Expenses &expenses,
                       int cargoWeight) : Plane(manufacturer, brand, runwayLength, expenses) {
    CargoPlane::cargoWeight = cargoWeight;
}

int CargoPlane::getCargoWeight() const {
    return cargoWeight;
}

void CargoPlane::setCargoWeight(int cargoWeight) {
    CargoPlane::cargoWeight = cargoWeight;
}
