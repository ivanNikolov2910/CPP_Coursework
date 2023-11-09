#include "CargoPlane.h"

CargoPlane::CargoPlane(const std::string &id, const std::string &manufacturer, const std::string &brand,
                       int runwayLength,
                       double fuelPerKilometer, int pilotCount, int stewardCount, int cargoWeight)
        : Plane(id, manufacturer, brand, runwayLength, fuelPerKilometer, pilotCount, stewardCount) {
    CargoPlane::cargoWeight = cargoWeight;
}

CargoPlane::~CargoPlane() {}

int CargoPlane::getCargoWeight() const {
    return cargoWeight;
}

void CargoPlane::setCargoWeight(int cargoWeight) {
    CargoPlane::cargoWeight = cargoWeight;
}

std::ostream &CargoPlane::put(std::ostream &out) const {
    out << cargo << "\n"
        << getId() << "\n"
        << getManufacturer() << "\n"
        << getBrand() << "\n"
        << getRunwayLength() << "\n"
        << getFuelPerKilometer() << "\n"
        << getPilotCount() << "\n"
        << getStewardCount() << "\n"
        << getCargoWeight() << "\n";
    return out;
}

std::istream &CargoPlane::get(std::istream &in) {
    std::string id, manuf, brand, rLength, fPerKilo, pCnt, sCnt;
    std::string maxWeigth;

    in >> id;
    in >> manuf;
    in >> brand;
    in >> rLength;
    in >> fPerKilo;
    in >> pCnt;
    in >> sCnt;

    CargoPlane::setId(id);
    CargoPlane::setManufacturer(manuf);
    CargoPlane::setBrand(brand);
    CargoPlane::setRunwayLength(std::stoi(rLength));
    CargoPlane::setFuelPerKilometer(std::stoi(fPerKilo));
    CargoPlane::setPilotCount(std::stoi(pCnt));
    CargoPlane::setStewardCount(std::stoi(sCnt));

    in >> maxWeigth;
    CargoPlane::setCargoWeight(std::stoi(maxWeigth));
    return in;
}
