#ifndef COURSEWORK_FLIGHT_H
#define COURSEWORK_FLIGHT_H

#include <string>
#include "../../constants/constants.h"

ResultCode validateDestination(const std::string &);

enum Type {
    cargo = 0,
    passenger = 1,
};

class Flight {
private:
    std::string id, destination;
    unsigned time{}, distance{};
    Type type;
public:
    Flight(Type type, const std::string &id, const std::string &destination, unsigned time, unsigned distance);

    Flight() = default;

    virtual ~Flight();

    friend ResultCode validateDestination(const std::string &);

    const std::string &getId() const;

    const std::string &getDestination() const;

    void setDestination(const std::string &destination);

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
