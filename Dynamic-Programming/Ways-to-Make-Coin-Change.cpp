#include <bits/stdc++.h>
using namespace std;

long solve(int *denominations, int idx, int n, int value, vector<vector<long>> &dp) {
    // If value is 0, then there is only one way to make change
    if(value == 0) {
        return 1;
    }
    // If value is less than 0 or idx is greater than n, then there is no way to make change
    if(value < 0 || idx >= n) {
        return 0;
    }
    // If ways to make change for value and idx is already calculated, then return it
    if(dp[value][idx] != -1) {
        return dp[value][idx];
    }
    long res = 0;
    // If value is greater than 0 and idx is less than n, then we have two choices
    // 1. Include the current denomination, and stay on the same denomination
    res += solve(denominations, idx, n, value - denominations[idx], dp);
    // 2. Exclude the current denomination, and move to the next denomination
    res += solve(denominations, idx + 1, n, value, dp);
    // Return the total number of ways to make change for value and idx
    return dp[value][idx] = res;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Sort the denominations array, to avoid duplicate ways
    sort(denominations, denominations + n);
    // Create a dp array to store the number of ways to make change for value and idx
    vector<vector<long>> dp(value + 1, vector<long>(n, -1));
    // Return the total number of ways to make change for value and 0
    return solve(denominations, 0, n, value, dp);
}