#ifndef COURSEWORK_PASSENGERPLANE_H
#define COURSEWORK_PASSENGERPLANE_H

#include "Plane.h"

class PassengerPlane : public Plane {
private:
    int businessSeat{}, passengerSeat{};

public:
    PassengerPlane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
                   double fuelPerKilometer, int pilotCount, int stewardCount, int businessSeat, int passengerSeat);

    PassengerPlane() = default;

    ~PassengerPlane() override;

    int getBusinessSeat() const;

    void setBusinessSeat(int businessSeat);

    int getPassengerSeat() const;

    void setPassengerSeat(int passengerSeat);

    std::ostream &put(std::ostream &out) const override;

    std::istream &get(std::istream &in) override;
};

#endif // COURSEWORK_PASSENGERPLANE_H
