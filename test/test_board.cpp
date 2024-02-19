#include <vector>

#include <gtest/gtest.h>
#include "board.hpp"


TEST(StateManagementTest, BoardInitializedToAllZeros) {
    Board board;

    std::vector<std::vector<int>> expected(Board::board_size, std::vector<int>(Board::board_size, 0));
    auto result = board.getBoard();

    EXPECT_EQ(result, expected);
}