#include <bits/stdc++.h> 
using namespace std;

int uniquePaths(int m, int n) {
    // Create a 2D array to store the count of paths to reach
	vector<vector<int>> dp(n, vector<int>(m, 0));

    // There is only one way to reach any cell in the first row
	for(int i=0; i<n; i++) {
		dp[i][0] = 1;
	}
    
    // There is only one way to reach any cell in the first column
	for(int j=0; j<m; j++) {
		dp[0][j] = 1;
	}

    // For any other cell, the number of paths to reach it is equal to the
    // number of paths to reach the cell above it plus the number of paths
    // to reach the cell to the left of it
	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) {
			dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]);
		}
	}

    // Return the number of paths to reach the bottom right cell
	return dp[n - 1][m - 1];
}