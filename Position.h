#pragma once

#include <string>

class Position {
private:
    std::string data;

public:
    Position() = default;

    Position(std::string data);

    bool operator==(const Position &other);

    std::string getData() const;

    void setData(std::string data);
};