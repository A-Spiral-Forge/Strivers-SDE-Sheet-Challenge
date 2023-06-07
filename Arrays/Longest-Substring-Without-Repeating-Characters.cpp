#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string input)
{
    // Store the count of each character in the string
    vector<int> count(26, 0);
    int n = input.size(), start = 0;
    int res = 0;

    // Iterate over the string
    for(int i=0; i<n; i++) {
        // Get the index for the current character
        int index = input[i] - 'a';
        // If the count of current character is 1
        if(count[index] == 1) {
            // Increment start until the count of current character is 0
            while(start < i && count[index] > 0) {
                // Decrement the count of character at start pointer
                count[input[start] - 'a']--;
                // Increment start pointer
                start++;
            }
        }
        // Increment the count of current character
        count[index]++;
        // Update the result
        res = max(res, i - start + 1);
    }

    // Return the result
    return res;
}