#include <bits/stdc++.h>
using namespace std;

int cutLogs(int k, int n)
{
    // dp[i][j] = logs cut using i axes in j moves
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    // Stores min number of moves to cut j logs using i axes
    int res = 0;
    // While number of logs cut is less than n
    while(dp[k][res] < n) {
        // Increase number of moves
        res++;
        // For each axe
        for(int i=1; i<=k; i++) {
            // Number of logs cut using i axes in res moves
            // = 1 + number of logs cut using i axes in res - 1 moves (axe not broken)
            // + number of logs cut using i - 1 axes in res - 1 moves (axe broken)
            dp[i][res] = 1 + dp[i - 1][res - 1] + dp[i][res - 1];
        }
    }
    // Return number of moves
    return res;
}
