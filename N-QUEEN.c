#include <stdio.h>
#include <stdbool.h>

#define MAX_N 8

bool isSafe(int board[][MAX_N], int row, int col, int n) {
    // Check for queens in the same column above
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens diagonally above left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens diagonally above right
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[][MAX_N], int row, int n) {
    if (row == n) {
        return true;  // All queens placed
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = 1;  // Place queen
            if (solveNQueens(board, row + 1, n)) {
                return true;
            }
            board[row][i] = 0;  // Backtrack
        }
    }

    return false;  // No valid position found for this row
}

void printSolution(int board[][MAX_N], int n) {
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the value of N (4, 6, or 8): ");
    scanf("%d", &n);

    if (n != 4 && n != 6 && n != 8) {
        printf("Invalid N value. Please enter 4, 6, or 8.\n");
        return 1;
    }

    int board[MAX_N][MAX_N] = {0};  // Initialize the board

    if (!solveNQueens(board, 0, n)) {
        printf("Solution does not exist\n");
        return 1;
    }

    printSolution(board, n);
    return 0;
}
