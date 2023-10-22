#ifndef COURSEWORK_FLIGHT_H
#define COURSEWORK_FLIGHT_H

#include <string>
#include <regex>
#include <iostream>
#include "../constants/constants.h"

using std::string, std::regex;

ResultCode validateId(string validateId);

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

    virtual ~Flight();

    friend ResultCode validateId(string validateId);

    const string &getId() const;

    const string &getDestination() const;

    void setDestination(const string &destination);

    unsigned int getTime() const;

    void setTime(unsigned int time);

    unsigned int getDistance() const;

    Type getType() const;

    bool operator==(const Flight &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Flight &obj) {
        out << obj.id << "\n" << obj.type << "\n" << obj.destination << obj.time << "\n" << obj.distance << std::endl;
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
