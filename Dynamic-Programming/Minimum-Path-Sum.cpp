#include <bits/stdc++.h> 
using namespace std;
int minSumPath(vector<vector<int>> &grid) {
    // Calculate grid size
    int n = grid.size();
    int m = grid[0].size();
    // Calculate first row and first column
    // which is just like prefix sum
    for(int i=1; i<n; i++) {
        grid[i][0] += grid[i - 1][0];
    }
    for(int j=1; j<m; j++) {
        grid[0][j] += grid[0][j - 1];
    }
    // Calculate the minimum path sum
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            // Minimum path sum is the minimum of the
            // previous row and previous column
            // plus the current cell
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    // Return the minimum path sum
    return grid[n - 1][m - 1];
}