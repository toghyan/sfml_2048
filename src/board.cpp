#include "board.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

Board::Board() : board_(board_size, std::vector<int>(board_size, 0))
{
     int first_position = GetRandomPosition();
     int second_position;
     // Make sure the second position is different.
     do{
        second_position = GetRandomPosition();
     } while(first_position == second_position);

    // Set it to 2 or 4.
     board_[first_position / board_size][first_position % board_size] = GetRandomTwoOrFour();
     board_[second_position / board_size][second_position % board_size] = GetRandomTwoOrFour();

}

const std::vector<std::vector<int>> &Board::GetBoard() const
{
    return board_;
}

int Board::GetRandomTwoOrFour() const
{
    srand(time(NULL));
    return (rand() % 10) < 9 ? 2:4;
}

int Board::GetRandomPosition() const
{
    srand(time(NULL));
    int position = rand() % (board_size * board_size);
    
    return position;
}
