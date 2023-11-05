#ifndef COURSEWORK_PLANE_H
#define COURSEWORK_PLANE_H

#include <iostream>

class Plane {
private:
    std::string id, manufacturer, brand;
    int runwayLength;
    double fuelPerKilometer;
    int pilotCount, stewardCount;

public:
    Plane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
          double fuelPerKilometer, int pilotCount, int stewardCount);

    Plane();

    virtual ~Plane();

    const std::string &getId() const;

    const std::string &getManufacturer() const;

    const std::string &getBrand() const;

    int getRunwayLength() const;

    void setRunwayLength(int runwayLength);

    double getFuelPerKilometer() const;

    void setFuelPerKilometer(double fuelPerKilometer);

    int getPilotCount() const;

    void setPilotCount(int pilotCount);

    int getStewardCount() const;

    void setStewardCount(int stewardCount);

    bool operator==(const Plane &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Plane &obj) {
        out << obj.id << "\n"
            << obj.manufacturer << "\n"
            << obj.brand << "\n"
            << obj.runwayLength << "\n"
            << obj.fuelPerKilometer << "\n"
            << obj.pilotCount << "\n"
            << obj.stewardCount << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Plane &obj) {
        std::string rl, fpk, pc, sc;
        in >> obj.id;
        in >> obj.manufacturer;
        in >> obj.brand;
        in >> rl;
        in >> fpk;
        in >> pc;
        in >> sc;

        obj.setRunwayLength(std::stoi(rl));
        obj.setFuelPerKilometer(std::stoi(fpk));
        obj.setStewardCount(std::stoi(sc));
        obj.setPilotCount(std::stoi(pc));
        return in;
    }
};

#endif //COURSEWORK_PLANE_H
