#include <bits/stdc++.h>
using namespace std;

bool isCommonPrefix(vector<string> &arr, int n, int len)
{
    // Get the prefix
    string prefix = arr[0].substr(0, len);
    // Check for each word
    for(int i=1; i<n; i++) {
        // If prefix is not present at the beginning of the word
        if(arr[i].find(prefix) != 0) {
            // Return false
            return false;
        }
    }
    // Return true
    return true;
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Find longest common prefix using binary search
    int low = 0, high = INT_MAX;
    while(low <= high) {
        // Find the mid
        int mid = low + (high - low) / 2;
        // If all the strings are of size greater than mid
        if(isCommonPrefix(arr, n, mid)) {
            // Update the low
            low = mid + 1;
        }
        // Else update the high
        else {
            high = mid - 1;
        }
    }

    // Return the result
    return arr[0].substr(0, (low + high) / 2);
}
