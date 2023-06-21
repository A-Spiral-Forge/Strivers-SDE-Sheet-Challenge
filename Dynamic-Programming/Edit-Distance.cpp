#include <bits/stdc++.h>
using namespace std;

int solve(string &str1, string &str2, int i, int j, int n, int m, vector<vector<int>> &dp) {
    // If we have reached the end of any string, return the remaining length of the other string
    if(i == n || j == m) {
        return max(n - i, m - j);
    }
    // If the current state has already been calculated, return it
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    // Replace the current character and move forward
    int res = solve(str1, str2, i + 1, j + 1, n, m, dp) + 1;
    if(str1[i] == str2[j]) {
        // If the current characters are same, we don't need to do anything
        res = min(res, solve(str1, str2, i + 1, j + 1, n, m, dp));
    }
    // Delete the current character and move forward
    res = min(res, solve(str1, str2, i + 1, j, n, m, dp) + 1);
    // Insert at the current position and move forward
    res = min(res, solve(str1, str2, i, j + 1, n, m, dp) + 1);
    // Return the minimum of all the operations
    return dp[i][j] = res;
}

int editDistance(string &str1, string &str2)
{
    int n = str1.size(), m = str2.size();
    // dp[i][j] stores the minimum number of operations 
    // required to convert the substring str1[i..n-1] to str2[j..m-1]
    vector<vector<int>> dp(n, vector<int>(m, -1));
    // Call the recursive function
    return solve(str1, str2, 0, 0, n, m, dp);
}