#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price, int n)
{
    // Make a dp array of size n + 1
    // dp[i] stores the maximum profit that can be 
    // obtained by cutting a rod of length i
	vector<int> dp(n + 1, -1);
    // Base case, if length of rod is 0, then profit is 0
	dp[0] = 0;
    // For rod of length i
	for(int i=1; i<=n; i++) {
        // For each length, we can cut the rod in different ways
		for(int j = i - 1; j >= 0; j--) {
            // We can cut the rod of length i at j
            // So the profit will be dp[j] + price[i - j - 1]
            // Here i - j - 1 is the length of the remaining rod
            // We take the maximum of all such profits
			dp[i] = max(dp[i], dp[j] + price[i - j - 1]);
		}
	}
    // Return the maximum profit that can be obtained by cutting a rod of length n
	return dp[n];
}
