#include <bits/stdc++.h> 
using namespace std;

// Function to find the most efficient way to multiply
int solve(vector<int> &arr, int start, int end, vector<vector<int>> &dp) {
    // If there is only one matrix
    // then cost will be zero
    if(start + 2 > end) {
        return 0;
    }
    // If there are only two matrices
    if(start + 2 == end) {
        // Cost is number of multiplications
        return arr[start] * arr[start + 1] * arr[end];
    }
    // If already calculated
    if(dp[start][end] != -1) {
        // Return the value
        return dp[start][end];
    }

    int res = INT_MAX;
    // Try every possible combination
    for(int i = start + 1; i < end; i++) {
        // Cost of multiplying the two matrices
        // which are obtained after partitioning
        int temp = arr[start] * arr[i] * arr[end];
        // Add the cost of multiplying the left part
        temp += solve(arr, start, i, dp);
        // Add the cost of multiplying the right part
        temp += solve(arr, i, end, dp);
        // Update the minimum value
        res = min(res, temp);
    }
    // Return the minimum value
    return dp[start][end] = res;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Create a dp array
    // dp[i][j] stores the minimum cost of
    // multiplying the matrices from i to j
    vector<vector<int>> dp(N, vector<int>(N, -1));
    // Return the minimum cost
    return solve(arr, 0, N - 1, dp);
}