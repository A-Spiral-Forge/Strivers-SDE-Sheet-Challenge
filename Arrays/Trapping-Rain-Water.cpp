#include <bits/stdc++.h> 
using namespace std;

long getTrappedWater(long *arr, int n){
    // Make two array to store the maximum element on the left and right of the current element
    vector<long> left(n, 0), right(n, 0);

    // Store the maximum element on the left of the current element
    for(int i=1; i<n; i++) {
        left[i] = max(arr[i - 1], left[i - 1]);
    }

    // Store the maximum element on the right of the current element
    for(int i=n-1; i>0; i--) {
        right[i - 1] = max(arr[i], right[i]);
    }

    // Calculate the amount of water trapped
    long res = 0;
    for(int i=0; i<n; i++) {
        // The amount of water trapped at the current element is equal to the minimum of the maximum element on the left and right of the current element minus the height of the current element
        long level = min(left[i], right[i]);
        res += max(0L, level - arr[i]);
    }

    // Return the amount of water trapped
    return res;
}