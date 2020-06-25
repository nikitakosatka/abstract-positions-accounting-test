#include "Position.h"

Position::Position(string data) : data(data) {}

string Position::getData() {
    return data;
}

void Position::setData(string data) {
    this->data = data;
}