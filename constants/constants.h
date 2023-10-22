#ifndef COURSEWORK_CONSTANTS_H
#define COURSEWORK_CONSTANTS_H

#include <regex>
#include <string>

using std::regex, std::string;

const regex FLIGHT_ID_PATTER("[A-Z]{3}[0-9]{4,6}[A-Z]{3}");
const string FLIGHT_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\flights)";


enum ResultCode {
    success, validation_error, internal_error
};

#endif
