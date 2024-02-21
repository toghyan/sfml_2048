#include <vector>
#include <cstdlib>
#include <ctime>
#include "board_management.hpp"


int BoardManagement::GetRandomTwoOrFour()
{
    srand(time(NULL));
    return (rand() % 10) < 9 ? 2:4;
}

int BoardManagement::GetRandomPosition(int size)
{
    srand(time(NULL));
    int position = rand() % (size);
    
    return position;
}

bool BoardManagement::IsThereZero() const
{
    for (const auto& row : board_) {
        for (int value : row){
            if (value == 0)
                return true;
        }
    }
    return false;
}

bool BoardManagement::AnyMergableNeighbors() const
{
    for (int row = 0; row < board_size_; row++){
        for (int col = 0; col < board_size_; col++){
            if (board_[row][col] != 0 && AnyNeighborWithSameValue(row, col))
                return true;
        }
    }

    return false;
}

void BoardManagement::AddNewEntry()
{
    if (!IsThereZero())
        return;
    
    int position = GetRandomPosition(board_size_ * board_size_);
    // Try until we chose a position with value zero.
    while (board_[position / board_size_][position % board_size_] != 0)
        position = GetRandomPosition(board_size_ * board_size_);

    board_[position / board_size_][position % board_size_] = GetRandomTwoOrFour();
}

const std::vector<std::vector<int>> &BoardManagement::GetBoard() const
{
    return board_;
}

bool BoardManagement::AnyNeighborWithSameValue(int row, int col) const
{
    const int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int row_neighbor;
    int col_neighbor;
    for (int i = 0; i < 4; i++) {
        row_neighbor = row + neighbors[i][0];
        col_neighbor = col + neighbors[i][1];
        if ((0 <= row_neighbor) && (row_neighbor <= (board_size_ - 1)) &&
            (0 <= col_neighbor) && (col_neighbor <= (board_size_ - 1)) &&
            board_[row][col] == board_[row_neighbor][col_neighbor])
            return true;
    }

    return false;
}
