#ifndef COURSEWORK_CONSTANTS_H
#define COURSEWORK_CONSTANTS_H

#include <regex>

const std::regex FLIGHT_ID_PATTER("[A-Z]{3}[0-9]{4,6}[A-Z]{3}");
const std::regex PLANE_ID_PATTER("[A-Z]{2}[0-9]{4,6}");
const std::regex BASE_CITY_NAME("^(?:[A-Z][a-z]*[\\s-]?){1,3}(?:[A-Z][a-z]*)?$");

const std::string FLIGHT_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\flights)";
const std::string PLANE_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\planes)";
const std::string RUNWAY_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\runways)";
const std::string STAFF_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\staff)";
const std::string ASSIGN_FLIGHTS_FILE_PATH = R"(D:\Workplace\CppTU\Coursework\resources\assign-flights)";


enum ResultCode {
    success, validation_error, internal_error, not_found_error
};

#endif
