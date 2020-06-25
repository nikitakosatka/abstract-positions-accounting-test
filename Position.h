#pragma once

class Position {
private:
    string data;

public:
    Position() = default;

    Position(string data);

    string getData();

    void setData(string data);
};