#include <bits/stdc++.h> 
using namespace std;

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // dp[i] = max sum of increasing subsequence ending at i
    // Intialize dp[i] = rack[i] as each element is a subsequence
	vector<int> dp = rack;
    // Store the maximum sum of increasing subsequence
    int res = 0;
    // Iterate over all elements
    for(int i = 0; i < n; i++) {
        // Update the maximum sum of increasing subsequence with the current element
        res = max(res, dp[i]);
        // Iterate over all elements after the current element
        for(int j = i + 1; j < n; j++) {
            // If the current element is greater than the previous element
            if(rack[i] < rack[j]) {
                // Update the maximum sum of increasing subsequence till the current element
                dp[j] = max(dp[j], dp[i] + rack[j]);
            }
            // Update the maximum sum of increasing subsequence
            res = max(res, dp[j]);
        }
    }
    // Return the maximum sum of increasing subsequence
    return res;
}