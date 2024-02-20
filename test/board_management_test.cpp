#include <vector>
#include <gtest/gtest.h>
#include "board_management.hpp"


TEST(BoardManagementTest, GetRandomTwoOrFourTest) {
    int result;
    for (int i = 0; i < 10; i++){
        result = BoardManagement::GetRandomTwoOrFour();
        EXPECT_TRUE (result == 2 || result == 4);
    }
}

TEST(BoardManagementTest, GetRandomPositionTest) {
    int result;
    for (int size = 1; size < 26; size++){
        result = BoardManagement::GetRandomPosition(size);
        EXPECT_LE(result, size - 1);
        EXPECT_GE(result, 0);
    }
    
}

TEST(BoardManagementTest, IsThereZeroReturnsFalse) {
    int size = 4;
    // A 4x4 board of 2s.
    std::vector<std::vector<int>> board(size, std::vector<int>(size, 2));
    BoardManagement board_management(board, size);

    EXPECT_FALSE(board_management.IsThereZero());
}

TEST(BoardManagementTest, IsThereZeroReturnsTrue) {
    int size = 4;
    // A 4x4 board of 2s except the last element which is zero.
    std::vector<std::vector<int>> board(size, std::vector<int>(size, 2));
    board[size - 1][size - 1] = 0;
    BoardManagement board_management(board, size);

    EXPECT_TRUE(board_management.IsThereZero());
}