#ifndef COURSEWORK_STAFFUTILS_H
#define COURSEWORK_STAFFUTILS_H


#include <fstream>
#include "../corp-data/Staff.h"
#include "../../constants/constants.h"


Staff readStaffData(const std::vector<Staff> &);

ResultCode appendStaffToFile(const std::vector<Staff> &);

ResultCode updateStaffData(Staff &);

ResultCode rewriteStaff(const std::vector<Staff> &);


ResultCode ListStaff(std::vector<Staff> &);

ResultCode CreateStaff(unsigned);

ResultCode UpdateStaff(const std::string &id);

ResultCode DeleteStaff(const std::string &id);

#endif
