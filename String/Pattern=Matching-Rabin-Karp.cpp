#include <bits/stdc++.h>
using namespace std;

vector<int> stringMatch(string &str, string &pat) {
    // We use multiple as 26, because we have 26 characters in english alphabet
    // We use mod as 1e9 + 7, because it is a prime number
    long long patHash = 0, mod = 1e9 + 7;
    int n = str.size(), m = pat.size();
    // Calculate the hash of pattern
    for(char &ch: pat) {
        patHash = ((patHash * 26) % mod + (ch - 'A')) % mod;
    }

    // Calculate the hash of first m characters of string
    long long strHash = 0;
    for(int i=0; i<m; i++) {
        strHash = ((strHash * 26) % mod + (str[i] - 'A')) % mod;
    }

    // Calculate the hash of 26^(m-1) for later use
    long long hash = 1;
    for(int i=1; i<m; i++) {
        hash = (hash * 26) % mod;
    }

    vector<int> res;
    // If the hash of pattern and first m characters of string are 
    // equal, then we will push 0 as the first index of pattern
    if(patHash == strHash) {
        res.push_back(0);
    }
 
    for(int i=m; i<n; i++) {
        // We subtract the hash of first character of previous window
        // Here we use hash of 26^(m-1) to subtract the hash of first character
        strHash = (strHash - ((hash * (str[i - m] - 'A')) % mod) + mod) % mod;
        // We multiply the hash of previous window by 26
        // And add the hash of current character
        strHash = ((strHash * 26) % mod + (str[i] - 'A')) % mod;

        // If the hash of pattern and current window of string are
        // equal, then we will push the index of first character of current window
        if(strHash == patHash) {
            res.push_back(i - m + 1);
        }
    }

    // Return the vector of indices
    return res;
}
