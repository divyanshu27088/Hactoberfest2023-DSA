#include <iostream>
#include <vector>

bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int N) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(std::vector<std::vector<int>>& board, int col, int N) {
    if (col == N) {
        // All queens are successfully placed, print the solution.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    std::cout << "Q ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;
            res = solveNQueensUtil(board, col + 1, N) || res;
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

void solveNQueens(int N) {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0, N)) {
        std::cout << "No solution exists." << std::endl;
    }
}

int main() {
    int N;
    std::cout << "Enter the number of queens (N): ";
    std::cin >> N;
    solveNQueens(N);
    return 0;
}
