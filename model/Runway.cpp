#include <string>
#include "Runway.h"

Runway::Runway(const std::string &id, int length) : id(id), length(length) {}

Runway::~Runway() {}

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

Runway::Runway() {}
