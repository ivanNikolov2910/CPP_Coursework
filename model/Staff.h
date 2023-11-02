
#ifndef COURSEWORK_STAFF_H
#define COURSEWORK_STAFF_H

#include <string>
#include <ostream>

using std::string;

enum StaffPosition {
    pilot = 0, steward = 1
};

class Staff {
private:
    string id, name, family;
    StaffPosition position;
    double salary;

public:
    Staff(const string &id, const string &name, const string &family, StaffPosition position, double salary);

    Staff();

    virtual ~Staff();

    const string &getId() const;

    void setId(const string &id);

    const string &getName() const;

    void setName(const string &name);

    const string &getFamily() const;

    void setFamily(const string &family);

    StaffPosition getPosition() const;

    void setPosition(StaffPosition position);

    double getSalary() const;

    void setSalary(double salary);

    bool operator==(const Staff &other) const {
        return id == other.id;
    }

    friend std::ostream &operator<<(std::ostream &out, const Staff &obj) {
        out << obj.id << "\n"
            << obj.name << "\n"
            << obj.family << "\n"
            << obj.position << "\n"
            << obj.salary;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Staff &obj) {
        int position;

        in >> obj.id;
        in >> obj.name;
        in >> obj.family;
        in >> position;
        in >> obj.salary;

        obj.setPosition(static_cast<StaffPosition>(position));

        return in;
    }

};


#endif //COURSEWORK_STAFF_H
