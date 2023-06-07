#include <bits/stdc++.h>
using namespace std;

string fourSum(vector<int> arr, int target, int n) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Iterate over the array
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            // Fix two elements i and j
            int remaining = target - arr[i] - arr[j];
            // Apply two pointer approach on the remaining array
            int left = j + 1, right = n - 1;
            
            // Find the remaining two elements
            while(left < right) {
                // If the sum of two elements is equal to remaining
                if(arr[left] + arr[right] == remaining) {
                    // Return "Yes"
                    return "Yes";
                }

                // If the sum of two elements is greater than remaining
                if(arr[left] + arr[right] > remaining) {
                    // Decrement right
                    right--;
                // If the sum of two elements is less than remaining
                } else {
                    // Increment left
                    left++;
                }
            }
        }
    }

    // If no such quadruplet is found, return "No"
    return "No";
}
