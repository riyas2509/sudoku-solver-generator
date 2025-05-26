/*
Check if the entered sudoku is valid
Take input of sudoku from the user
Generate a new Sudoku and if asked then only solve it
*/

#include <stdio.h>
int sudoku[9][9] = {
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0},
};

void printSudoku(int sudoku[9][9]);
int validMove(int sudoku[9][9], int row, int column, int value); //Considering Given Sudoku is Valid
int solveSudoku(int sudoku[9][9], int row, int column);

int main()
{
    printf("\nWelcome to SUDOKU SOLVER !!!");
    printf("\nOriginal Sudoku : ");
    printSudoku(sudoku);
    if (solveSudoku(sudoku, 0, 0))
    {
        printf("\nHurray!!! The Sudoku is Solved.\nSolved Sudoku is:");
        printSudoku(sudoku);
    }
    else
    {
        printf("\nSORRY. This Sudoku is NOT Solvable.\n");
    }

    return 0;
}

void printSudoku(int sudoku[9][9])
{
    printf("\n+-------+-------+-------+");
    for(int row = 0; row < 9; row++)
    {
        if(row % 3 == 0 && row != 0)
        {
            printf("\n|-------+-------+-------|");
        }
        printf("\n");
        for(int column = 0; column < 9; column++)
        {
            if(column % 3 == 0)
            {
                printf("| ");
            }
            if(sudoku[row][column] != 0)
            {
                printf("%d ", sudoku[row][column]);
            }
            else
            {
                printf("  ");
            }
        }
        printf("|");
    }
    printf("\n+-------+-------+-------+\n");
}

int validMove(int sudoku[9][9], int row, int column, int value)
{
    //Valid Row
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[row][i] == value)
        {
            return 0;
        }
    }

    //Valid Column
    for(int j = 0; j < 9; j++)
    {
        if(sudoku[j][column] == value)
        {
            return 0;
        }
    }

    //Valid Square
        //2 loops required for 3x3 block execution
        //We would like ki hum jis block mai hai uske start mai aa jaye
        //r = row - row % 3 and c = column - column % 3
    int r = row - row % 3;
    int c = column - column % 3;
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            if (sudoku[r+m][c+n] == value)
            {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int sudoku[9][9], int row, int column)
{
    //Boundary Case to Check if we have reached the last number of the grid
    if(column == 9)
    {
        //Boundary Case to Check if we have reached the last number of the Sudoku
        if(row == 8)
        {
            return 1; //Sudoku is Solved
        }
        row++;
        column = 0;
    }

    if(sudoku[row][column] > 0)
    {
        return solveSudoku(sudoku, row, column+1);
    }

    for(int i = 1; i <= 9; i++)
    {
        if(validMove(sudoku, row, column, i))
        {
            sudoku[row][column] = i;
            if(solveSudoku(sudoku, row, column + 1))
            {
                return 1;
            }
            sudoku[row][column] = 0;
        }
    }
    return 0;
}