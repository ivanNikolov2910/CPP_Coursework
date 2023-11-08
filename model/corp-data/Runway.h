
#ifndef COURSEWORK_RUNWAY_H
#define COURSEWORK_RUNWAY_H

#include <iostream>

class Runway {
private:
    std::string id;
    int length;

public:
    Runway(const std::string &id, int length);

    virtual ~Runway();

    const std::string &getId() const;

    void setId(const std::string &id);

    int getLength() const;

    void setLength(int length);

    bool operator==(const Runway &other) const {
        return id == other.id;
    }

    bool operator<(const Runway &other) const {
        return length < other.length;
    }

    friend std::ostream &operator<<(std::ostream &out, const Runway &obj) {
        out << obj.id << "\n"
            << obj.length << "\n";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Runway &obj) {
        in >> obj.id;
        in >> obj.length;
        return in;
    }
};


#endif //COURSEWORK_RUNWAY_H