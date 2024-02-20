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