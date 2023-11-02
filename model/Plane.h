#ifndef COURSEWORK_PLANE_H
#define COURSEWORK_PLANE_H

#include <string>

using std::string;

class Plane {
private:
    string id, manufacturer, brand;
    int runwayLength;
    double fuelPerKilometer;

public:
    Plane(const string &id, const string &manufacturer, const string &brand, int runwayLength, double fuelPerKilometer)
            : id(id), manufacturer(manufacturer), brand(brand), runwayLength(runwayLength),
              fuelPerKilometer(fuelPerKilometer) {}

    Plane();

    virtual ~Plane();

    const string &getId() const;

    const string &getManufacturer() const;

    const string &getBrand() const;

    int getRunwayLength() const;

    void setRunwayLength(int runwayLength);

    double getFuelPerKilometer() const;

    void setFuelPerKilometer(double fuelPerKilometer);

    bool operator==(const Plane &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Plane &obj) {
        out << obj.id << "\n"
            << obj.manufacturer << "\n"
            << obj.brand << "\n"
            << obj.runwayLength << "\n"
            << obj.fuelPerKilometer << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Plane &obj) {
        string rl, fpk;
        in >> obj.id;
        in >> obj.manufacturer;
        in >> obj.brand;
        in >> rl;
        in >> fpk;

        obj.setRunwayLength(std::stoi(rl));
        obj.setFuelPerKilometer(std::stoi(fpk));
        return in;
    }
};

#endif //COURSEWORK_PLANE_H
