#ifndef COURSEWORK_PLANE_H
#define COURSEWORK_PLANE_H

#include <string>
#include "submodels/Expenses.h"

using std::string;

class Plane {
private:
    string manufacturer, brand;
    int runwayLength;
    double fuelPerKilometer;

protected:
    Plane(const string &manufacturer, const string &brand, int runwayLength, double fuelPerKilometer);

    virtual ~Plane();

    const string &getManufacturer() const;

    void setManufacturer(const string &manufacturer);

    const string &getBrand() const;

    void setBrand(const string &brand);

    int getRunwayLength() const;

    void setRunwayLength(int runwayLength);

    double getFuelPerKilometer() const;

    void setFuelPerKilometer(double fuelPerKilometer);
};

#endif //COURSEWORK_PLANE_H
