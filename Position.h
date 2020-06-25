#pragma once

#include <string>

using namespace std;

class Position {
private:
    string data;

public:
    Position() = default;

    Position(string data);

    inline bool operator==(const Position &other);

    string getData() const;

    void setData(string data);
};