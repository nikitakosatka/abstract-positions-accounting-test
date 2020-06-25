#pragma once

#include <iostream>
#include "Position.h"
#include "PositionList.h"

class ConsoleInterface {
private:
    PositionList list;
    bool running;

public:
    ConsoleInterface() = default;

    void run();

    void addPosition();

    void removePosition();

    void getAllPositions();

    void searchPositions();
};