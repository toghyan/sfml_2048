#include <vector>

#include <gtest/gtest.h>
#include "state_management.hpp"


TEST(StateManagementTest, BoardInitializedToAllZeros) {
    StateManagement state_management;

    std::vector<std::vector<int>> expected(StateManagement::board_size, std::vector<int>(StateManagement::board_size, 0));
    auto result = state_management.getBoard();

    EXPECT_EQ(result, expected);
}