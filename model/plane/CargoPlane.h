#ifndef COURSEWORK_CARGOPLANE_H
#define COURSEWORK_CARGOPLANE_H

#include "Plane.h"

class CargoPlane : public Plane {
private:
    int cargoWeight{};

public:
    CargoPlane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
               double fuelPerKilometer, int pilotCount, int stewardCount, int cargoWeight);

    CargoPlane() = default;

    ~CargoPlane() override;

    int getCargoWeight() const;

    void setCargoWeight(int cargoWeight);

    std::ostream &put(std::ostream &out) const override;

    std::istream &get(std::istream &in) override;
};

#endif // COURSEWORK_CARGOPLANE_H
