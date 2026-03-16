#include <iostream>
#include "src/tictactoe.hpp"
#include <limits>

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "Welcome to Tic-Tac-Toe!"<<endl;

    Board board;


    char current_player = 'X';
    int moves;
    bool new_game;
    do {
        moves = 0;
        board.print();
        while (true) {
            cout << "Player " << current_player << ", choose a cell (1-9): ";
            bool good_input;
            int cell;
            do {
                good_input = true;
                cell = input_validate(1,9);
                if (!board.placeMark(cell, current_player)) {
                    cout << "Cell already taken. Try again."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    good_input = false;
                }
            } while (!good_input);

            moves++;
            board.print();

            if (board.checkWinner(current_player)) {
                cout << "Player " << current_player << " wins!"<<endl;
                break;
            }

            if (moves == 9) {
                cout << "It's a draw!"<<endl;
                break;
            }

            current_player = (current_player == 'X') ? 'O' : 'X';
        }
        cout<<"Play again? Type '1' for yes and '2' for no."<<endl;
        int selection = input_validate(1,2);
        if (selection == 1) {
            new_game = true;
        } else {
            new_game = false;
        }
        board.clear();
    } while (new_game);
}