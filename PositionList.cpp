/*!
 * @file
 * @brief PositionList class implementation
 * All methods of the PositionList class are implemented here
*/
#include "PositionList.h"

using namespace std;

void PositionList::addPosition(Position position) {
    positions.push_back(position);
}

void PositionList::removePosition(int key) {
    if (key < 0 || key >= positions.size()) {
        throw out_of_range("Key is out of range");
    }

    positions.erase(positions.begin() + key);
}

void PositionList::removePosition(Position position) {
    for (int index = 0; index < positions.size(); index++) {
        if (positions[index] == position) {
            removePosition(index);
            break;
        }

        if (index == positions.size() - 1) {
            throw out_of_range("Element is not found");
        }
    }
}

vector<Position> PositionList::searchPositions(string data) {
    vector<Position> foundPositions;

    for (int index = 0; index < positions.size(); index++) {
        if (positions[index].getData().find(data) != string::npos) {
            foundPositions.push_back(positions[index]);
        }
    }

    return foundPositions;
}

vector<Position> &PositionList::getAllPositions() {
    return positions;
}