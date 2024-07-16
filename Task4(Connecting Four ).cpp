#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

class ConnectFour {
private:
    std::vector<std::vector<char> > board;
    char currentPlayer;

public:
    ConnectFour() : board(ROWS, std::vector<char>(COLS, ' ')), currentPlayer('X') {}

    void printBoard() {
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                std::cout << "| " << board[row][col] << " ";
            }
            std::cout << "|\n";
        }
        for (int col = 0; col < COLS; ++col) {
            std::cout << "----";
        }
        std::cout << "-\n";
        for (int col = 0; col < COLS; ++col) {
            std::cout << "  " << col + 1 << " ";
        }
        std::cout << "\n";
    }

    bool dropDisc(int col) {
        if (col < 0 || col >= COLS || board[0][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            return false;
        }

        for (int row = ROWS - 1; row >= 0; --row) {
            if (board[row][col] == ' ') {
                board[row][col] = currentPlayer;
                return true;
            }
        }
        return false;
    }

    bool checkWin() {
        // Check horizontal, vertical, and diagonal lines for a win
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                if (board[row][col] == ' ') continue;
                if (col <= COLS - 4 &&
                    board[row][col] == board[row][col + 1] &&
                    board[row][col] == board[row][col + 2] &&
                    board[row][col] == board[row][col + 3]) return true;
                if (row <= ROWS - 4 &&
                    board[row][col] == board[row + 1][col] &&
                    board[row][col] == board[row + 2][col] &&
                    board[row][col] == board[row + 3][col]) return true;
                if (col <= COLS - 4 && row <= ROWS - 4 &&
                    board[row][col] == board[row + 1][col + 1] &&
                    board[row][col] == board[row + 2][col + 2] &&
                    board[row][col] == board[row + 3][col + 3]) return true;
                if (col >= 3 && row <= ROWS - 4 &&
                    board[row][col] == board[row + 1][col - 1] &&
                    board[row][col] == board[row + 2][col - 2] &&
                    board[row][col] == board[row + 3][col - 3]) return true;
            }
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        while (true) {
            printBoard();
            int col;
            std::cout << "Player " << currentPlayer << ", enter column (1-7) to drop your disc: ";
            std::cin >> col;
            if (dropDisc(col - 1)) {
                if (checkWin()) {
                    printBoard();
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    break;
                }
                switchPlayer();
            }
        }
    }
};

int main() {
    ConnectFour game;
    game.play();
    return 0;
}

