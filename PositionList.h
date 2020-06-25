#pragma once

#include <vector>
#include <string>
#include "Position.h"

class PositionList {
private:
    std::vector<Position> positions;

public:
    PositionList() = default;

    void addPosition(Position position);

    void removePosition(int key);

    void removePosition(Position position);

    std::vector<Position> searchPositions(std::string data);

    std::vector<Position> &getAllPositions();
};