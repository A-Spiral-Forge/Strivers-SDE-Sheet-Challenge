#include <bits/stdc++.h>
using namespace std;

// This function will return the box number for the given cell
int box(int i, int j) {
    return ((i / 3) * 3)  + (j / 3);
}

// This function will solve the sudoku
bool solveSudoku(int matrix[9][9], int i, int j, vector<vector<bool>> &rowsVisited, vector<vector<bool>> &colsVisited, vector<vector<bool>> &boxesVisited) {
    // If we have reached the end of the matrix, we will return true
    if(i >= 9) {
        return true;
    }

    // If we have reached the end of the row, we will move to the next row
    if(j >= 9) {
        i++; j = 0;
    }

    bool res = false;
    // If the current cell is not empty, we will move to the next cell
    if(matrix[i][j] != 0) {
        return solveSudoku(matrix, i, j + 1, rowsVisited, colsVisited, boxesVisited);
    }

    // We will try all the numbers from 1 to 9
    for(int num=1; num<=9; num++) {
        int boxNumber = box(i, j);
        // We will check if the current number is already present in the current row, column or box
        if(rowsVisited[i][num] || colsVisited[j][num] || boxesVisited[boxNumber][num]) {
            continue;
        }

        matrix[i][j] = num;
        rowsVisited[i][num] = colsVisited[j][num] = boxesVisited[boxNumber][num] = true;
        // If the current number is not present in the current row, column or box, we will try it
        res = res || solveSudoku(matrix, i, j + 1, rowsVisited, colsVisited, boxesVisited);
        // Backtrack to try the next number
        matrix[i][j] = 0;
        rowsVisited[i][num] = colsVisited[j][num] = boxesVisited[boxNumber][num] = false;
    }

    // Return the result
    return res;
}

bool isItSudoku(int matrix[9][9]) {
    // We will store the numbers which are already present in the current row, column or box
    vector<vector<bool>> rowsVisited(9, vector<bool>(10, false));
    vector<vector<bool>> colsVisited(9, vector<bool>(10, false));
    vector<vector<bool>> boxesVisited(9, vector<bool>(10, false));

    // We will mark the numbers which are already present in the current row, column or box
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int num = matrix[i][j];
            if(num == 0) {
                continue;
            }

            rowsVisited[i][num] = true;
            colsVisited[j][num] = true;
            boxesVisited[box(i, j)][num] = true;
        }
    }

    // We will solve the sudoku
    return solveSudoku(matrix, 0, 0, rowsVisited, colsVisited, boxesVisited);
}
