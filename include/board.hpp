#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "board_management.hpp"


enum class MoveCommand : int {kUp, kDown, kRight, kLeft};


/**
 *   @brief Class the manage the state of 2048 board and its algorithm.
 */  
class Board {
public:
    /**
     * @brief Default constructor of the class.
     * @param board_size integer, the length of the square board.
     * */ 
    Board(int board_size = 4) : board_management_(CreateInitialBoard(board_size), board_size){}

    /**
     * @brief Returns the current state of the board from BoardManagement instance.
     * @return Constant reference to the board.
    */
    const std::vector<std::vector<int>>& GetBoard() const;

    /**
     * @brief Checks if the game is finished.
     * This method checks if there is a zero element in the board or
     * there are two neighboring elements with the same value (which
     * means they can be combined).
     * @return true if the game can continue, otherwise false.
    */
    bool CanContinue() const;

    /**
     * @brief Updates the board based on the move command.
     * If the state of the board changes, a random 2 or 4 will be added at an empty position.
     * Keep in mind that if the changes the board that means an empty spot is available.
     * @param move_command MoveCommand enum indicating which move to perform.
    */
    void Move(MoveCommand move_command);


private:
    std::vector<std::vector<int>> CreateInitialBoard(int board_size);
    // Varibles
    BoardManagement board_management_;

};

#endif // BOARD_HPP