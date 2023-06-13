#include <bits/stdc++.h>
using namespace std;

/*
Two pointer approach is better than DP approach, as it takes O(1) space.
Both approaches take O(n^2) time. 
*/

string longestPalinSubstring(string &str)
{
    int n = str.size();
    // Initialize dp array
    // dp[i][j] = true if substring str[i...j] is palindrome
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Base case: All substrings of length 1 are palindrome
    for(int i=0; i<n; i++) {
        dp[i][i] = true;
    }
    
    string res = {str[0]};
    int sz = 1;
    
    // Check for substrings of length 2 and more
    for(int i=n-1; i>=0; i--) {
        // j = i+1 because we need to check for substrings of length 2
        for(int j=i+1; j<n; j++) {
            // If str[i] != str[j], then substring str[i...j] is not palindrome
            if(str[i] != str[j]) {
                continue;
            }

            // If str[i] == str[j] ans substring str[i...j] is palindrome
            // then check for substring str[i+1...j-1]
            if(j - i == 1 || dp[i + 1][j - 1]) {
                // If str[i+1...j-1] is palindrome, make dp value true
                dp[i][j] = true;

                // Update result if current substring is longer or 
                // having smaller index than current result, if both substrings
                // are of same length
                if(sz <= j - i + 1) {
                    res = str.substr(i, j - i + 1);
                    sz = j - i + 1;
                }
            }
        }
    }

    // Return result
    return res;
}