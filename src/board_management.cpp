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

bool BoardManagement::MergeAvailable() const
{
    return false;
}

const std::vector<std::vector<int>> &BoardManagement::GetBoard() const
{
    return board_;
}
