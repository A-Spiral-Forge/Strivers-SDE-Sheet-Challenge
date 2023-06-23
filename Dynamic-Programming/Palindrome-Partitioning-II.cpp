#include <bits/stdc++.h> 
using namespace std;

// Check if a string is palindrome between start and end index
bool isPalindrome(string &s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++; end--;
    }
    return true;
} 

// Recursive solution
int solve(string &str, int idx, int n, vector<int> &dp) {
    // If we have reached the end of the string
    if(idx == n) {
        // Return 0 as no partition is required
        return 0;
    }
    // If we have already calculated the answer for this index
    if(dp[idx] != -1) {
        // Return the answer
        return dp[idx];
    }
    // Initialize the answer to the maximum value
    int res = n;
    // For all the indices from idx to n - 1
    for(int j = idx; j < n; j++) {
        // If the string from idx to j is a palindrome
        if(isPalindrome(str, idx, j)) {
            // Update the answer by taking the minimum of the current
            // answer and 1 + answer for the remaining string
            res = min(res, solve(str, j + 1, n, dp) + 1);
        }
    }
    // Return the answer
    return dp[idx] = res;
}

int palindromePartitioning(string str) {
    int n = str.size();
    // Initialize the dp array with -1
    vector<int> dp(n + 1, -1);
    // Return the number of partitions - 1
    return solve(str, 0, n, dp) - 1;
}
