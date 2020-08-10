#include <stdio.h>

#define SIZE 9

// The problem.
int matrix[9][9] = {
    {0,0,0,2,6,0,7,0,1},
    {6,8,0,0,7,0,0,9,0},
    {1,9,0,0,0,4,5,0,0},
    {8,2,0,1,0,0,0,4,0},
    {0,0,4,6,0,2,9,0,0},
    {0,5,0,0,0,3,0,2,8},
    {0,0,9,3,0,0,0,7,4},
    {0,4,0,0,5,0,0,3,6},
    {7,0,3,0,1,8,0,0,0}
};

// Display sudoku.
void display()
{
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d", matrix[i][j]);
        }

        printf("\n");
    }
}

// Check if all cells are assigned or not if there is any unassigned cell,
// then this function will change the values of row and col accordingly.
int unassigned_number(int *row, int *col)
{
    int unassign = 0;
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            // Cell is unassigned.
            if (matrix[i][j] == 0) {
                // Change values of row and col.
                *row = i;
                *col = j;

                // There is one or more unassigned cells.
                unassign = 1;
                return unassign;
            }
        }
    }

    return unassign;
}

// Check if we can put a value in a paticular cell or not.
int is_safe(int n, int r, int c)
{
    int i, j;

    // Checking in row.
    for (i = 0; i < SIZE; i++) {
        // There is a cell with same value.
        if (matrix[r][i] == n) {
            return 0;
        }
    }

    // Checking column.
    for (i = 0; i < SIZE; i++) {
        // There is a cell with the value equal to i.
        if (matrix[i][c] == n) {
            return 0;
        }
    }

    // Checking sub matrix.
    int row_start = (r / 3) * 3;
    int col_start = (c / 3) * 3;

    for (i = row_start; i < row_start + 3; i++) {
        for(j = col_start; j < col_start + 3; j++) {
            if (matrix[i][j] == n) {
                return 0;
            }
        }
    }

    return 1;
}

// Solve sudoku using backtracking.
int solve()
{
    int row, col;

    // If all cells are assigned then the sudoku is already solved, pass by reference.
    // Because unassigned_number will change the values of row and col.
    if (unassigned_number(&row, &col) == 0) {
        return 1;
    }

    int n, i;

    // Number between 1 to 9.
    for (i = 1; i <= SIZE; i++) {
        // If we can assign i to the cell or not, the cell is matrix[row][col].
        if (is_safe(i, row, col)) {
            matrix[row][col] = i;

            // Backtracking process.
            if (solve()) {
                return 1;
            }

            // If we can't proceed with this solution, reassign the cell.
            matrix[row][col] = 0;
        }
    }

    return 0;
}

int main()
{
    if (solve()) {
        display();
    }
    else {
        printf("Solution not found.\n");
    }

    return 0;
}
