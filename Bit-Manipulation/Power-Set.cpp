#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> pwset(vector<int>v)
{
    sort(v.begin(), v.end());
    int n = v.size();
    // Number of subsets is 2^n
    int m = pow(2, n);

    // Run a loop for making all the subsets
    vector<vector<int>> res;
    for(int i = 0; i < m; i++) {
        // For every number check if its bit is set or not
        vector<int> subset;
        for(int j = 0; j < n; j++) {
            // If the bit is set, add the number to the subset
            if(i & (1 << j)) {
                subset.push_back(v[j]);
            }
        }
        // Add the subset to the result
        res.push_back(subset);
    }
    // Return the result
    return res;
}