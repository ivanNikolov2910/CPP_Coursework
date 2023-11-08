#ifndef COURSEWORK_PLANE_H
#define COURSEWORK_PLANE_H

#include <iostream>
#include <string>

class Plane {
private:
    std::string id, manufacturer, brand;
    int runwayLength;
    double fuelPerKilometer;
    int pilotCount, stewardCount;

public:
    Plane(const std::string &id, const std::string &manufacturer, const std::string &brand, int runwayLength,
          double fuelPerKilometer, int pilotCount, int stewardCount);

    // Plane();

    virtual ~Plane();

    const std::string &getId() const;

    void setId(const std::string& id);

    const std::string &getManufacturer() const;

    void setManufacturer(const std::string& manufacturer);

    const std::string &getBrand() const;

    void setBrand(const std::string& brand);

    int getRunwayLength() const;

    void setRunwayLength(int runwayLength);

    double getFuelPerKilometer() const;

    void setFuelPerKilometer(double fuelPerKilometer);

    int getPilotCount() const;

    void setPilotCount(int pilotCount);

    int getStewardCount() const;

    void setStewardCount(int stewardCount);

    virtual std::ostream& put(std::ostream&) const = 0;
    virtual std::istream& get(std::istream&) = 0;

    bool operator==(const Plane &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Plane &obj) {
        return obj.put(out);
    }

    friend std::istream &operator>>(std::istream &in, Plane &obj) {
        return obj.get(in);
    }
};

#endif //COURSEWORK_PLANE_H
