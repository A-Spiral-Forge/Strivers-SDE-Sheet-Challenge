#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
    // Sort the array
    sort(arr.begin(), arr.end());
    int n = arr.size();
    
    // Store the count of each element in the array
    map<int, int> count;
    // Store the result
    vector<vector<int>> res;

    // Iterate over the array
    for(auto &it: arr) {
        // If the count of s - it is greater than 0
        int temp = count[s - it];
        for(int i=0; i<temp; i++) {
            // Add the pair to the result
            res.push_back({min(it, s - it), max(it, s - it)});
        }
        // Increment the count of current element
        count[it]++;
    }

    // Sort the result
    sort(res.begin(), res.end());

    return res;
}