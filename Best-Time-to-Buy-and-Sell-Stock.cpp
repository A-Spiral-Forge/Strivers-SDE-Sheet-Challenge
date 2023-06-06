#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    int res = 0, minTillNow = prices[0];

    // Iterate over the prices
    for(auto &it: prices) {
        // Update the minimum price till now
        minTillNow = min(minTillNow, it);
        // Update the maximum profit
        res = max(res, it - minTillNow);
    }

    return res;
}