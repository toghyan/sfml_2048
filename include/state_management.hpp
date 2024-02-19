#ifndef STATE_MANAGEMENT_HPP
#define STATE_MANAGEMENT_HPP

#include <vector>


/**
 *   @brief Class the manage the state of 2048 board and implement the algorithm
 */  
class StateManagement {
public:
    static constexpr int board_size = 4;
    StateManagement() : board(board_size, std::vector<int>(board_size, 0)) {}
    const std::vector<std::vector<int>>& getBoard() const;

private:
    
    std::vector<std::vector<int>> board;

};

#endif // STATE_MANAGEMENT_HPP