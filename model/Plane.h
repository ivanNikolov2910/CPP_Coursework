#ifndef COURSEWORK_PLANE_H
#define COURSEWORK_PLANE_H

#include <string>
#include "submodels/Expenses.h"

using std::string;

class Plane {
private:
    string id, manufacturer, brand;
    int runwayLength;
    double fuelPerKilometer;

    int businessSeats, passengerSeats;
    int cargoWeight;

public:
    Plane(const string &id, const string &manufacturer, const string &brand, int runwayLength, double fuelPerKilometer)
            : id(id), manufacturer(manufacturer), brand(brand), runwayLength(runwayLength),
              fuelPerKilometer(fuelPerKilometer) {}

    Plane();

    virtual ~Plane();

    const string &getId() const;

    const string &getManufacturer() const;

    void setManufacturer(const string &manufacturer);

    const string &getBrand() const;

    void setBrand(const string &brand);

    int getRunwayLength() const;

    void setRunwayLength(int runwayLength);

    double getFuelPerKilometer() const;

    void setFuelPerKilometer(double fuelPerKilometer);

    int getBusinessSeats() const;

    void setBusinessSeats(int businessSeats);

    int getPassengerSeats() const;

    void setPassengerSeats(int passengerSeats);

    int getCargoWeight() const;

    void setCargoWeight(int cargoWeight);

    bool operator==(const Plane &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Plane &obj) {
        out << obj.id << "\n"
            << obj.manufacturer << "\n"
            << obj.brand << "\n"
            << obj.fuelPerKilometer << "\n"
            << obj.cargoWeight << "\n"
            << obj.passengerSeats << "\n"
            << obj.businessSeats << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Plane &obj) {
        in >> obj.id;
        in >> obj.manufacturer;
        in >> obj.brand;
        in >> obj.fuelPerKilometer;
        in >> obj.cargoWeight;
        in >> obj.passengerSeats;
        in >> obj.businessSeats;

        return in;
    }
};

#endif //COURSEWORK_PLANE_H
