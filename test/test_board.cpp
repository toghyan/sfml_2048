#include <vector>

#include <gtest/gtest.h>
#include "board.hpp"


TEST(BoardTest, BoardInitialization) {
    Board board;
    auto result = board.GetBoard();

    int num_zeros = 0;
    int num_two_or_four = 0;

    for (const auto& row : result) {
        for (int value : row) {
            if (value == 0)
                num_zeros++;
            else if (value == 2 || value == 4)
                num_two_or_four++;
        }
    }

    // All but two values should be zero.
    EXPECT_EQ(num_zeros, 14);
    // Two of the values should be 2 or 4.
    EXPECT_EQ(num_two_or_four, 2);
}