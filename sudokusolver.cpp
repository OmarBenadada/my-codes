#include <iostream>
#include <string>

using namespace std;

const int GRID_SIZE = 9;

void printGridWithBorders(int grid[GRID_SIZE][GRID_SIZE]) {
    cout << " _________________________________" << endl;
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
       if (col == 0) cout << "|";  // Start row with a vertical border
            if (grid[row][col] == 0)
                cout << " . ";  // Use dot for empty cells
            else
                cout << " " << grid[row][col] << " ";

            if ((col + 1) % 3 == 0)  // Add vertical border after every 3 cells
                cout << "|";
        }
        cout << endl;

        if ((row + 1) % 3 == 0)  // Add horizontal border after every 3 rows
            cout << "|___|___|___|___|___|___|___|___|___|" << endl;
    }
    cout << endl;
}

// Function to check if placing num in grid[row][col] is valid
bool isValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    // Check row, column, and 3x3 subgrid
    for (int x = 0; x < GRID_SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

// Backtracking algorithm to solve the Sudoku
bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    bool emptySpace = false;

    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                emptySpace = true;
                break;
            }
        }
        if (emptySpace) break;
    }

    if (!emptySpace) return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Welcome to the Sudoku Solver Game!" << endl;
    cout << "Here's the initial Sudoku grid:" << endl;
    printGridWithBorders(grid);

    char choice;
    cout << "Do you want to modify the grid? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                cout << "Enter value for cell (" << row + 1 << ", " << col + 1 << ") (current value is " 
                     << (grid[row][col] == 0 ? "." : to_string(grid[row][col])) << "): ";
                cin >> grid[row][col];

                while (grid[row][col] < 0 || grid[row][col] > 9) {
                    cout << "Invalid input! Please enter a value between 0 and 9: ";
                    cin >> grid[row][col];
                }
            }
        }
    }

    cout << "The grid you entered is:" << endl;
    printGridWithBorders(grid);

    if (solveSudoku(grid)) {
        cout << "Sudoku Solved!" << endl;
        printGridWithBorders(grid);
    } else {
        cout << "This Sudoku puzzle cannot be solved!" << endl;
    }

    return 0;
}
