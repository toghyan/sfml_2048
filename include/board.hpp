#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>


/**
 *   @brief Class the manage the state of 2048 board and its algorithm.
 */  
class Board {
public:
    static constexpr int board_size = 4;

    /**
     * @brief Default constructor of the board class.
     * This constructor initiallizes the board_ member variable and 
     * sets two of its entries to 2 or 4 and the rest to zero.
     * */ 
    Board();

    /**
     * @brief Getter method for the board.
     * @return Constant reference to the board.
    */
    const std::vector<std::vector<int>>& GetBoard() const;

private:
    // Methods

    /**
     * @brief Method to generate 2 (90% chance) or 4 (10% chance).
     * @return 2 or 4.
     * */  
    int GetRandomTwoOrFour() const;

    /**
     * @brief Method to get a random position on the board.
     * The return value is between 0 and 15 and the index is decided by
     * remainder to board size for column and dividend for row.
     *  e.g. 9 -> row 2 column 1.
     * @return a random integer between 0 and 15 (inclusive).
    */
    int GetRandomPosition() const;

    // Varibles
    std::vector<std::vector<int>> board_;

};

#endif // BOARD_HPP