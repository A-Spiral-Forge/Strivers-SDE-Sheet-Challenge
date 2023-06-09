#include <bits/stdc++.h>
using namespace std;

// This function will check if the current position is safe or not diagonally
bool check(vector<int> &temp, int column, int row) {
    for(int i=0; i<column; i++) {
        if(temp[i] + i == row + column) {
            return false;
        }
        if(temp[i] - i == row - column) {
            return false;
        }
    }
    return true;
}

// This function will generate all the possible positions of the queens
void solve(vector<vector<int>> &positions, vector<int> &temp, vector<bool> &visited, int column, int n) {
    // If we have reached the end of the board, we will add the current position to the result
    if(column == n) {
        positions.push_back(temp);
        return;
    }

    // We will try to place the queen in all the possible positions in the current column
    for(int i=0; i<n; i++) {
        // If the current position is safe, we will place the queen there
        if(!visited[i] && check(temp, column, i)) {
            temp.push_back(i);
            // We will mark the current position as visited
            visited[i] = true;
            // We will try to place the queen in the next column
            solve(positions, temp, visited, column + 1, n);
            // We will backtrack
            temp.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // We will store all the possible positions of the queens
    vector<vector<int>> positions;
    vector<int> temp;
    // We will store if the current row is visited or not
    vector<bool> visited(n, false);
    
    // We will generate all the possible positions of the queens
    solve(positions, temp, visited, 0, n);
    vector<vector<int>> res;

    // We will convert the positions to the required format
    for(const vector<int> &it: positions) {
        vector<int> temp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(j == it[i]) {
                    temp.push_back(1);
                } else {
                    temp.push_back(0);
                }
            }
        }
        res.push_back(temp);
    }

    // Return the result
    return res;
}