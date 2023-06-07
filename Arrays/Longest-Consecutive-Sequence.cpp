#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Store the length of longest consecutive sequence
    int len = 0, res = 0, prev = arr[0] - 1;

    // Iterate over the array
    for(int i=0; i<n; i++) {
        // If the current element just after the previous element
        if(arr[i] - prev == 1) {
            // Increment the length
            len++;
        // If the current element is not just after the previous element
        } else if(arr[i] - prev > 1) {
            // Reset the length
            len = 1;
        }
        // Update the previous element
        prev = arr[i];
        // Update the result
        res = max(len, res);
    }

    // Return the result
    return res;
}