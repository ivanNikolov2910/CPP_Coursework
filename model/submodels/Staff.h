
#ifndef COURSEWORK_STAFF_H
#define COURSEWORK_STAFF_H

#include <string>

using std::string;

enum StaffPosition{
    pilot, steward
};

class Staff {
private:
    string id, name, family;
    StaffPosition position;
    double salary;

public:
    Staff(const string &id, const string &name, const string &family, StaffPosition position, double salary);
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
};


#endif //COURSEWORK_STAFF_H
