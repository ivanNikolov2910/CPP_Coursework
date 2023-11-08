#include <string>
#include "PassengerPlane.h"

PassengerPlane::PassengerPlane(const std::string &id, const std::string &manufacturer, const std::string &brand,
                               int runwayLength,
                               double fuelPerKilometer, int pilotCount, int stewardCount, int businessSeat,
                               int passengerSeat)
        : Plane(id, manufacturer, brand, runwayLength, fuelPerKilometer, pilotCount, stewardCount) {

    PassengerPlane::businessSeat = businessSeat;
    PassengerPlane::passengerSeat = passengerSeat;
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

std::ostream &PassengerPlane::put(std::ostream &out) const {
    out << getId() << "\n"
        << getManufacturer() << "\n"
        << getBrand() << "\n"
        << getRunwayLength() << "\n"
        << getFuelPerKilometer() << "\n"
        << getPilotCount() << "\n"
        << getStewardCount() << "\n"
        << getBusinessSeat() << "\n"
        << getPassengerSeat();
    return out;
}

std::istream &PassengerPlane::get(std::istream &in) {
    std::string id, manuf, brand, rLength, fPerKilo, pCnt, sCnt;
    std::string bs, ps;

    in >> id;
    in >> manuf;
    in >> brand;
    in >> rLength;
    in >> fPerKilo;
    in >> pCnt;
    in >> sCnt;

    PassengerPlane::setId(id);
    PassengerPlane::setManufacturer(manuf);
    PassengerPlane::setBrand(brand);
    PassengerPlane::setFuelPerKilometer(std::stoi(fPerKilo));
    PassengerPlane::setPilotCount(std::stoi(pCnt));
    PassengerPlane::setStewardCount(std::stoi(sCnt));

    in >> bs;
    in >> ps;
    PassengerPlane::setBusinessSeat(std::stoi(bs));
    PassengerPlane::setPassengerSeat(std::stoi(ps));

    return in;
}
