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

TEST(BoardManagementTest, AnyMergableNeighborsReturnsTrue) {
    int size = 4;
    // A 4x4 board of 0s except the last two elements of the last row that are 2s.
    std::vector<std::vector<int>> board_row_neighbors(size, std::vector<int>(size, 0));
    board_row_neighbors[size - 1][size - 2] = 2;
    board_row_neighbors[size - 1][size - 1] = 2;

    BoardManagement board_management_with_row_neighbors(board_row_neighbors, size);
    EXPECT_TRUE(board_management_with_row_neighbors.AnyMergableNeighbors());

    // A 4x4 board of 0s except the last two elements of the first column that are 2s.
    std::vector<std::vector<int>> board_column_neighbors(size, std::vector<int>(size, 0));
    board_column_neighbors[0][size - 2] = 2;
    board_column_neighbors[0][size - 1] = 2;

    BoardManagement board_management_with_column_neighbors(board_column_neighbors, size);
    EXPECT_TRUE(board_management_with_column_neighbors.AnyMergableNeighbors());

}

TEST(BoardManagementTest, AnyMergableNeighborsReturnsFalse) {
    int size = 4;
    std::vector<std::vector<int>> board = {{2, 4, 2, 4}, {4, 2, 4, 2}, {2, 4, 2, 4}, {4, 2, 4, 2}};

    BoardManagement board_management(board, size);
    EXPECT_FALSE(board_management.AnyMergableNeighbors());

}

TEST(BoardManagementTest, AddNewEntryTest) {
    // 4 by 4 board with ones except one zero. Using ones here to check if any
    // of the non-zero elements gets changed to 2 or 4.
    int existing_elements_value = 1;
    int size = 4;
    int row_zero = 3;
    int col_zero = 3;
    std::vector<std::vector<int>> board(size, std::vector<int>(size, existing_elements_value));
    board[row_zero][col_zero] = 0;
    BoardManagement board_management(board, size);
    board_management.AddNewEntry();

    // Check if the zero changed to 2 or 4.
    int result = board_management.GetBoard()[row_zero][col_zero];
    EXPECT_TRUE(result == 2 || result == 4);

    // Check if any of the ones changed.
    for (int row=0; row < size; row++){
        for (int col=0; col < size; col++){
            if (row == row_zero && col == col_zero)
                continue;
            result = board_management.GetBoard()[row][col];
            EXPECT_EQ(result, existing_elements_value);
        }
    }

}