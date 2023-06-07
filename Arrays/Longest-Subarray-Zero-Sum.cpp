#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {
    // Map to store the prefix sum and the index of the first occurence of that prefix sum
    map<int, int> prefixSumWithIndex;
    // Insert the first element of the prefix sum as 0 with index -1
    prefixSumWithIndex[0] = -1;
    int n = arr.size();
    
    int sum = 0, res = 0;
    // Iterate over the array
    for(int i=0; i<n; i++) {
        // Calculate the prefix sum
        sum += arr[i];
        // If the prefix sum is already present in the map
        if(prefixSumWithIndex.find(sum) != prefixSumWithIndex.end()) {
            // Update the result difference of with minimum index of current prefix sum and current index
            res = max(res, i - prefixSumWithIndex[sum]);
        }
        // If the prefix sum is not present in the map
        if(prefixSumWithIndex.find(sum) == prefixSumWithIndex.end()) {
            // Insert the prefix sum with its index
            prefixSumWithIndex[sum] = i;
        }
    }

    // Return the result
    return res;
}