#include <bits/stdc++.h>
using namespace std;

// Function to find all possible word breaks
void solve(set<string> &dict, string &s, vector<string> &res, vector<string> &temp, int index, int n) {
    // If we reach end of string, add the sentence to result
    if(index == n) {
        string ans = "";
        // Add all the words in temp to ans
        for(string &str: temp) {
            ans += str;
            ans += ' ';
        }
        // Remove the last space
        ans.pop_back();
        // Add the sentence to result
        res.push_back(ans);
        return;
    }

    string str = "";
    // Make all possible substrings starting from index
    for(int i = index; i<n; i++) {
        str += s[i];
        // If the substring is not present in dictionary, ignore it
        if(dict.find(str) == dict.end()) {
            continue;
        }

        // If the substring is present in dictionary, add it to temp and recurse for remaining string
        temp.push_back(str);
        solve(dict, s, res, temp, i + 1, n);
        // Remove the last word from temp and backtrack
        temp.pop_back();
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Make a set of all words in dictionary
    set<string> dict(dictionary.begin(), dictionary.end());

    vector<string> res;
    vector<string> temp;
    int n = s.size();

    // Call the recursive function
    solve(dict, s, res, temp, 0, n);
    // Return the result
    return res;
}