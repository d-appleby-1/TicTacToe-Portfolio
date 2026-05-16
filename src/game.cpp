#include "game.h"

#include "func.h"
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

Game::Game() {
    srand(time(nullptr));
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    Board board = Board();
    play();
}

void Game::play() {

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

        cout<<"\nEngage Trap Mode?"<<endl;
        cout<<"1. Yes"<<endl;
        cout<<"2. No"<<endl;
        int trap_mode = input_validate(1, 2);
        if (trap_mode == 1) {
            board.setTrap(rand() % 9 + 1);
        }

        int moves = 0;
        char current_player = 'X';
        board.print();

        while (true) {
            int cell;
            if (game_mode == 2 && current_player == comp_char) {
                cell = board.getFirstAvailable();
                board.placeMark(cell, current_player);
                cout << "Computer (Player " << current_player << ") chooses cell " << cell << "." << endl;
            } else {
                cout << "Player " << current_player << ", choose a cell (1-9): ";
                bool good_input;
                do {
                    good_input = true;
                    cell = input_validate(1,9);
                    if (!board.placeMark(cell, current_player)) {
                        cout << "Cell already taken. Try again." << endl;
                        good_input = false;
                    }
                } while (!good_input);
            }
            if (trap_mode != 1) {
                moves++;
            } else {
                if (board.getTrap() != cell) {
                    moves++;
                }
            }
            board.print();

            if (board.checkWinner(current_player)) {
                if (game_mode == 2 && current_player == comp_char) {
                    cout << "Computer wins!" << endl;
                } else {
                    cout << "Player " << current_player << " wins!" << endl;
                }
                break;
            }

            if (moves == 9 || moves == 8 && trap_mode == 1) {
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
        board.setTrap(0);
    } while (new_game);
}
