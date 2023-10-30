#ifndef COURSEWORK_FLIGHT_H
#define COURSEWORK_FLIGHT_H

#include <string>
#include <regex>
#include <iostream>
#include "../constants/constants.h"
#include "./utils/Validation.cpp"

using std::string, std::regex;

ResultCode validateDestination(string);

enum Type {
    cargo = 0,
    passenger = 1,
};

class Flight {
private:
    string id, destination;
    unsigned time, distance;
    Type type;


public:
    Flight(Type type, string id, string destination, unsigned time, unsigned distance);

    Flight();

    virtual ~Flight();

    friend ResultCode validateDestination(string);

    const string &getId() const;

    const string &getDestination() const;

    void setDestination(const string &destination);

    unsigned int getTime() const;

    void setTime(unsigned int time);

    unsigned int getDistance() const;

    void setDistance(unsigned int distance);

    Type getType() const;

    bool operator==(const Flight &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Flight &obj) {
        out << obj.id << "\n"
            << obj.type << "\n"
            << obj.destination << "\n"
            << obj.time << "\n"
            << obj.distance << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Flight &obj) {
        int typeNum;
        in >> obj.id;
        in >> typeNum;
        in >> obj.destination;
        in >> obj.time;
        in >> obj.distance;

        obj.type = static_cast<Type>(typeNum);

        return in;
    }

};


#endif //COURSEWORK_FLIGHT_H
