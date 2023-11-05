#ifndef COURSEWORK_CARGOPLANE_H
#define COURSEWORK_CARGOPLANE_H

#include <iostream>
#include "Plane.h"

class CargoPlane : public Plane {
private:
    int cargoWeight;
public:
    CargoPlane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
               double fuelPerKilometer, int cargoWeight);

    int getCargoWeight() const;

    void setCargoWeight(int cargoWeight);

    friend std::ostream &operator<<(std::ostream &out, const CargoPlane &obj) {
        out << static_cast<const Plane &>(obj) << "\n"
            << obj.cargoWeight;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, CargoPlane &obj) {
        std::string cw;
        in >> static_cast<Plane &>(obj);
        in >> cw;
        obj.setCargoWeight(std::stoi(cw));
        return in;
    }
};


#endif //COURSEWORK_CARGOPLANE_H
