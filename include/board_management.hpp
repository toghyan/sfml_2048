#ifndef BOARD_MANAGEMENT_HPP
#define BOARD_MANAGEMENT_HPP

#include <vector>


class BoardManagement {
public:
    // Constructor.
    /**
     * @brief Default constructor of the class.
     * @param board 2D integer vector, initial state of the square board.
     * @param board_size integer indicating the lenght of the square board.
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
     * @param size integer indicating the upper limit of the random value.
     * @return a random integer between [0, size).
    */
    static int GetRandomPosition(int size);

    /**
     * @brief checks if any of the elements are zero.
     * @return true if any of the elements are zero, otherwise false.
    */
    bool IsThereZero() const;

    /**
     * @brief checks if there are two neighbors with the same non-zero value.
     * This function helps with checking if any merge is avalible.
     * @return true if there are two non-zero neighbors with the same value, otherwise false.
    */
    bool AnyMergableNeighbors() const;

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

    /**
     * @brief Checks if the given element has a neighbor with the same value.
     * @return true if a neighbor with the same value exist, otherwise false.
    */
    bool AnyNeighborWithSameValue(int row, int col) const;

    /**
     * @brief Performs a move to left.
     * This is a helper function to implement board manipulation.
    */
    void MoveLeft();

    /**
     * @brief performs a move to right.
     * This function first mirrors the board vertically, then performs a move to
     * the left and then mirrors the board vertically again.
    */
    void MoveRight();

    /**
     * @brief Performs a downward move and updates the board.
     * This function utilizes the board rotation helper to first transform the
     * board 90 degrees [clockwise for down move and counter clockwise for up move].
     * Then perfroms a move to the left. Then it rotates the board 90 degrees [counter 
     * clockwise for down move and clockwise for up move].
     * @param down boolean indicating a down move or an up move.
    */
    void MoveVertically(bool down);

    /**
     * @brief Rotates the board ninety degrees.
     * This method is a helper function to transform the board, when an up or
     * down move command is given, so that we can use the left move command.
     * @param clockwise boolean indicating clockwise or counter clockwise rotation.
    */
    void RotateTheBoardNinetyDegrees(bool clockwise);

    int board_size_;
    std::vector<std::vector<int>> board_;
};

#endif // BOARD_MANAGEMENT_HPP