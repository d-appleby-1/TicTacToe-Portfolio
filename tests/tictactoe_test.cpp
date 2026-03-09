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