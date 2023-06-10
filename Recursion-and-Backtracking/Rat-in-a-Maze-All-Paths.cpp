#include <bits/stdc++.h> 
using namespace std;

// Function to find the paths for rat to reach destination
void solve(vector<vector<int>> &maze, int i, int j, int n,  vector<vector<int>> &res, vector<int> &visited) {
    // Calculate index for 1D array
    int idx = (i * n) + j; 

    // Check if rat is out of maze or at a blocked cell or already visited cell
    if(i >= n || j >= n || i < 0 || j < 0 || maze[i][j] == 0 || visited[idx] == 1) {
        return;
    }

    // If rat reaches destination, add the path to result
    if(i == n-1 && j == n-1) {
        visited[idx] = 1;
        res.push_back(visited);
        visited[idx] = 0;
        return;
    }

    // Mark current cell as visited and move to next cells
    visited[idx] = 1;
    // Move down, right, up, left
    solve(maze, i + 1, j, n, res, visited);
    solve(maze, i, j + 1, n, res, visited);
    solve(maze, i - 1, j, n, res, visited);
    solve(maze, i, j - 1, n, res, visited);
    // Mark current cell as unvisited for backtracking
    visited[idx] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> res;
    vector<int> visited(n * n, 0);

    // Call function to find paths
    solve(maze, 0, 0, n, res, visited);
    // Return result
    return res;
}