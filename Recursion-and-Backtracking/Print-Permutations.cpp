#include <bits/stdc++.h> 
using namespace std;

void solve(string &s, int index, int n, vector<string> &res) {
    // If we have reached the end of the string, we will add the string to the result
    if(index == n) {
        res.push_back(s);
        return;
    }

    // We will swap the current character with all the characters after it (including itself)
    for(int i=index; i<n; i++) {
        swap(s[i], s[index]);
        // We will recursively call the function for the remaining string
        solve(s, index + 1, n, res);
        swap(s[i], s[index]);
    }
}

vector<string> findPermutations(string &s) {
    int n = s.size();
    vector<string> res;
    // We will call the recursive function to find all the permutations of the string
    solve(s, 0, n, res);
    // Return the result
    return res;
}