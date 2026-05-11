#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE("Board initializes with cells 1-9") {
    Board b;
    for (int i = 1; i < 10; i++) {
        REQUIRE(b.placeMark(i, 'X') == true);
    }
}

TEST_CASE("placeMark rejects moves on occupied cells") {
    Board b;

    REQUIRE(b.placeMark(1, 'X') == true);
    REQUIRE(b.placeMark(1, 'O') == false);
}

TEST_CASE("checkWinner detects row wins") {
    Board b;

    b.placeMark(1, 'X');
    b.placeMark(2, 'X');
    b.placeMark(3, 'X');

    REQUIRE(b.checkWinner('X') == true);
    REQUIRE(b.checkWinner('O') == false);
}

TEST_CASE("checkWinner detects column wins") {
    Board b;

    b.placeMark(1, 'O');
    b.placeMark(4, 'O');
    b.placeMark(7, 'O');

    REQUIRE(b.checkWinner('O') == true);
    REQUIRE(b.checkWinner('X') == false);
}

TEST_CASE("checkWinner detects diagonal wins") {
    Board b;

    b.placeMark(1, 'X');
    b.placeMark(5, 'X');
    b.placeMark(9, 'X');

    REQUIRE(b.checkWinner('X') == true);
}

TEST_CASE("checkWinner detects anti-diagonal wins") {
    Board b;

    b.placeMark(3, 'O');
    b.placeMark(5, 'O');
    b.placeMark(7, 'O');

    REQUIRE(b.checkWinner('O') == true);
}

TEST_CASE("getFirstAvailable returns 1 on an empty board") {
    Board b;
    REQUIRE(b.getFirstAvailable() == 1);
}

TEST_CASE("getFirstAvailable correctly skips occupied cells") {
    Board b;

    b.placeMark(1, 'X');
    b.placeMark(2, 'O');
    REQUIRE(b.getFirstAvailable() == 3);

    b.placeMark(3, 'X');
    b.placeMark(4, 'O');
    REQUIRE(b.getFirstAvailable() == 5);
}

TEST_CASE("getFirstAvailable returns -1 when the board is completely full") {
    Board b;

    for (int i = 1; i <= 9; i++) {
        b.placeMark(i, 'X');
    }

    REQUIRE(b.getFirstAvailable() == -1);
}

TEST_CASE("clear resets the board completely") {
    Board b;

    b.placeMark(1, 'X');
    b.placeMark(5, 'O');
    b.placeMark(9, 'X');

    b.clear();

    REQUIRE(b.getFirstAvailable() == 1);
    REQUIRE(b.placeMark(1, 'O') == true);
    REQUIRE(b.placeMark(5, 'X') == true);
}

TEST_CASE("Trap cell returns true but does not place a mark") {
    Board b;
    b.setTrap(5);

    REQUIRE(b.placeMark(5, 'X') == true);  // trap triggers
    REQUIRE(b.getCell(5) == '5');          // remains unchanged
}

TEST_CASE("Non-trap cells behave normally") {
    Board b;
    b.setTrap(5);

    REQUIRE(b.placeMark(1, 'X') == true);
    REQUIRE(b.getCell(1) == 'X');
}

TEST_CASE("Trap cell stays empty even after multiple attempts") {
    Board b;
    b.setTrap(5);

    REQUIRE(b.placeMark(5, 'X') == true);
    REQUIRE(b.placeMark(5, 'O') == true);
    REQUIRE(b.getCell(5) == '5');   // still empty
}

TEST_CASE("Trap can be changed and behaves correctly") {
    Board b;
    b.setTrap(3);

    REQUIRE(b.placeMark(3, 'X') == true);
    REQUIRE(b.getCell(3) == '3');

    b.setTrap(7);
    REQUIRE(b.placeMark(7, 'O') == true);
    REQUIRE(b.getCell(7) == '7');
}

TEST_CASE("getTrap returns correct trap cell") {
    Board b;
    b.setTrap(9);
    REQUIRE(b.getTrap() == 9);
}
