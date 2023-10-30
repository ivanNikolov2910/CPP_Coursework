#ifndef COURSEWORK_CONSTANTS_H
#define COURSEWORK_CONSTANTS_H

#include <regex>
#include <string>

using std::regex, std::string;

const regex FLIGHT_ID_PATTER("[A-Z]{3}[0-9]{4,6}[A-Z]{3}");
const regex BASE_CITY_NAME("^(?:[A-Z][a-z]*[\\s-]?){1,3}(?:[A-Z][a-z]*)?$");
const string FLIGHT_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\flights)";
const string PLANE_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\planes)";
const string RUNWAY_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\runways)";


enum ResultCode {
    success, validation_error, internal_error, not_found_error
};

#endif
