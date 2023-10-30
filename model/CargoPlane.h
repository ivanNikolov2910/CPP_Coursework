
#ifndef COURSEWORK_CARGOPLANE_H
#define COURSEWORK_CARGOPLANE_H

#include "Plane.h"
#include <iostream>

class CargoPlane : public Plane {
private:
    int cargoWeight;

public:
    CargoPlane(const string &manufacturer, const string &brand, int runwayLength, const Expenses &expenses,
               int cargoWeight);

    int getCargoWeight() const;

    void setCargoWeight(int cargoWeight);

    friend std::ostream &operator<<(std::ostream &out, const CargoPlane &obj) {
        out << obj.getManufacturer() << "\n"
            << obj.getBrand() << "\n"
            << obj.getRunwayLength() << "\n"
            << obj.getExpenses() << "\n"
            << obj.cargoWeight << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, CargoPlane &obj) {
        string manufacturer, brand;
        int runwayLength;
        Expenses expenses;
        in >> manufacturer;
        in >> brand;
        in >> runwayLength;
        in >> expenses;
        in >> obj.cargoWeight;

        obj.setManufacturer(manufacturer);
        obj.setBrand(brand);
        obj.setRunwayLength(runwayLength);
        obj.setExpenses(expenses);

        return in;
    }
};


#endif //COURSEWORK_CARGOPLANE_H
