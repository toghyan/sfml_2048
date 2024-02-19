#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>


/**
 *   @brief Class the manage the state of 2048 board and implement the algorithm
 */  
class Board {
public:
    static constexpr int board_size = 4;
    Board() : board_(board_size, std::vector<int>(board_size, 0)) {}
    const std::vector<std::vector<int>>& getBoard() const;

private:
    
    std::vector<std::vector<int>> board_;

};

#endif // BOARD_HPP