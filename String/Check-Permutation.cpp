#include <bits/stdc++.h> 
using namespace std;

bool areAnagram(string &str1, string &str2){
    vector<int> count(26, 0);
    int len = 0;
    // Iterate over the first string
    for(char &ch: str1) {
        // Increment the count of the character
        count[ch - 'a']++;
        // Increment the length
        len++;
    }

    // Iterate over the second string
    for(char &ch: str2) {
        // If the character is not present in the first string
        if(count[ch - 'a'] == 0) {
            // Return false
            return false;
        }
        // Decrement the count of the character
        count[ch - 'a']--;
        // Decrement the length
        len--;
    }

    // Return true if the length is 0
    return len == 0;
}