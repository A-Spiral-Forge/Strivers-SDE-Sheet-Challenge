#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &values, vector<int> &weights, int n, int w, int idx, vector<vector<int>> &dp) {
    // If we have reached the end of the array or the 
    // capacity of the knapsack is reached
	if(idx == n || w == 0) {
		return 0;
	}
    // If the value is already calculated
	if(dp[w][idx] != -1) {
        // Return the value
		return dp[w][idx];
	}
	int res = 0;
    // If the weight of the current item is less than or 
    // equal to the capacity of the knapsack
	if(weights[idx] <= w) {
        // We have the choice to include the current item
		res = max(res, solve(values, weights, n, w - weights[idx], idx + 1, dp) + values[idx]);
	}
    // We also have the choice to not include the current item
	res = max(res, solve(values, weights, n, w, idx + 1, dp));
    // Return the maximum value and store it in the dp array
	return dp[w][idx] = res;
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Create a dp array of size (w + 1) * n
	vector<vector<int>> dp(w + 1, vector<int>(n, -1));
    // Call the recursive function
	return solve(values, weights, n, w, 0, dp);
}