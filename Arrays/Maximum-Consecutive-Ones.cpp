#include <bits/stdc++.h>
using namespace std;

int longestSubSeg(vector<int> &arr , int n, int k){
    int res = 0;
    int flipped = 0, start = 0;

    // Variable Sliding window
    for(int i=0; i<n; i++) {
        // If the current element is 0, then increment the flipped count
        if(arr[i] == 0) {
            flipped++;
        }

        // If the flipped count is greater than k, then we need to move the start pointer
        while(flipped > k) {
            // If the start element is 0, then decrement the flipped count
            if(arr[start] == 0) {
                flipped--;
            }
            // Move the start pointer
            start++;
        }

        // Update the result
        res = max(res, i - start + 1);
    }

    // Return the result
    return res;
}
