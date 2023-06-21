#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    // Stores the length of longest increasing subsequence
    int ans = 1;
    // Stores the longest increasing subsequence
    vector<int> lis;
    // Push the first element in the vector
    lis.push_back(arr[0]);
    // Iterate over the array
    for(int i=1; i<n; i++) {
        // If the current element is greater than the last element of lis
        if(arr[i] > lis.back()) {
            // Push the current element in the vector
            lis.push_back(arr[i]);
            // Increment the length of lis
            ans++;
        } else {
            // Find the index of the first element in lis which is greater than or equal to arr[i]
            int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            // Replace the element at index with arr[i]
            lis[index] = arr[i];
        }
    }
    // Return the length of lis
    return ans;
}
