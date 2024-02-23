#include <vector>
#include "board.hpp"
#include "board_management.hpp"


const std::vector<std::vector<int>> &Board::GetBoard() const
{
    return board_management_.GetBoard();
}

bool Board::CanContinue() const
{
    return board_management_.IsThereZero() || board_management_.AnyMergableNeighbors();
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

void Board::Move(MoveCommand move_command)
{
    // Copy the board so that we can check if the board has changed.
    std::vector<std::vector<int>> board_copy(board_management_.GetBoard());

    switch (move_command)
    {
    case MoveCommand::kUp:
        board_management_.MoveVertically(false);
        break;

    case MoveCommand::kDown:
        board_management_.MoveVertically(true);
        break;
    
    case MoveCommand::kRight:
        board_management_.MoveRight();
        break;

    case MoveCommand::kLeft:
        board_management_.MoveLeft();
        break;
    
    default:
        break;
    }

    // If the board changed add a random 2 or 4 at an empty position.
    if (board_copy != board_management_.GetBoard())
        board_management_.AddNewEntry();
}
