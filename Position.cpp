#include "Position.h"

Position::Position(string data) : data(data) {}

string Position::getData() const {
    return data;
}

bool Position::operator==(const Position &other) {
    return data == other.getData();
}

void Position::setData(string data) {
    this->data = data;
}