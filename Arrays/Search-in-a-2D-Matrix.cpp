#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N + M)
// Space Complexity: O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    // Start from the top right corner
    int i= 0, j = m - 1;

    while(i < n && j >= 0) {
        // If the current element is equal to the target, return true
        if(mat[i][j] == target) {
            return true;
        }
        // If the current element is less than the target, move down
        if(mat[i][j] < target) {
            i++;
        // If the current element is greater than the target, move left
        } else {
            j--;
        }
    }

    // If the element is not found, return false
    return false;
}