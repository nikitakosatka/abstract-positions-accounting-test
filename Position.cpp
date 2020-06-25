#include "Position.h"

using namespace std;

Position::Position(string data) : data(data) {}

string Position::getData() const {
    return data;
}

bool Position::operator==(const Position &other) {
    return data == other.getData();
}