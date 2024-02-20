#ifndef BOARD_MANAGEMENT_HPP
#define BOARD_MANAGEMENT_HPP

#include <vector>


class BoardManagement {
public:
    // Constructor.
    /**
     * @brief Default constructor of the class.
     * This constructor initiallizes the board_ member variable and 
     * sets two of its entries to 2 or 4 and the rest to zero.
     * */
    BoardManagement(std::vector<std::vector<int>> board, int board_size) : board_(board), board_size_(board_size) {}
    /**
     * @brief Method to generate 2 (90% chance) or 4 (10% chance).
     * @return 2 or 4.
     * */  
    static int GetRandomTwoOrFour();

    /**
     * @brief Method to get a random position on the board.
     * The return value is between [0, size) and the index is decided by
     * remainder to board size for column and dividend for row.
     *  e.g. 9 -> row 2 column 1.
     * @return a random integer between [0, size).
    */
    static int GetRandomPosition(int size);

    /**
     * @brief checks if any of the elements are zero.
     * @return true if any of the elements are zero, otherwise false.
    */
    bool IsThereZero() const;

    /**
     * @brief checks if any of the elements can be merged.
     * @return true if there are two non-zero neighbors with the same value, otherwise false.
    */
    bool MergeAvailable() const;

    /**
     * @brief Randomly, updates a zero entry to either 2 or 4.
     * @throws 
    */
    void AddNewEntry();

    /**
     * @brief Getter method for the board.
     * @return Constant reference to the board.
    */
    const std::vector<std::vector<int>>& GetBoard() const;

private:
    int board_size_;
    std::vector<std::vector<int>> board_;
};

#endif // BOARD_MANAGEMENT_HPP