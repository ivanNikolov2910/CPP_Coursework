#include <string>
#include "Runway.h"

Runway::Runway(const std::string &id, int length) {
    Runway::id = id;
    Runway::length = length;
}

Runway::~Runway() = default;

const std::string &Runway::getId() const {
    return id;
}

void Runway::setId(const std::string &id) {
    Runway::id = id;
}

int Runway::getLength() const {
    return length;
}

void Runway::setLength(int length) {
    Runway::length = length;
}