#pragma once

#include <vector>

class Board {
    std::vector<std::vector<char>> grid;
    int trap;

public:
    Board();

    void clear();

    void print() const;

    bool placeMark(int cell, char player);

    bool checkWinner(char player) const;

    int getFirstAvailable() const;

    void setTrap(int cell);

    int getTrap();

    char getCell(int cell) const;
};
