#pragma once

#include <vector>

using std::vector;

class Board {
private:
    vector<vector<char>> grid;

public:
    Board();

    void clear();

    void print() const;

    bool placeMark(int cell, char player);

    bool checkWinner(char player) const;

    int getFirstAvailable() const;
};

