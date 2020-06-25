/*!
 * @file
 * @brief Position class implementation
 * All methods of the Position class are implemented here
*/
#include "Position.h"

using namespace std;

Position::Position(string data) : data(data) {} // Constructor in which we set data from the parameter

string Position::getData() const {
    return data;
}

bool Position::operator==(const Position &other) {
    return data == other.getData();
}