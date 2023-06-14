#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Calculate the minimum word size
    int minWordSize = INT_MAX;
    for(int i=0; i<n; i++) {
        minWordSize = min(minWordSize, (int)arr[i].size());
    }

    string res = "";
    // Check for each character
    for(int i=0; i<minWordSize; i++) {
        int count = 0;
        char ch = arr[0][i];
        // Check for each word
        for(int j=0; j<n; j++) {
            // If character is same at the given index
            if(arr[j][i] == ch) {
                // Increment the count
                count++;
            }
        }
        // If count is less than n, then return the result
        if(count < n) {
            return res;
        }
        // Else append the character to the result
        res += ch;
    }
    // Return the result
    return res;
}
