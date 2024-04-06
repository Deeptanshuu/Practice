#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int solutions[MAX][MAX];
int solutionCount = 0;

void printBoard(int board[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[MAX][MAX], int row, int col, int n) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int board[MAX][MAX], int col, int n) {
    if (col == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j])
                    solutions[solutionCount][j] = i + 1;
            }
        }
        solutionCount++;
        return 1;
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1, n) || res;
            board[i][col] = 0;
        }
    }

    return res;
}

int nQueen(int n) {
    solutionCount = 0;
    int board[MAX][MAX] = {0};

    if (solveNQUtil(board, 0, n) == 0)
        return 0;

    for (int i = 0; i < solutionCount; i++) {
        int tempBoard[MAX][MAX] = {0};
        for (int j = 0; j < n; j++) {
            tempBoard[solutions[i][j] - 1][j] = 1;
        }
        printf("Solution %d:\n", i + 1);
        printBoard(tempBoard, n);
    }

    return 1;
}

int main() {
    int n;
    printf("Enter the value of N for the N-Queens problem: ");
    scanf("%d", &n);
    nQueen(n);
    return 0;
}