#include <stdio.h>

#define N 4

int board[N][N];

void printSolution() {
	int i,j;
    for ( i = 0; i < N; i++) {
        for ( j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isSafe(int row, int col) {
	int i,j;
    for ( i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for ( i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for ( i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQueens(int col) {
    if (col >= N) {
        printSolution();
        return 1;
    }

    int res = 0;
    int i;
    for ( i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1; 
            res = solveNQueens(col + 1) || res; 

            board[i][col] = 0; 
        }
    }

    return res;
}

int main() {
	int i,j;
    for ( i = 0; i < N; i++)
        for ( j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQueens(0))
        printf("Solution does not exist\n");

    return 0;
} 
