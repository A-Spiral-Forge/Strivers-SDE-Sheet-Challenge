#include <bits/stdc++.h>
using namespace std;

// Compute the LPS array
void computeLpsArray(string &p, int m, vector<int> &lps) {
    // Length of the previous longest prefix suffix
    int len = 0, i = 1;
    // lps[0] is always 0
    while(i < m) {
        // If the characters match
        if(p[i] == p[len]) {
            // Increment the length
            len++;
            // Store the length
            lps[i] = len;
            // Increment the index
            i++;
        // If the characters don't m atch
        } else {
            // Check if the length is not 0
            if(len != 0) {
                // If the length is not 0
                // Update the length
                len = lps[len - 1];
            // If the length is 0
            } else {
                // Update the index
                i++;
            }
        }
    }
}

// Find the pattern in the string
bool findPattern(string p, string s)
{
    // Get the size of the strings
    int n = s.size(), m = p.size();

    // Compute the LPS array
    vector<int> lps(m, 0);
    computeLpsArray(p, m, lps);

    // Find the pattern
    int i = 0, j = 0;
    // Iterate over the string
    while((n - i) >= (m - j)) {
        // If the characters match
        if(s[i] == p[j]) {
            // Increment the index of the string and the pattern
            i++;
            j++;
        }

        // If the pattern is found
        if(j == m) {
            // Return true
            return true;
        }

        // If the characters don't match
        if(i < n && s[i] != p[j]) {
            // If the index of the pattern is not 0
            // Update the index of the pattern
            if(j != 0) {
                j = lps[j - 1];
            // Update the index of the string 
            } else {
                i++;
            }
        }
    }

    // If the pattern is not found
    // Return false
    return false;
}