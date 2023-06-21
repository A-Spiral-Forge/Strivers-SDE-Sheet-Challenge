#include<bits/stdc++.h>
using namespace std;

// Helper function to find the length of longest common subsequence
int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp, int n, int m) {
	// If we reach the end of any string, return 0
    if(i == n || j == m) {
		return 0;
	}
    // If the state has already been visited
	if(dp[i][j] != -1) {
        // Return the value of the state
		return dp[i][j];
	}
    // If the characters match
	if(s[i] == t[j]) {
        // Recursively call for the next characters, and add 1 to the answer
		int ans = solve(s, t, i + 1, j + 1, dp, n, m) + 1;
        // Store the answer in the dp table
		return dp[i][j] = ans;
	}
    // If the characters don't match, recursively call for the next characters
    // and store the maximum of the two answers
	int a = solve(s, t, i + 1, j, dp, n, m);
	int b = solve(s, t, i, j + 1, dp, n, m);
	return dp[i][j] = max(a, b);
}

int lcs(string s, string t)
{
	int n = s.size(), m = t.size();
    // Create a dp table of size n x m, and initialize it with -1
	vector<vector<int>> dp(n, vector<int>(m, -1));
    // Call the helper function
	return solve(s, t, 0, 0, dp, n, m);
}