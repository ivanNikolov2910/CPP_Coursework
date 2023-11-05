
#ifndef COURSEWORK_STAFF_H
#define COURSEWORK_STAFF_H

#include <iostream>

enum StaffPosition {
    pilot = 0, steward = 1
};

class Staff {
private:
    std::string id, name, family;
    StaffPosition position;
    double salary;

public:
    Staff(const std::string &id, const std::string &name, const std::string &family, StaffPosition position, double salary);

    Staff();

    virtual ~Staff();

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getFamily() const;

    void setFamily(const std::string &family);

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
