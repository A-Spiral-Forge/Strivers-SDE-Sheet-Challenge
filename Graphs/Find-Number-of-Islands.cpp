#include <bits/stdc++.h>
using namespace std;

// Check if the given coordinates are valid or not
bool check(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

// Function to find the number of islands.
int getTotalIslands(int** arr, int n, int m)
{
    // Store the number of islands
    int res = 0;
    // Iterate over the matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // If the current cell is 0, then continue
            if(arr[i][j] == 0) {
                continue;
            }

            // Else, we have found a new island
            res++;
            // Perform BFS to find all the connected land
            queue<pair<int, int>> q;
            // Push the current cell
            q.push({i, j});
            // Mark the current cell as visited
            arr[i][j] = 0;
            // Iterate until the queue is empty
            while(!q.empty()) {
                // Get the front element
                pair<int, int> temp = q.front();
                // Pop the front element
                q.pop();
                // Iterate over all the adjacent cells (8 directions)
                for(int dx = -1; dx <= 1; dx++) {
                    for(int dy = -1; dy <= 1; dy++) {
                        // Get the coordinates of the adjacent cell
                        int new_x = temp.first + dx;
                        int new_y = temp.second + dy;
                        // If the current cell is valid and is a land, then push it into the queue
                        if(check(new_x, new_y, n, m) && arr[new_x][new_y] == 1) {
                            q.push({new_x, new_y});
                            // Mark the current cell as visited
                            arr[new_x][new_y] = 0;
                        }
                    }
                }
            }
        }
    }
    // Return the number of islands
    return res;
}
