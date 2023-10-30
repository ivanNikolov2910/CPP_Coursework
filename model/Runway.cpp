
#include "Runway.h"

Runway::Runway(const string &id, int length) : id(id), length(length) {}

Runway::~Runway() {}

const string &Runway::getId() const {
    return id;
}

void Runway::setId(const string &id) {
    Runway::id = id;
}

int Runway::getLength() const {
    return length;
}

void Runway::setLength(int length) {
    Runway::length = length;
}


