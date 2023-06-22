#include <bits/stdc++.h> 
using namespace std;

// Return true if there is a subset of arr[] with sum equal to given sum
bool solve(vector<int> &arr, int idx, int n, int k, vector<vector<int>> &dp) {
    // If left sum is 0, then there is a subset
    if(k == 0) {
        return true;
    }
    // If there are no elements and left sum is negative, 
    // then there is no subset
    if(k < 0 || idx >= n) {
        return false;
    }
    // If we have already solved this subproblem, return 
    // the result from the dp table
    if(dp[k][idx] != -1) {
        return dp[k][idx];
    }

    // Take the current element into the subset and check 
    // if there is a subset with the remaining sum
    bool take = solve(arr, idx + 1, n, k - arr[idx], dp);
    // Don't take the current element into the subset and check
    // if there is a subset with the remaining sum
    bool notTake = solve(arr, idx + 1, n, k, dp);
    // Store the result in the dp table
    return dp[k][idx] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(k + 1, vector<int>(n, -1));
    // Call the recursive function
    return solve(arr, 0, n, k, dp);
}