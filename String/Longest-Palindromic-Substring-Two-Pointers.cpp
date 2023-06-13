#include <bits/stdc++.h>
using namespace std;

string longestPalinSubstring(string &str)
{
    int n = str.size();
    // start and end are the starting and ending index of the longest palindromic substring
    int start = 0, end = 0;

    // for each index i, we will check for the longest 
    // palindromic substring with i as the center and has odd length
    for(int i=0; i<n; i++) {
        // Using two pointer approach
        int left = i, right = i;
        while(left >= 0 && right < n && str[left] == str[right]) {
            // if the length of the current palindromic substring is greater 
            // than the previous one then update the start and end index
            if(right - left > end - start) {
                start = left;
                end = right;
            }
            left--;
            right++;
        }
    }

    // for each index i, we will check for the longest
    // palindromic substring with i and i + 1 as the center and has even length
    for(int i=0; i<n - 1; i++) {
        // Using two pointer approach
        int left = i, right = i + 1;
        while(left >= 0 && right < n && str[left] == str[right]) {
            // if the length of the current palindromic substring is greater
            // than the previous one then update the start and end index
            if(right - left > end - start) {
                start = left;
                end = right;
            }
            left--;
            right++;
        }
    }

    string res ="";
    // Traverse from start to end and append the characters to the result
    for(int i=start; i<=end; i++) {
        res += str[i];
    }
    // return the longest palindromic substring
    return res;
}