//
// Created by ivann on 11/2/2023.
//

#ifndef COURSEWORK_CARGOPLANE_H
#define COURSEWORK_CARGOPLANE_H

#include <ostream>
#include "Plane.h"

class CargoPlane : public Plane {
private:
    int cargoWeight;
public:
    CargoPlane(const string &id, const string &manufacturer, const string &brand, int runwayLength,
               double fuelPerKilometer, int cargoWeight);

    int getCargoWeight() const;

    void setCargoWeight(int cargoWeight);

    friend std::ostream &operator<<(std::ostream &out, const CargoPlane &obj) {
        out << static_cast<const Plane &>(obj) << "\n"
            << obj.cargoWeight;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, CargoPlane &obj) {
        string cw;
        in >> static_cast<Plane &>(obj);
        in >> cw;
        obj.setCargoWeight(std::stoi(cw));
        return in;
    }
};


#endif //COURSEWORK_CARGOPLANE_H
