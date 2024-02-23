#include <algorithm>
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

void BoardManagement::MoveLeft()
{
    // First, for each row, send the zeros to the right, maintaining order.
    for (auto& row : board_) {
        std::stable_partition(row.begin(), row.end(), [](int n) { return n != 0; });
    }
    // Merge identical non-zero neighbors
    for (auto& row : board_) {
        int index = 0;
        while(index < (board_size_ - 1) && row[index] != 0){
            if(row[index] == row[index + 1]){
                row[index] = 2*row[index];
                // Remove the neighbor and add a zero to the end;
                row.erase(row.begin() + index + 1);
                row.push_back(0);
            }
            index++;
        }
    }
}

void BoardManagement::MoveRight()
{
    // Mirror the board vertically so that a left move can be performed.
    for (auto& row : board_) {
        std::reverse(row.begin(), row.end());
    }
    // Perform move lef.
    MoveLeft();

    // Mirror the board vertically to go back to original orientation.
    for (auto& row : board_) {
        std::reverse(row.begin(), row.end());
    }

}

void BoardManagement::MoveVertically(bool down)
{
    RotateTheBoardNinetyDegrees(down);
    MoveLeft();
    RotateTheBoardNinetyDegrees(!down);
}

void BoardManagement::RotateTheBoardNinetyDegrees(bool clockwise)
{
    std::vector<std::vector<int>> rotated_board(board_size_, std::vector<int>(board_size_, 0));
    for (int row = 0; row < board_size_; row++){
        for (int col = 0; col < board_size_; col++){
            rotated_board[row][col] = (clockwise) ?  
            board_[board_size_ - 1 - col][row] : board_[col][board_size_ - 1 - row];
        }
    }

    board_ = rotated_board;
}
