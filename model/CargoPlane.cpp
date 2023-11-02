//
// Created by ivann on 11/2/2023.
//

#include "CargoPlane.h"

CargoPlane::CargoPlane(const string &id, const string &manufacturer, const string &brand, int runwayLength,
                       double fuelPerKilometer, int cargoWeight) : Plane(id, manufacturer, brand, runwayLength,
                                                                         fuelPerKilometer), cargoWeight(cargoWeight) {}

int CargoPlane::getCargoWeight() const {
    return cargoWeight;
}

void CargoPlane::setCargoWeight(int cargoWeight) {
    CargoPlane::cargoWeight = cargoWeight;
}


