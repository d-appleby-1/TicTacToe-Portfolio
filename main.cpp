#include <iostream>
#include "src/tictactoe.hpp"
#include <limits>

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;

    Board board;

    bool new_game;
    do {
        cout << "\nSelect Game Mode:" << endl;
        cout << "1. Human vs Human" << endl;
        cout << "2. Human vs Computer" << endl;
        int game_mode = input_validate(1, 2);

        char comp_char = ' ';
        if (game_mode == 2) {
            cout << "\nWho should go first?" << endl;
            cout << "1. Computer" << endl;
            cout << "2. Human" << endl;
            int comp_order = input_validate(1, 2);
            comp_char = (comp_order == 1) ? 'X' : 'O';
        }

        int moves = 0;
        char current_player = 'X';
        board.print();

        while (true) {
            if (game_mode == 2 && current_player == comp_char) {
                int cell = board.getFirstAvailable();
                board.placeMark(cell, current_player);
                cout << "Computer (Player " << current_player << ") chooses cell " << cell << "." << endl;
            } else {
                cout << "Player " << current_player << ", choose a cell (1-9): ";
                bool good_input;
                int cell;
                do {
                    good_input = true;
                    cell = input_validate(1,9);
                    if (!board.placeMark(cell, current_player)) {
                        cout << "Cell already taken. Try again." << endl;
                        good_input = false;
                    }
                } while (!good_input);
            }

            moves++;
            board.print();

            if (board.checkWinner(current_player)) {
                if (game_mode == 2 && current_player == comp_char) {
                    cout << "Computer wins!" << endl;
                } else {
                    cout << "Player " << current_player << " wins!" << endl;
                }
                break;
            }

            if (moves == 9) {
                cout << "It's a draw!" << endl;
                break;
            }

            current_player = (current_player == 'X') ? 'O' : 'X';
        }

        cout << "Play again? Type '1' for yes and '2' for no." << endl;
        if (input_validate(1,2) == 1) {
            new_game = true;
        } else {
            new_game = false;
        }
        board.clear();
    } while (new_game);

    return 0;
}