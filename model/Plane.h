#ifndef COURSEWORK_PLANE_H
#define COURSEWORK_PLANE_H

#include <string>
#include "submodels/Expenses.h"

using std::string;

class Plane {
private:
    string manufacturer, brand;
    int runwayLength;
    Expenses expenses;
};


#endif //COURSEWORK_PLANE_H
