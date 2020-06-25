#pragma once

#include <vector>
#include <string>
#include "Position.h"

using namespace std;

class PositionList {
private:
    vector<Position> positions;

public:
    PositionList() = default;

    void addPosition(Position position);

    void removePosition(int key);

    void removePosition(Position position);

    vector<Position> searchPositions(string data);

    vector<Position> &getAllPositions();
};