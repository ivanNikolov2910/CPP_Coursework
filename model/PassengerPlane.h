//
// Created by ivann on 11/2/2023.
//

#ifndef COURSEWORK_PASSENGERPLANE_H
#define COURSEWORK_PASSENGERPLANE_H


#include <ostream>
#include "Plane.h"

class PassengerPlane : public Plane {
private:
    int businessSeat, passengerSeat;

public:
    PassengerPlane(const string &id, const string &manufacturer, const string &brand, int runwayLength,
                   double fuelPerKilometer, int businessSeat, int passengerSeat);

    int getBusinessSeat() const;

    void setBusinessSeat(int businessSeat);

    int getPassengerSeat() const;

    void setPassengerSeat(int passengerSeat);

    friend std::ostream &operator<<(std::ostream &out, const PassengerPlane &obj) {
        out << static_cast<const Plane &>(obj) << "\n"
            << obj.businessSeat << "\n"
            << obj.passengerSeat;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, PassengerPlane &obj) {
        string bs, ps;
        in >> static_cast<Plane &>(obj);
        in >> bs;
        in >> ps;
        obj.setBusinessSeat(std::stoi(bs));
        obj.setPassengerSeat(std::stoi(ps));
        return in;
    }
};


#endif //COURSEWORK_PASSENGERPLANE_H
