#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    // Kadane's Algorithm
    long long res = 0, currmax = 0;

    // Iterate over the array
    for(int i=0; i<n; i++) {
        // Update the current sum
        currmax += arr[i];
        // Update the maximum sum
        res = max(currmax, res);
        // If the current maximum sum is negative, make it 0
        currmax = max(currmax, 0LL);
    }

    return res;
}