#include "tictactoe.hpp"

#include <iostream>

using std::vector;
using std::cout;
using std::endl;

Board::Board() : trap(0) {
    grid = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
}

void Board::clear() {
    grid = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
}

void Board::print() const {
    cout << "\nCurrent board:"<<endl;
    for (int i = 0; i < 3; i++) {
        cout << " " << grid[i][0] << " | " << grid[i][1] << " | " << grid[i][2] << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << endl;
}

bool Board::placeMark(int cell, char player) {
    if (cell == trap) {
        cout << "It's a trap!" << endl;
        return true;
    }
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;

    if (grid[row][col] == 'X' || grid[row][col] == 'O')
        return false;

    grid[row][col] = player;
    return true;
}

bool Board::checkWinner(char player) const {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}

int Board::getFirstAvailable() const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != 'X' && grid[i][j] != 'O') {
                return (i * 3) + j + 1;
            }
        }
    }
    return -1;
}

void Board::setTrap(int cell) {
    trap = cell;
}

int Board::getTrap() {
    return trap;
}

char Board::getCell(int cell) const {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    return grid[row][col];
}