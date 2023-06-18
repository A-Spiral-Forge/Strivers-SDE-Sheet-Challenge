#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Get the dimensions of the image
    int n = image.size();
    int m = image[0].size();
    // Get the old color of the pixel
    int oldColor = image[x][y];
    // If the old color and the new color are the same, return the image
    if(oldColor == newColor) {
        return image;
    }

    // Perform BFS
    queue<pair<int, int>> q;
    // Push the starting pixel
    q.push({x, y});
    // Change the color of the starting pixel
    image[x][y] = newColor;

    // While the queue is not empty
    while(!q.empty()) {
        // Get the front element
        pair<int, int> temp = q.front();
        // Remove the front element
        q.pop();
        
        // Check if the adjacent pixels have the same color as the old color
        // If yes, change the color and push them into the queue
        if(temp.first > 0 && image[temp.first - 1][temp.second] == oldColor) {
            image[temp.first - 1][temp.second] = newColor;
            q.push({temp.first - 1, temp.second});
        }
        if(temp.second > 0 && image[temp.first][temp.second - 1] == oldColor) {
            image[temp.first][temp.second - 1] = newColor;
            q.push({temp.first, temp.second - 1});
        }
        if(temp.first < n - 1 && image[temp.first + 1][temp.second] == oldColor) {
            image[temp.first + 1][temp.second] = newColor;
            q.push({temp.first + 1, temp.second});
        }
        if(temp.second < m - 1 && image[temp.first][temp.second + 1] == oldColor) {
            image[temp.first][temp.second + 1] = newColor;
            q.push({temp.first, temp.second + 1});
        }
    }

    // Return the image
    return image;
}