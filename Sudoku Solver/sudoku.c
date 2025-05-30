#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Add this line for time() function

int sudoku[9][9];

// Function Declaration
void printSudoku(int sudoku[9][9]);
int validMove(int sudoku[9][9], int row, int column, int value);
int solveSudoku(int sudoku[9][9], int row, int column);
int isValidSudoku(int sudoku[9][9]);
void inputSudoku(int sudoku[9][9]);
void generateSudoku(int sudoku[9][9], int difficulty);
void removeNumbers(int sudoku[9][9], int difficulty);

int main()
{
    int choice;        // Choose know if the user want to enter the Sudoku or needs the computer to generate
    srand(time(NULL)); // Seed for random Sudoku generation

    while (1)
    {
        printf("\nWelcome to SUDOKU SOLVER!\n");
        printf("Choose an option:\n");
        printf("1. Enter Sudoku manually\n");
        printf("2. Generate a new Sudoku\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) // Sudoku is entered Manually
        {
            inputSudoku(sudoku); // Function Calling

            // Printing Original Sudoku
            printf("\nOriginal Sudoku:");
            printSudoku(sudoku);

            // Check if the entered Sudoku is valid
            if (!isValidSudoku(sudoku))
            {
                printf("\nThe entered Sudoku is INVALID.\n");
                continue;
            }

            // Directly solve the Sudoku
            if (solveSudoku(sudoku, 0, 0))
            {
                printf("\nHurray! The Sudoku is solved:\n");
                printSudoku(sudoku);
            }
            else
            {
                printf("\nSorry, this Sudoku is NOT solvable.\n");
            }
        }
        else if (choice == 2) // Sudoku is generated by the Computer
        {
            int difficulty;
            printf("Choose difficulty level:\n");
            printf("1. Easy\n2. Medium\n3. Hard\n4. Super\n5. Expert\n6. Exit\n");
            scanf("%d", &difficulty);

            if (difficulty == 6)
            {
                printf("Exiting Sudoku Solver. Goodbye!\n");
                return 0;
            }
            generateSudoku(sudoku, difficulty);
        }
        else if (choice == 3) // Exit
        {
            printf("Exiting Sudoku Solver. Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Printing Original Sudoku
        printf("\nOriginal Sudoku:");
        printSudoku(sudoku);

        // Check if the Sudoku entered by the user is valid or not because the code generated by the computer is valid
        if (!isValidSudoku(sudoku))
        {
            printf("\nThe entered Sudoku is INVALID.\n");
            continue;
        }

        // If the User wants the computer to solve the Sudoku or not
        if (choice == 2)
        {
            int solve;
            printf("\nDo you want to solve the Sudoku? (1 for Yes, 0 for No, 2 to Exit): ");
            scanf("%d", &solve);
            if (solve == 2 || solve == 0) // Sudoku not solved by the Computer or Exit
            {
                printf("Exiting Sudoku Solver. Goodbye!\n");
                return 0;
            }
            else if (solve == 1) // Sudoku Solved by the Computer
            {
                if (solveSudoku(sudoku, 0, 0))
                {
                    printf("\nHurray! The Sudoku is solved.\n");
                    printSudoku(sudoku);
                }
                else
                {
                    printf("\nSorry, this Sudoku is NOT solvable.\n");
                }
            }
        }
    }
    return 0;
}

// Taking input of Sudoku from the User
void inputSudoku(int sudoku[9][9])
{
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (int i = 0; i < 9; i++) // Row
    {
        for (int j = 0; j < 9; j++) // Column
        {
            scanf("%d", &sudoku[i][j]);
        }
    }
}

// For Generating Sudoku by the Computer
void generateSudoku(int sudoku[9][9], int difficulty)
{
    solveSudoku(sudoku, 0, 0);
    removeNumbers(sudoku, difficulty);
}

// To Make the Difficulty of the Sudoku Puzzle
void removeNumbers(int sudoku[9][9], int difficulty)
{
    int clues;
    switch (difficulty)
    {
    case 1:
        clues = 50;
        break; // Easy
    case 2:
        clues = 40;
        break; // Medium
    case 3:
        clues = 30;
        break; // Hard
    case 4:
        clues = 25;
        break; // Super
    case 5:
        clues = 20;
        break; // Expert
    default:
        clues = 40;
        break; // Default to Medium
    }

    int totalCells = 81;
    int toRemove = totalCells - clues;
    while (toRemove > 0)
    {
        int r = rand() % 9;
        int c = rand() % 9;
        if (sudoku[r][c] != 0)
        {
            sudoku[r][c] = 0;
            toRemove--;
        }
    }
}

// To check whether the Sudoku Entered is Valid or not
int isValidSudoku(int sudoku[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (sudoku[row][col] != 0)
            {
                int value = sudoku[row][col];
                sudoku[row][col] = 0;
                if (!validMove(sudoku, row, col, value))
                {
                    return 0;
                }
                sudoku[row][col] = value;
            }
        }
    }
    return 1;
}

// Print the Sudoku Puzzle
void printSudoku(int sudoku[9][9])
{
    printf("\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++)
    {
        if (row % 3 == 0 && row != 0)
        {
            printf("\n|-------+-------+-------|");
        }
        printf("\n");
        for (int column = 0; column < 9; column++)
        {
            if (column % 3 == 0)
            {
                printf("| ");
            }
            if (sudoku[row][column] != 0)
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

// This function is to check whether the move made by the computer is valid or not when the computer is solving the Sudoku
int validMove(int sudoku[9][9], int row, int column, int value)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[row][i] == value || sudoku[i][column] == value)
        {
            return 0;
        }
    }

    int r = row - row % 3;
    int c = column - column % 3;
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            if (sudoku[r + m][c + n] == value)
            {
                return 0;
            }
        }
    }
    return 1;
}

// To solve the Sudoku
int solveSudoku(int sudoku[9][9], int row, int column)
{
    if (column == 9)
    {
        if (row == 8)
        {
            return 1; // Sudoku is solved
        }
        row++;
        column = 0;
    }

    if (sudoku[row][column] > 0)
    {
        return solveSudoku(sudoku, row, column + 1);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (validMove(sudoku, row, column, num))
        {
            sudoku[row][column] = num;
            if (solveSudoku(sudoku, row, column + 1))
            {
                return 1;
            }
            sudoku[row][column] = 0; // Backtrack
        }
    }
    return 0;
}