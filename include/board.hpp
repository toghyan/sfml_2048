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
     * @brief Updates the board based on the move command and then adds a random value.
     * This function does not care if the board won't chnage with the given command.
    */
    void Move(MoveCommand move_command);


private:
    std::vector<std::vector<int>> CreateInitialBoard(int board_size);
    // Varibles
    BoardManagement board_management_;

};

#endif // BOARD_HPP