#include <bits/stdc++.h> 
using namespace std;

// This function will check if the given string is a palindrome or not
bool isPalindrome(string &s, int sz) {
    for(int i = 0; i < (sz / 2); i++) {
        // If the characters at the beginning and the end are not equal, 
        // the string is not a palindrome
        if(s[i] != s[sz - i - 1]) {
            return false;
        }
    }
    // If the string is a palindrome, return true
    return true;
}

void solve(string &s, int index, int n, vector<vector<string>> &res, vector<string> &temp) {
    // If we have reached the end of the string, we will add the current partition to the result
    if(index == n) {
        res.push_back(temp);
        return;
    }

    // We will try to partition the string from the current index
    string part = "";
    for(int i=index; i<n; i++) {
        // We will add the current character to the partition
        part += s[i];
        // If the current partition is a palindrome, we will add it to the current partition
        if(isPalindrome(part, i - index + 1)) {
            temp.push_back(part);
            // We will try to partition the remaining string
            solve(s, i + 1, n, res, temp);
            // We will backtrack and remove the current partition
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    int n = s.size();
    vector<vector<string>> res;
    vector<string> temp;

    // We will try to partition the string from the beginning
    solve(s, 0, n, res, temp);
    // Return the result
    return res;
}