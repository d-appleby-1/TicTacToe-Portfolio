#include "func.h"

#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;

int input_validate(int lower, int upper) {
    std::string s;
    bool good_input;
    do {
        good_input = true;
        cin >> s;
        if (cin.fail() || s[0] - 48 < lower || s[0] - 48 > upper || s.length() > 1) {
            cout << "Invalid input. Please try again."<<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            good_input = false;
        }
    } while (!good_input);

    return s[0] - 48;
}