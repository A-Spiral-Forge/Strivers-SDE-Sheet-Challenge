#include <bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Using BFS
    queue<pair<int, int>> q;

    // Push all initial rotten oranges in queue
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    int res = -1;
    // BFS
    while(!q.empty()) {
        int qs = q.size();
        // For all rotten oranges in queue
        while(qs--) {
            // Pop the front rotten orange
            pair<int, int> temp = q.front();
            int x = temp.first, y = temp.second;
            q.pop();
        
            // Push all adjacent fresh oranges
            if(x > 0 && grid[x - 1][y] == 1) {
                q.push({x - 1, y});
                grid[x - 1][y] = 2;
            }
            if(x + 1 < n && grid[x + 1][y] == 1) {
                q.push({x + 1, y});
                grid[x + 1][y] = 2;
            }
            if(y > 0 && grid[x][y - 1] == 1) {
                q.push({x, y - 1});
                grid[x][y - 1] = 2;
            }
            if(y + 1 < m && grid[x][y + 1] == 1) {
                q.push({x, y + 1});
                grid[x][y + 1] = 2;
            }
        }
        // Increment time
        res++;
    }

    // Check if any fresh orange is left
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            // If any fresh orange is left, return -1
            if(grid[i][j] == 1) {
                return -1;
            }
        }
    }

    // If time is -1, means no rotten orange was present return 0
    // Else return time
    return res == -1 ? 0 : res;
}