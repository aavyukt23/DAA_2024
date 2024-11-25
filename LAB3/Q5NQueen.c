#include <stdio.h>
#include <stdbool.h>

#define N 8 // Change this for a different size chessboard

// Function to print the board
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the current column
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueen(int board[N][N], int row) {
    // Base case: If all queens are placed
    if (row >= N) {
        printBoard(board);
        return true;
    }

    bool success = false;
    // Try placing a queen in each column for the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place the queen

            // Recur to place queens in the next row
            success = solveNQueen(board, row + 1) || success;

            // Backtrack and remove the queen
            board[row][col] = 0;
        }
    }

    return success;
}

int main() {
    int board[N][N] = {0};

    printf("Solutions to the %d-Queen problem:\n", N);
    if (!solveNQueen(board, 0)) {
        printf("No solution exists.\n");
    }

    return 0;
}
