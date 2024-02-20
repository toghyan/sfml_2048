#include <vector>
#include "board.hpp"
#include "board_management.hpp"


const std::vector<std::vector<int>> &Board::GetBoard() const
{
    return board_management_.GetBoard();
}

bool Board::CanContinue() const
{
    return board_management_.IsThereZero() || board_management_.MergeAvailable();
}

void Board::Move(MoveCommand move_command)
{
}

std::vector<std::vector<int>> Board::CreateInitialBoard(int board_size)
{
    std::vector<std::vector<int>> board(board_size, std::vector<int>(board_size, 0));
    int first_position = BoardManagement::GetRandomPosition(board_size * board_size);
    int second_position;
    // Make sure the second position is different.
    do{
       second_position = BoardManagement::GetRandomPosition(board_size * board_size);
    } while(first_position == second_position);

    // Set it to 2 or 4.
    board[first_position / board_size][first_position % board_size] = BoardManagement::GetRandomTwoOrFour();
    board[second_position / board_size][second_position % board_size] = BoardManagement::GetRandomTwoOrFour();

    return board;
}
